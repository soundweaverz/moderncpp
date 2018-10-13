# -*- Makefile -*-
all: windows wlinux
windows: modern710.cpp
	g++ -g modern710.cpp -o modern710.exe -std=c++17
wlinux:
	wsl.exe g++ -g modern710.cpp -o modern710.x -std=c++17
linux:
	g++ -g modern710.cpp -o modern710.exe -std=c++17
# aufräumen
wclean:
	del *.exe *.x *.o
lclean:
	rm -f *.exe *.x *.o