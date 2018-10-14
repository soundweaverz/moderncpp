# -*- Makefile -*-
all: windows wlinux
wall: windows wlinux
windows: modern710.cpp
	g++ -g modern710.cpp -o modern710.exe -std=c++17
wlinux:
	wsl.exe g++ -g modern710.cpp -o modern710.x -std=c++17
lall: linux lwindows
linux:
	g++ -g modern710.cpp -o modern710.x -std=c++17
lwindows:
	x86_64-w64-mingw32-g++-posix -g modern710.cpp -o modern710.exe -std=c++17
winetest:
	i686-w64-mingw32-g++-posix -g modern710.cpp -o modern710.exe -std=c++17 --static
# aufräumen
wclean:
	del *.exe *.x *.o
lclean:
	rm -f *.exe *.x *.o