gaim
====


Dependencies
* [SDL2](http://www.libsdl.org/)
* [SDL2 Image](http://www.libsdl.org/projects/SDL_image/)
* [SDL2 TTF](http://www.libsdl.org/projects/SDL_ttf/)
* [JsonCPP](http://jsoncpp.sourceforge.net/) 0.6.0.rc2
 
Developed on windows using MinGW, it should cross compile but i've not yet tried.

Also require a fix to minGw's io.h the references of "off64 _ t" to "_ off64_t" (without spaces, sorry formatting issues for _) see: http://sourceforge.net/p/mingw/bugs/2024/
