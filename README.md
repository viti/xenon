# xenon

The Intrig message decoder.

## Quick Start

    git clone --recursive https://github.com/intrig/xenon.git
    cd xenon
    make 
    make test

## Updating an existing repo to latest

    git pull
    git submodule update

## Building on Windows

Windows requires the following steps:

1. Install [Github Desktop](https://desktop.github.com)

   Clone the xenon repo.

2. Install [cmake](https://cmake.org/runningcmake/)

   Follow the instructions in the above link to have cmake generate the Visual Studio build files.

3. Microsoft Visual Studio 2015 (or later)
  
  Load and build the Visual Studio Solution file located at `xenon/build/Program.sln`.

## Dependencies

    cmake
    C++11 compiler
    Github desktop (on Windows)

## Additional dependencies

Boost dependencies are not required for xenon, but some tests tests will be skipped if boost cannot be found.

    ubuntu: sudo apt-get install libboost-all-dev
    mac: brew install boost
    windows: dunno, I just skip it

After building, a static library, xenon, can be found in the `xenon/o` directory.

See the examples directory for some common uses of the decoder.

Also, the tools directory contains examples, such as idm and xv.

For your application, you just need the contents of the include directory and link with the xenon library.
