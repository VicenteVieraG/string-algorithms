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

The project structure is not very complex. Each algorithm is built as a library and then linked to the main project. All libraries consist of an `hpp` header file and a `cpp` source file. Some algorithms may use some dependencies from the utils folder. This structure makes it easy to just copy and paste the code for your own project or either build just the algorithms you need.