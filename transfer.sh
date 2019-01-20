#!/bin/bash

tar -cJf modernc++package.tar.xz ./Modern\ C++/*

scp ./modernc++package.tar.xz aipi-extern:/srv/smb/shitbox/Jonas/Programmieren/
ssh aipi-extern 'cd /srv/smb/shitbox/Jonas/Programmieren;
                 tar -xvf ./modernc++package.tar.xz;
                 rm modernc++package.tar.xz'
rm modernc++package.tar.xz
