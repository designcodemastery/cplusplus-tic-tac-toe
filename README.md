# cplusplus-tic-tac-toe

__This is the repo for my first attempt at a C++ console app version of the classic game Tic-Tac-Toe.__

I am using the solution architecture I used when learning Python in 2021 as a guide for my C++ app. This might not be the best or more efficient one, but it is a start for me to build upon.

For this C++ version I am using CMake and Ninja for build setup and generator. This is my introduction to both of these systems, so my setup is very basic indeed, just providing the bare minimum to allow me to build the application on both my Windows 11 Pro and Ubuntu 22 developer plaforms from the same code base.

## Documentation

In the documentation folder you will find the following:

1. architecture.md: This will give you the solution architecture I have used for this app.
2. setup.md: Instructions for setting up the development environment.
3. build.md: Instructions to build the Tic-Tac-Toe game project using CMake with the Ninja build system.

## Enhancements

1. I would like to come back to this project at some stage and include a testing framework.
2. I am interested in implementing an AI computer move facility using something like the MiniMax algorithm.
3. As well as being cross-platform, I would like to look at making the app locale aware and support other languages than English.