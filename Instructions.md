# Instruction Steps:
### Install 32bit prequisites for gcc (libpng, SDL, freetype, mesa-gl)
### **NOTE**: This section is evolving with community feedback
  Fedora:

        sudo dnf install gcc-c++ libpng-devel.i686 freetype-devel.i686 SDL2-devel.i686 libx11-devel.i686 mesa-libGL-devel.i686 pkgconf-pkg-config.i686
  Debian:

        sudo apt-get install gcc-multilib libpng-dev:i386 libfreetype6-dev:i386 libsdl-dev:i386 libgl1-mesa-dev:i386
  Arch:

          sudo pacman -S ???

1. Install python3, pip3 for asset extraction, also install python dependencies

        pip3 install -r requirements.txt

1. Paste `baserom_original.z64` here
1. Build the ZAPD tool

        ./build_ZAPD.sh
1. Extract assets

        ./setup_assets.sh

1. Choose your favorite Build System:
      1. [Meson](#Meson) *the preferred choice*
      2. [Make](#Make)

## Meson
1. Install Meson+Ninja on your system
1. Build OpenOoT

        meson builddir --cross-file x86-linux-gnu
        cd builddir
        meson compile
1. `ooot` will be in the `builddir` directory
1. Enjoy playing OpenOoT!

## Make
1. Install GNU Make on your system
1. **IMPORTANT**: `-j` is optional but recommended, it will use multiple cores to speed up the build process.
1. Build GLideN64

        cd subprojects/GLideN64/projects/cmake
        cmake -DCMAKE_TOOLCHAIN_FILE=linux_i686.toolchain.cmake  -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DSDL=1 -DNOHQ=1 ../../src/
        make -j

1. Build OpenOoT

        make -f Makefile.linux -j
1. `ooot` will be in the `build` directory
1. Enjoy playing OpenOoT!