# -*- Makefile -*-
all: windows wlinux
windows: main.cpp
	g++ -g main.cpp -o main.exe -std=c++17
wlinux:
	wsl.exe g++ -g main.cpp -o main.x -std=c++17
linux:
	g++ -g main.cpp -o main.exe -std=c++17
# aufräumen
wclean:
	del *.exe *.x *.o
lclean:
	rm -f *.exe *.x *.o