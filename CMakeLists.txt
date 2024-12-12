cmake_minimum_required(VERSION 3.29)

project(Factorial)

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

set(FACTORIAL_VERSION_MAJOR   0   CACHE STRING "factorial-project major version number.")
set(FACTORIAL__VERSION_MINOR   ${INCREMENTED_VALUE}   CACHE STRING "factorial-project minor version number.")
set(FACTORIAL__VERSION_PATCH   1   CACHE STRING "factorial-project patch version number.")

# Update the cache
file(WRITE ${CACHE_FILE} "${FACTORIAL__VERSION_MINOR}")

mark_as_advanced(FACTORIAL_VERSION_MAJOR FACTORIAL_VERSION_MINOR FACTORIAL_VERSION_PATCH)
set(FACTORIAL__HEADER "Factorial 2024" )
set(FACTORIAL__USAGE "Usage:\t calc factorial <number to calc factorial:n>>" )
set(FACTORIAL__USAGE_DESC  "Description:\t Computes the factorial" )
mark_as_advanced(FACTORIAL_HEADER FACTORIAL_USAGE FACTORIAL_USAGE_DESC)
#cmake_print_variables(FACTORIAL__HEADER)
configure_file(factorial_config.h.in ./src/factorial_config.h)

set(SOURCES ./src/main.cpp ./src/Factorial.cpp )
set(HEADERS ./src/Factorial.h ./src/factorial_config.h)
add_executable(calcFactorial ${SOURCES} ${HEADERS})

set_property(TARGET calcFactorial PROPERTY CXX_STANDARD 17)
set_property(TARGET calcFactorial PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET calcFactorial PROPERTY CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Debug)


SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -O0 -g -fno-rtti")
#SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")
#SET(CMAKE_CXX_FLAGS_RELEASE "-O3")
#SET(CMAKE_CXX_FLAGS_DEBUG  "-O0 -g")

enable_testing()
add_subdirectory (test)