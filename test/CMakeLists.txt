cmake_minimum_required(VERSION 3.29)

# Setup GoogleTest
configure_file(CMakeLists.txt.ini googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
   message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)


set(BINARY ${CMAKE_PROJECT_NAME}_tst)

set(SOURCES ./main.cpp ./factorial_tests.cpp ../src/Factorial.cpp) 
set(HEADERS ../src/Factorial.h)
add_executable(${BINARY} ${SOURCES} ${HEADERS})
set_property(TARGET ${BINARY} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${BINARY} PROPERTY CXX_STANDARD_REQUIRED ON)
include_directories(../src)
target_link_libraries(${BINARY} gtest_main)
enable_testing()

add_test(NAME Usage COMMAND ${BINARY})
set_tests_properties(Usage
  PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number"
)

add_test(NAME ${BINARY} COMMAND ${BINARY} )
 function(do_test target arg result)
  add_test(NAME Comp${arg} COMMAND ${target} ${arg})
  set_tests_properties(Comp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endfunction()

# do a bunch of result based tests
do_test(${BINARY} 4 "4 = 24")
do_test(${BINARY} 9 "9 = 362880")
do_test(${BINARY} 5 "5 = 120")
do_test(${BINARY} 7 "7 = 5040")
do_test(${BINARY} 25 "25 = 7034535277573963776") 