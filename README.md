# gc-polyscope-project-template
A template project to get started with [geometry-central](http://geometry-central.net/) and [Polyscope](http://polyscope.run/).


### Get the code
Clone the project 
```
git clone --recursive https://github.com/nmwsharp/gc-polyscope-project-template.git
```

### Build the code

**Unix-like machines**: configure (with cmake) and compile
```
cd gc-polyscope-project-template
mkdir build
cd build
cmake ..
make -j6
```

**Windows / Visual Studio**

Install CMake, and use either the CMake GUI or the command line interface (as on unix) to generate a Visual Studio solution.  Build the solution with Visual Studio.

### Run the code
```
./bin/gc_project /path/to/a/mesh
```

### Edit the code

Modify the main file `src/main.cpp` to start implementing your own algorithms. `CMakeLists.txt` contains a few comments for adding additional files.  

## Interactive interpreter

The `console` subdirectory contains instructions and an example for running geometry-central and Polyscope in an interactive C++ interpreter with `cling`.
