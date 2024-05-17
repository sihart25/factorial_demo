# Demonstration Project for CI 
 
 

## Requirements

- CMake Minimum Version 3.10)
- gcc+ ( require gcc 10.1 or higher).

## Quick start

this is a demonstration project for ``` C++ 23, make and CI``` ,
```bash

cmake -S ./ -B build
cmake --build build -j 2 -v  
cmake  --install ../bin
```

This will make a build directory (-B) if it does not exist, with the source directory defined as -S.
CMake will configure and generate makefiles by default, as well as set all options to their default settings and cache them into a file called CMakeCache.txt, which will sit in the build directory.
You can call the build directory anything you want; by convention it should have the word build in it to be ignored by most package’s .gitignore files.

You can then invoke your build system (line 2). You can add '-j 2' to build on two cores, or '-v' to verbosely show commands used to build.

Finally, you can even run your tests from here, by passing the 'Factorial_tst' target to the underlying build system.
 '-t' lets you select a target. 
There’s also a cmake <dir> --install command in CMake 3.15+ that does the install - without invoking the underlying build system!



to run the executable use the command below in the build directory.
Here we are providing the argument of `7` to get the factorial of it.

```bash 

./build/bin/calcFactorial 7

```
Output should be:
```bash
The factorial of 7 = 5040
```

to runtests we call build and tests

``bash

cmake --build build ; ./build/test/bin/Factorial_tst

```


