# -*- Makefile -*-

# filename
filename = openssltest

# args
args = -g $(filename).cpp -std=c++17  -lssl -lcrypto
winfile = -IC:/msys64/usr/local/include -LC:/msys64/usr/local/lib -o $(filename).exe
linfile = -I/usr/local/include -L/usr/local/lib -o $(filename).x

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