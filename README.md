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

**Bazel**

Install [Bazel](https://bazel.build/install) (version 7 or later to enable Bzlmod for loading external dependencies) and then run:

```
bazel run src:main external/geometry_central/test/assets/fox.ply
```

Note that with Bazel, you don't have to clone this project with the `--recursive` flag, since all dependencies are loaded at compile time.

### Run the code
```
./bin/gc_project /path/to/a/mesh
```

### Edit the code

Modify the main file `src/main.cpp` to start implementing your own algorithms. `CMakeLists.txt` contains a few comments for adding additional files.  

## Interactive interpreter

The `console` subdirectory contains instructions and an example for running geometry-central and Polyscope in an interactive C++ interpreter with `cling`.
