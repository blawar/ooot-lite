#define WIN32_LEAN_AND_MEAN
#define DISABLE_AUDIO
#define USE_GLIDEN64
#include "window.h"

static std::unique_ptr<platform::window::Base> gWindow;

extern "C" {
#include "global.h"
#include "ultra64/vi.h"
//#include "scheduler.h"
#include "gfx.h"
#include "def/graph.h"
	extern OSViMode osViModeNtscLan1;
	u64 frameRateDivisor();
	bool isRunning();
}

/*struct OSViMode
{
	u8 type;
	OSViCommonRegs comRegs;
	OSViFieldRegs fldRegs[2];
}; // size = 0x4C

/*static OSViMode osViMode = {
	2, // type
	{
		// comRegs
		0x311E,       // ctrl
		SCREEN_WIDTH, // width
		0x3E52239,    // burst
		0x20D,        // vSync
		0xC15,        // hSync
		0xC150C15,    // leap
		0x6C02EC,     // hStart
		0x200,        // xScale
		0,            // vCurrent
	},
	{ // fldRegs
	  {
			// [0]
			0x280,    // origin
			0x400,    // yScale
			0x2501FF, // vStart
			0xE0204,  // vBurst
			2,        // vIntr
		},
		{
			// [1]
			0x280,    // origin
			0x400,    // yScale
			0x2501FF, // vStart
			0xE0204,  // vBurst
			2,        // vIntr
		} },
};*/

#include <stdlib.h>
//#include "gfx/fast64.h"

//#include "gfx/renderer.h"

#include "configfile.h"
#include "debug.h"

//#include <cstdio>
#include <filesystem>

#include "nx.h"
#include "audio/audio_api.h"
//#include "ultra64/sptask.h"
#include "xxhash64.h"
#ifdef USE_F3D
extern "C" {
#include "n64-fast3d-engine/gfx_pc.h"
#include "n64-fast3d-engine/gfx_opengl.h"
#include "n64-fast3d-engine/gfx_sdl.h"
}
#elif defined(USE_GLIDEN64)
extern "C" {
void gfx_init(const char* romName, OSViMode* viMode);
void gfx_shutdown();
bool gfx_start_frame();
void gfx_end_frame();
void gfx_run(OSTask_t* task, u32 sz);
void gfx_fbe_enable(int enable);
}
#endif

#if defined(USE_CF3D)
#include "gfx/fast64.h"
#elif defined(USE_RDPP)
extern "C" {

#include "core/n64video.h"
#include "output/screen.h"
#include "output/vdac.h"

#define MSG_BUFFER_LEN 256

void msg_error(const char* err, ...) {
    va_list arg;
    va_start(arg, err);
    char buf[MSG_BUFFER_LEN];
    vsprintf(buf, err, arg);

    va_end(arg);
    exit(0);
}

void msg_warning(const char* err, ...) {
    va_list arg;
    va_start(arg, err);
    char buf[MSG_BUFFER_LEN];
    vsprintf(buf, err, arg);

    va_end(arg);
}

void msg_debug(const char* err, ...) {
    va_list arg;
    va_start(arg, err);
    char buf[MSG_BUFFER_LEN];
    vsprintf(buf, err, arg);

    va_end(arg);
}

}
#endif
//GfxDimensions gfx_current_dimensions;

OSMesg D_80339BEC;
OSMesgQueue gSIEventMesgQueue;

s8 gResetTimer;
s8 D_8032C648;

#ifndef DISABLE_AUDIO
extern AudioAPI audio_sdl;
AudioAPI* audio_api = nullptr;

#ifdef ENABLE_SDL_AUDIO
#else
AudioAPI audio_sdl;
#endif
#endif

#ifdef USE_CF3D
sm64::gfx::Fast64* g_fast64 = nullptr;
#endif

extern "C" {
void send_display_list(Gfx* gfx);
}
void game_loop_one_iteration(void);
void dispatch_audio_sptask(struct SPTask* spTask);

extern void game_init(void* arg);

void dispatch_audio_sptask(struct SPTask* spTask)
{
}

static uint8_t inited = 0;

void send_display_list(Gfx* gfx) {
	if(!inited)
	{
		return;
	}
#ifdef USE_F3D
    gfx_start_frame();
    gfx_run(gfx);
    gfx_end_frame();
#endif
	//g_fast64->run(gfx);
}

