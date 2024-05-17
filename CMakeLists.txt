cmake_minimum_required(VERSION 3.29)

project(Factorial
  VERSION
    1.0
  DESCRIPTION
    "Factorial is a very nice project"
  LANGUAGES
    CXX
)

set(SOURCES ./src/main.cpp ./src/Factorial.cpp )
set(HEADERS ./src/Factorial.h)
set(EXECUTABLE_OUTPUT_PATH ./bin)
add_executable(calcFactorial ${SOURCES} ${HEADERS})
set_property(TARGET calcFactorial PROPERTY CXX_STANDARD 17)
set_property(TARGET calcFactorial PROPERTY CXX_STANDARD_REQUIRED ON)


SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -O0 -g -fno-rtti")
#SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")
#SET(CMAKE_CXX_FLAGS_RELEASE "-O3")
#SET(CMAKE_CXX_FLAGS_DEBUG  "-O0 -g")

set(CMAKE_CXX_CLANG_TIDY clang-tidy -checks=-*,readability-*)
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})
set(CACHE_FILENAME "BuildNumberCache.txt")
set(CACHE_FILE "${CMAKE_SOURCE_DIR}/${CACHE_FILENAME}")
message( STATUS "#Reading data from file + incrementation")
IF(EXISTS ${CACHE_FILE})
    message( STATUS ${CACHE_FILE})
    file(READ ${CACHE_FILE} INCREMENTED_VALUE )
    math(EXPR INCREMENTED_VALUE  "${INCREMENTED_VALUE}+1")
ELSE()
    message( STATUS "Missing: ${CACHE_FILE}")
    set(INCREMENTED_VALUE  "1")
ENDIF()

set(LIBCNEAREST_VERSION_MAJOR   0   CACHE STRING "cNearest-project major version number.")
set(LIBCNEAREST_VERSION_MINOR   ${INCREMENTED_VALUE}   CACHE STRING "cNearest-project minor version number.")
set(LIBCNEAREST_VERSION_PATCH   1   CACHE STRING "cNearest-project patch version number.")

# Update the cache
file(WRITE ${CACHE_FILE} "${LIBCNEAREST_VERSION_MINOR}")

mark_as_advanced(LIBCNEAREST_VERSION_MAJOR LIBCNEAREST_VERSION_MINOR LIBCNEAREST_VERSION_PATCH)
set(LIBCNEAREST_HEADER "cNearest © 2020 University of Birmingham" )
set(LIBCNEAREST_USAGE "Usage:\t cnearestbin <Points for Sphere:p> <prolate x:a> <prolate yz:c>" )
set(LIBCNEAREST_USAGE_DESC  "Description:\t Computes the Grand Resistance Matrix and compares the analytical result to the numerical" )
mark_as_advanced(LIBCNEAREST_HEADER LIBCNEAREST_USAGE LIBCNEAREST_USAGE_DESC)
#cmake_print_variables(LIBCNEAREST_HEADER)
configure_file(cnearestlib_config.h.in cnearestlib_config.h)

enable_testing()
add_subdirectory (test)