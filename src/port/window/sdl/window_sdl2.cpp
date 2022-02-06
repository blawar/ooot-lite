#define GL_GLEXT_PROTOTYPES 1

#if defined(__MINGW32__) || defined(USE_SDL2_INCLUDE_PATH_SHORT)
	#include <SDL.h>
	#include <SDL_opengl.h>
	#ifdef _WIN32
		#include <GL/glew.h>
		/* #include <SDL2/SDL_opengl.h> */
	#endif
#else
	#include <SDL2/SDL.h>
	#include <SDL2/SDL_opengles2.h>
#endif
#include "port/window.h"
#include "ultra64/types.h"
#include <stdio.h>
#include <chrono>
#include <memory>

extern "C"
{
	void quit();
}
void WindowsWGL_GrabWindow(void *wnd);

namespace platform::window
{
#define GFX_API_NAME "SDL2 - OpenGL"
#define DESIRED_SCREEN_WIDTH 1920
#define DESIRED_SCREEN_HEIGHT 1080

	static const SDL_Scancode windows_scancode_table[] = {
			/*	0						1							2							3							4						5							6							7
			 */
			/*	8						9							A							B							C						D							E							F
			 */
			SDL_SCANCODE_UNKNOWN,
			SDL_SCANCODE_ESCAPE,
			SDL_SCANCODE_1,
			SDL_SCANCODE_2,
			SDL_SCANCODE_3,
			SDL_SCANCODE_4,
			SDL_SCANCODE_5,
			SDL_SCANCODE_6, /* 0 */
			SDL_SCANCODE_7,
			SDL_SCANCODE_8,
			SDL_SCANCODE_9,
			SDL_SCANCODE_0,
			SDL_SCANCODE_MINUS,
			SDL_SCANCODE_EQUALS,
			SDL_SCANCODE_BACKSPACE,
			SDL_SCANCODE_TAB, /* 0 */

			SDL_SCANCODE_Q,
			SDL_SCANCODE_W,
			SDL_SCANCODE_E,
			SDL_SCANCODE_R,
			SDL_SCANCODE_T,
			SDL_SCANCODE_Y,
			SDL_SCANCODE_U,
			SDL_SCANCODE_I, /* 1 */
			SDL_SCANCODE_O,
			SDL_SCANCODE_P,
			SDL_SCANCODE_LEFTBRACKET,
			SDL_SCANCODE_RIGHTBRACKET,
			SDL_SCANCODE_RETURN,
			SDL_SCANCODE_LCTRL,
			SDL_SCANCODE_A,
			SDL_SCANCODE_S, /* 1 */

			SDL_SCANCODE_D,
			SDL_SCANCODE_F,
			SDL_SCANCODE_G,
			SDL_SCANCODE_H,
			SDL_SCANCODE_J,
			SDL_SCANCODE_K,
			SDL_SCANCODE_L,
			SDL_SCANCODE_SEMICOLON, /* 2 */
			SDL_SCANCODE_APOSTROPHE,
			SDL_SCANCODE_GRAVE,
			SDL_SCANCODE_LSHIFT,
			SDL_SCANCODE_BACKSLASH,
			SDL_SCANCODE_Z,
			SDL_SCANCODE_X,
			SDL_SCANCODE_C,
			SDL_SCANCODE_V, /* 2 */

			SDL_SCANCODE_B,
			SDL_SCANCODE_N,
			SDL_SCANCODE_M,
			SDL_SCANCODE_COMMA,
			SDL_SCANCODE_PERIOD,
			SDL_SCANCODE_SLASH,
			SDL_SCANCODE_RSHIFT,
			SDL_SCANCODE_PRINTSCREEN, /* 3 */
			SDL_SCANCODE_LALT,
			SDL_SCANCODE_SPACE,
			SDL_SCANCODE_CAPSLOCK,
			SDL_SCANCODE_F1,
			SDL_SCANCODE_F2,
			SDL_SCANCODE_F3,
			SDL_SCANCODE_F4,
			SDL_SCANCODE_F5, /* 3 */

			SDL_SCANCODE_F6,
			SDL_SCANCODE_F7,
			SDL_SCANCODE_F8,
			SDL_SCANCODE_F9,
			SDL_SCANCODE_F10,
			SDL_SCANCODE_NUMLOCKCLEAR,
			SDL_SCANCODE_SCROLLLOCK,
			SDL_SCANCODE_HOME, /* 4 */
			SDL_SCANCODE_UP,
			SDL_SCANCODE_PAGEUP,
			SDL_SCANCODE_KP_MINUS,
			SDL_SCANCODE_LEFT,
			SDL_SCANCODE_KP_5,
			SDL_SCANCODE_RIGHT,
			SDL_SCANCODE_KP_PLUS,
			SDL_SCANCODE_END, /* 4 */

			SDL_SCANCODE_DOWN,
			SDL_SCANCODE_PAGEDOWN,
			SDL_SCANCODE_INSERT,
			SDL_SCANCODE_DELETE,
			SDL_SCANCODE_UNKNOWN,
			SDL_SCANCODE_UNKNOWN,
			SDL_SCANCODE_NONUSBACKSLASH,
			SDL_SCANCODE_F11, /* 5 */
			SDL_SCANCODE_F12,
			SDL_SCANCODE_PAUSE,
			SDL_SCANCODE_UNKNOWN,
			SDL_SCANCODE_LGUI,
			SDL_SCANCODE_RGUI,
			SDL_SCANCODE_APPLICATION,
			SDL_SCANCODE_UNKNOWN,
			SDL_SCANCODE_UNKNOWN, /* 5 */

			SDL_SCANCODE_UNKNOWN,
			SDL_SCANCODE_UNKNOWN,
			SDL_SCANCODE_UNKNOWN,
			SDL_SCANCODE_UNKNOWN,
			SDL_SCANCODE_F13,
			SDL_SCANCODE_F14,
			SDL_SCANCODE_F15,
			SDL_SCANCODE_F16, /* 6 */
			SDL_SCANCODE_F17,
			SDL_SCANCODE_F18,
			SDL_SCANCODE_F19,
			SDL_SCANCODE_UNKNOWN,
			SDL_SCANCODE_UNKNOWN,
			SDL_SCANCODE_UNKNOWN,
			SDL_SCANCODE_UNKNOWN,
			SDL_SCANCODE_UNKNOWN, /* 6 */

			SDL_SCANCODE_INTERNATIONAL2,
			SDL_SCANCODE_UNKNOWN,
			SDL_SCANCODE_UNKNOWN,
			SDL_SCANCODE_INTERNATIONAL1,
			SDL_SCANCODE_UNKNOWN,
			SDL_SCANCODE_UNKNOWN,
			SDL_SCANCODE_UNKNOWN,
			SDL_SCANCODE_UNKNOWN, /* 7 */
			SDL_SCANCODE_UNKNOWN,
			SDL_SCANCODE_INTERNATIONAL4,
			SDL_SCANCODE_UNKNOWN,
			SDL_SCANCODE_INTERNATIONAL5,
			SDL_SCANCODE_UNKNOWN,
			SDL_SCANCODE_INTERNATIONAL3,
			SDL_SCANCODE_UNKNOWN,
			SDL_SCANCODE_UNKNOWN /* 7 */
	};