#define printf

static void save_config(void)
{
}


bool verifyIntegrity()
{
    return true; // TODO FIX
#if 0
	const static u64 ROM_SIZE = 0x800000;
	bool hasRom = false, hasPak = false;
	auto buffer = malloc(ROM_SIZE);

	if(!buffer)
	{
		return false;
	}

	for(const auto& entry : std::filesystem::directory_iterator("."))
	{
		if(entry.is_regular_file())
		{
			if(!hasRom && entry.path().extension() == ".z64" && entry.file_size() == ROM_SIZE)
			{
                FILE* f = nullptr;

				if (fopen_s(&f, entry.path().string().c_str(), "rb") == 0)
				{
					fread(buffer, 1, ROM_SIZE, f);
					fclose(f);

					if(XXHash64::hash(buffer, ROM_SIZE, 0) == 0xdaf4de8a170fdcbb)
					{
						hasRom = true;
						break;
					}
				}
			}
		}
	}

	for(const auto& entry : std::filesystem::directory_iterator("romfs"))
	{
		if(entry.is_regular_file())
		{
			if(entry.path().filename().string() == "!!base.pak")
			{
				hasPak = true;
				break;
			}
		}
	}

	if(!hasRom)
	{
		sm64::log("error: unable to locate Z64 rom.\n");
	}

	if(!hasPak)
	{
		sm64::log("error: unable to locate romfs/!!base.pak\n");
	}

	free(buffer);
	return hasRom && hasPak;
#endif
}

extern "C" {
	void main_func(void);
	void hid_init();
	void hid_update();
}

void main_func(void)
{
	sm64::log("initializing app\n");

#ifndef BUILD_NSO
	if(!verifyIntegrity())
	{
		return;
	}
#endif

	//static u64 pool[0x165000 / 8 / 4 * sizeof(void*)];
	//main_pool_init(pool, pool + sizeof(pool) / sizeof(pool[0]));
	//gEffectsMemoryPool = mem_pool_init(0x4000, MEMORY_POOL_LEFT);

#ifdef USE_CF3D
	g_fast64 = sm64::gfx::Fast64::createContext();
#endif

#ifndef DISABLE_AUDIO
	audio_api = &audio_sdl;
	if(!audio_api->init())
	{
		return;
	}
#endif

	//audio_init();
	//interface_init();

	gWindow = platform::window::create("The Legend of Zelda - Ocarina of Time", false);

#ifdef USE_F3D
	gfx_init(&gfx_sdl, &gfx_opengl_api, "Zelda OOT PC-Port", 0);
#elif defined(USE_RDPP)
    n64video_config config;
    n64video_config_init(&config);
    n64video_init(&config);

	screen_init(&config);
#elif defined(USE_GLIDEN64)
	gfx_init("THE LEGEND OF ZELDA", &osViModeNtscLan1);
	gfx_fbe_enable(1);
#endif
	gWindow->resize(-1, -1);
	hid_init();

	game_init(NULL);

	inited = 1;

	Graph_ThreadEntry(0);
}

void game_loop_one_iteration() {
    Graph_ThreadEntry(0);
}

void process_physics() {
}

void game_init(void* arg) {
}

#if(defined(_WIN32) || defined(_WIN64)) && defined(_MSC_VER)
#include <windows.h>
#include <shellscalingapi.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{
	SetProcessDpiAwareness(PROCESS_SYSTEM_DPI_AWARE);
	main_func();
	return 0;
}
#endif

#ifdef __SWITCH__
int main(int argc, char* argv[])
{

	initialize();
	main_func();
	return 0;
}
#endif

void create_next_audio_buffer(s16* samples, u32 num_samples) {
}

static bool g_isRunning = true;

extern "C" {
	bool gfx_start_frame()
	{
		if(gWindow)
		{
			return gWindow->begin_frame();
		}
		return false;
	}

	void gfx_end_frame()
	{
		if(gWindow)
		{
			gWindow->setTargetFrameRate(60 / frameRateDivisor());
			gWindow->end_frame();
		}
	}

	void set_fullscreen(bool value)
	{
		gWindow->set_fullscreen(value, false);
	}

	bool isRunning()
	{
		return g_isRunning;
	}

	void quit()
	{
		g_isRunning = false;
	}
}

