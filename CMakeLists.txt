# Main CMake file
cmake_minimum_required(VERSION 3.31.5)

project(stringsAlgorithms VERSION 0.1.3 LANGUAGES C CXX)

# Configure build options
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Create binary outputs at ./build/bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Libraries
set(stringAlgos STRING_ALGOS)

# Subdirectories
add_subdirectory(config)
add_subdirectory(external)
add_subdirectory(src)
add_subdirectory(include)
add_subdirectory(app)
