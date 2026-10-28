cmake_minimum_required(VERSION 3.10.0)
project(dinogame VERSION 0.1.0 LANGUAGES C CXX)

find_package(raylib REQUIRED)

add_executable(dinogame main.cpp)

target_link_libraries(dinogame PRIVATE raylib)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
