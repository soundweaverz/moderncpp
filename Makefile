# -*- Makefile -*-

# filename
filename = modern1210

### args ### 

# for RSA shit
# args = -g $(filename).cpp -std=c++17 -Wall -DDEBUG -lssl -lcrypto
# winfile = -IC:/OpenSSL-x64/include -LC:/OpenSSL-x64/lib -o $(filename).exe
# linfile = -I/usr/local/include -L/usr/local/lib -o $(filename).x

# for normal stuff
args = -g $(filename).cpp -std=c++17 -Wall
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
	del *.exe *.x *.o *.pem *.txt
lclean:
	rm -f *.exe *.x *.o *.pem *.txt