# Demonstration Project for CI 


[docs-stable-img]: https://img.shields.io/badge/docs-stable-blue.svg
[docs-stable-url]: https://amdgpu.juliagpu.org/stable
 

## Requirements

- CMake Minimum Version 3.10)
- gcc+ ( require gcc 10.1 or higher).

## Quick start

this is a demonstration project for ``` C++ 17, make and CI```  to build:

```bash
mkdir build && cd build
cmake ..
cmake –build .

```

to run the executable use the command below in the build directory.
Here we are providing the argument of `7` to get the factorial of it.

```bash 

Debug/Factorial.exe 7

```
Output should be:
```bash
The factorial of 7 = 5040
```


## Sulis Modules Build Requirements

- 

## BEAR Modules Build Requirements

- module load bear-apps/2022b
- module load CMake/3.24.3-GCCcore-12.2.0

