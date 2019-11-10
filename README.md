# Breakoutc

A _Breakout_ clone written in C using a strict ECS architecture. It's a port of
https://github.com/piesku/breakout/tree/tutorial.

![Screenshot](screenshot.png?raw=true)

## Windows

Open the repo in Visual Studio 2019 using the _Open a local folder_ option.

## Linux

    $ mkdir out
    $ cd out
    $ cmake ..
    $ make
    $ ./breakoutc

## MacOS

[Download SDL2](https://www.libsdl.org/download-2.0.php) and copy it to `/Library/Frameworks`

    $ mkdir out
    $ cd out
    $ cmake ..
    $ make
    $ ./breakoutc
