# -*- Makefile -*-

# filename
filename = modern815

# args
args = -g $(filename).cpp -std=c++17
winfile = -o $(filename).exe
linfile = -o $(filename).x

# setups for different systems
all: windows wlinux
wall: windows wlinux
windows:
	g++ $(args) $(winfile)
wlinux:
	wsl.exe g++ $(args) $(linfile)
lall: linux lwindows
linux:
	g++ $(args) $(linfile)
lwindows:
	x86_64-w64-mingw32-g++-posix $(args) $(winfile)
winetest:
	i686-w64-mingw32-g++-posix $(args) $(winfile) --static

# aufräumen
wclean:
	del *.exe *.x *.o
lclean:
	rm -f *.exe *.x *.o