String Algorithms
====================================
Vicete Javier Viera Guízar

## Description
This project is a collection of some string algorithms that either are interesting or useful to know. The algorithms are implemented in `C++` by me.

## Algorithms
### Pattern Matching
- [KMP](docs/KMP.md)

## Build
This project uses `CMake` as the build system. You can build the project by running the basic CMake command:

```shell
mkdir build
cd build
cmake ..
cmake --build .
```

The project structure is not very complex. All the algorithms are bundled in a single library that is linked to the main executable. Each algorithm consist of an `hpp` header file and a `cpp` source file. This arrangement makes it easy to just copy and paste the code for each algorithm so you do not need to build all the library.