	static const SDL_Scancode scancode_rmapping_nonextended[][2] = {
			{SDL_SCANCODE_KP_7, SDL_SCANCODE_HOME},
			{SDL_SCANCODE_KP_8, SDL_SCANCODE_UP},
			{SDL_SCANCODE_KP_9, SDL_SCANCODE_PAGEUP},
			{SDL_SCANCODE_KP_4, SDL_SCANCODE_LEFT},
			{SDL_SCANCODE_KP_6, SDL_SCANCODE_RIGHT},
			{SDL_SCANCODE_KP_1, SDL_SCANCODE_END},
			{SDL_SCANCODE_KP_2, SDL_SCANCODE_DOWN},
			{SDL_SCANCODE_KP_3, SDL_SCANCODE_PAGEDOWN},
			{SDL_SCANCODE_KP_0, SDL_SCANCODE_INSERT},
			{SDL_SCANCODE_KP_PERIOD, SDL_SCANCODE_DELETE},
			{SDL_SCANCODE_KP_MULTIPLY, SDL_SCANCODE_PRINTSCREEN}};

	static const SDL_Scancode scancode_rmapping_extended[][2] = {
			{SDL_SCANCODE_KP_ENTER, SDL_SCANCODE_RETURN}, {SDL_SCANCODE_RALT, SDL_SCANCODE_LALT}, {SDL_SCANCODE_RCTRL, SDL_SCANCODE_LCTRL}, {SDL_SCANCODE_KP_DIVIDE, SDL_SCANCODE_SLASH},
			//{SDL_SCANCODE_KP_PLUS, SDL_SCANCODE_CAPSLOCK}
	};

	static int inverted_scancode_table[512];

	class Sdl : public Base
	{
	public:
		SDL_Window *wnd;

		unsigned int window_width = 1280;
		unsigned int window_height = 720;
		bool fullscreen_state;
		void (*on_fullscreen_changed_callback)(bool is_now_fullscreen) = NULL;

