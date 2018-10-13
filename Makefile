# -*- Makefile -*-
all: windows wlinux
windows: modern708.cpp
	g++ -g modern708.cpp -o modern708.exe -std=c++17
wlinux:
	wsl.exe g++ -g modern708.cpp -o modern708.x -std=c++17
linux:
	g++ -g modern708.cpp -o modern708.exe -std=c++17
# aufräumen
wclean:
	del *.exe *.x *.o
lclean:
	rm -f *.exe *.x *.o