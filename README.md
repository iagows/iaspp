# iasPP

Meaning: iago action script ++;

## About

C++ Library to make easier to create games. C++11, SLD, FFMPEG. Created using Qt Creator with MingW. I'm doing this to personal use and with my freetime, so don't expect many updates, sorry.
If you find any "iagogamelib", or "aspp" please tell me to remove/update it. Thanks!

![iaspp](asp.png)

## Special Thanks to

| Site | Why? |
| :--- | ---: |
| https://www.libsdl.org/ | SDL ( S2 ) |
| http://www.willusher.io/pages/sdl2/ | basics, c++11 |
| http://www.java2s.com/ | simple codes |
| http://lazyfoo.net/tutorials/SDL/ | basics |
| https://stackoverflow.com/ | doubts, sdl2, libVLC, c++11, c++14, c, c++ etc |
| http://forums.linuxmint.com/ | doubts |
| http://www.linuxquestions.org | doubts |
| http://pubs.opengroup.org/onlinepubs/7908799/xsh/sysstat.h.html | mkdir - linux |
| https://www.google.com.br/ | found pages :P |
| http://qt-project.org/ | Qt Creator |
| https://github.com | Free storage |
| https://wiki.videolan.org/LibVLC_Users/ | libVLC |
| https://wiki.videolan.org/LibVLC_SampleCode_SDL/ | libVLC |
| http://spin.atomicobject.com/2013/01/13/exceptions-stack-traces-c/ | stacktrace for windows and linux |
| http://higherorderfun.com/blog/2012/06/03/math-for-game-programmers-05-vector-cheat-sheet/#more-123 | math |
| http://madebyevan.com/obscure-cpp-features/ | helpful obscure codes |
| https://github.com/ | GitHub |
| http://gcc.gnu.org/wiki/Visibility | library in Linux |

### Notes

In **windows**, I've included "windows.h", so I had to fix **Rectangle**:

```cpp
#ifdef __MINGW32__
    #define Rectangle winRectangle
    #include <windows.h>
    #undef Rectangle
#include <lmcons.h>
```

### Changes
| How should be | How it is | Why? |
| :------------ | :-------: | ---: |
| MouseEvent::DOUBLE_CLICK | MouseEvent::DOUBLE_CLICK_ | wincon.h  defines it|

### Tasks
#### Tested
- [x] Windows tested
- [ ] Linux tested (Ubuntu only)
- [x] ~~Mac tested~~ No ios. Sorry.

##### next steps

* finish MouseMove event
* finish TextField
* test TextField


## Requirements
* SDL2
* libVLC (not yet)

###generating ssh keys
https://help.github.com/articles/generating-ssh-keys/

###defining user
$ git config --global user.name "John Doe"
$ git config --global user.email johndoe@example.com

###how to clone with ssh
http://stackoverflow.com/questions/20871549/error-when-push-commits-with-github-fatal-could-not-read-username/20884273#20884273