		Sdl(const char *game_name, bool start_in_fullscreen) : Base()
		{
			SDL_Init(SDL_INIT_VIDEO);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
			SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

			SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
			// SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

			// SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
			// SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);

			char title[512];
			int len = sprintf(title, "%s (%s)", game_name, GFX_API_NAME);

#ifdef __SWITCH__
			wnd = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
#else
			wnd = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);

			if (start_in_fullscreen)
			{
				set_fullscreen(true, false);
			}
#endif

			/* If we're in OpenGL mode, just create a stub surface and we're done! */
			SDL_GLContext *SDL_VideoContext = (SDL_GLContext *)SDL_GL_CreateContext(wnd);
			if (!SDL_VideoContext)
			{
				printf("SDL_GL_CreateContext failed: %s\n", SDL_GetError());
				return;
			}
			if (SDL_GL_MakeCurrent(wnd, SDL_VideoContext) < 0)
			{
				printf("SDL_GL_MakeCurrent failed: %s\n", SDL_GetError());
				return;
			}
			SDL_Surface *SDL_VideoSurface = SDL_CreateRGBSurfaceFrom(NULL, window_width, window_height, 24, 0, 0, 0, 0, 0);
			if (!SDL_VideoSurface)
			{
				printf("SDL_CreateRGBSurfaceFrom failed: %s\n", SDL_GetError());
				return;
			}

			set_vsync();
			WindowsWGL_GrabWindow(wnd);
			gfx_resize(window_width, window_height);
			SDL_RaiseWindow(wnd);
		}

		void set_fullscreen(bool on, bool call_callback)
		{
#ifndef __SWITCH__
			if (fullscreen_state == on)
			{
				return;
			}
			fullscreen_state = on;

			SDL_DisplayMode mode;
			SDL_GetDesktopDisplayMode(SDL_GetWindowDisplayIndex(wnd), &mode);

			m_refreshInterval = std::chrono::microseconds(1000 * 1000 / mode.refresh_rate);

			if (on)
			{
				window_width = mode.w;
				window_height = mode.h;
			}
			else
			{
				window_width = DESIRED_SCREEN_WIDTH;
				window_height = DESIRED_SCREEN_HEIGHT;
			}
			SDL_SetWindowSize(wnd, window_width, window_height);
			SDL_SetWindowFullscreen(wnd, on ? SDL_WINDOW_FULLSCREEN : 0);

			gfx_resize(window_width, window_height);

			if (on_fullscreen_changed_callback != NULL && call_callback)
			{
				on_fullscreen_changed_callback(on);
			}
#endif
		}

		void set_vsync()
		{
			if (SDL_GetNumVideoDisplays() > 0)
			{
				SDL_DisplayMode mode;

				if (SDL_GetDesktopDisplayMode(SDL_GetWindowDisplayIndex(wnd), &mode) == 0) // assume highest resolution display is the one in use
				{
					// m_refreshInterval = std::chrono::microseconds(1000 * 1000 / mode.refresh_rate);
					m_refreshInterval = std::chrono::microseconds(1000 * 1000 / 60);
					return;
				}
			}

			m_refreshInterval = std::chrono::microseconds(1000 * 1000 / 60); // assume 60 fps

			return;
		}

		void set_fullscreen_changed_callback(void (*on_fullscreen_changed)(bool is_now_fullscreen))
		{
			on_fullscreen_changed_callback = on_fullscreen_changed;
		}

		void get_dimensions(u32 *width, u32 *height)
		{
			*width = window_width;
			*height = window_height;
		}

		int translate_scancode(int scancode)
		{
			if (scancode < 512)
			{
				return inverted_scancode_table[scancode];
			}
			else
			{
				return 0;
			}
		}

		void handle_events()
		{
			SDL_Event event;
			while (SDL_PollEvent(&event))
			{
				switch (event.type)
				{
				case SDL_WINDOWEVENT:
					if (event.window.event == SDL_WINDOWEVENT_RESIZED)
					{
						window_width = event.window.data1;
						window_height = event.window.data2;
						resize(window_width, window_height);
					}
					break;
				case SDL_QUIT:
					quit();
				}
			}
		}

		void swap_buffers_begin()
		{
			SDL_GL_SwapWindow(wnd);
		}

		void swap_buffers_end()
		{
		}

		void resize(long width, long height)
		{
			if (width > 0 && height > 0)
			{
				window_width = width;
				window_height = height;
			}
			gfx_resize(window_width, window_height);
		}
	};

	std::unique_ptr<Base> create(const char *name, bool fullscreen)
	{
		return std::make_unique<Sdl>(name, fullscreen);
	}
}
