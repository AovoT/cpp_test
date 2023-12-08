cmake_minimum_required(VERSION 3.16)
project(version_test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS src/*.cpp src/*.h)

add_executable(version_test ${sources})
target_include_directories(version_test PUBLIC
        src/basic/include
        src/class_test/include
        src/utils/include
        )