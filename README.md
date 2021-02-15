# lovelyGameEngine
My attempt at a 2D game engine.
This may, or may not turn into a disaster.

As of right now, lovelyGameEngine is JUST for me to learn how game engines work.

Who know's, maybe this will become more than an experiment!

The lovely Game engine also aims to be **cross platform.**

### Language used:
I am using C++ to develop the game engine.

### Development enviornment:
- OS: Manjaro Linux

### External libs:
- (OpenGL)
- glfw
- glew
- glm (OpenGL Mathematics)
- SOIL

### Compilation errors:

- Did you run the installation script located in the scripts/ folder? (Arch linux script deprecated right now)

- Getting linker error undefined reference to ... regarding the Nuklear api?
    - There is this weird bug where you must first comment out everything that has to do with the Nuklear api (interface/window.cxx/h), then compile the engine, then uncomment everything and compile the engine again.
    - I have created a simple workaround for this. First run make, then make safe safe=1 (you may have to run this command twice- I know this is really bad but it works). After that just run make safe=1 every time you change something NON UI related. If you get any linker errors, make clean and redo all this.

# Special thanks:
- [The Chernos](https://www.youtube.com/user/TheChernoProject) Game Engine series: Sparky, and Hazel.
- This [stackoverflow answer](https://stackoverflow.com/questions/17768008/how-to-build-install-glfw-3-and-use-it-in-a-linux-project/44615274#44615274) I found that installs GLFW in linux.
