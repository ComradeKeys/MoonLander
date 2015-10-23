bin_PROGRAMS = moon

#files of project
moon_SOURCES = src/main.cpp src/MoonGame.cpp src/MoonGame.hpp src/Moon.cpp src/Moon.hpp src/Game.cpp src/Game.hpp src/Ship.hpp src/Ship.cpp src/Ground.cpp src/Ground.hpp src/Vector3d.hpp src/Vector3d.cpp src/Platform.hpp src/Tile.cpp src/Tile.hpp src/Platform.hpp src/Platform.cpp src/Font.hpp src/Font.cpp

AM_CXXFLAGS = -pedantic -O3 -std=c++14 -Werror -g 

#using an m4 directory for macros
ACLOCAL_AMFLAGS = -I m4 --install

#letting autoconf know about the m4 dir
EXTRA_DIST = m4/NOTES
