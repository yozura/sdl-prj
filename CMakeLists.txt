cmake_minimum_required(VERSION 3.11)

include_directories(
    /usr/include/SDL2/
    /usr/include/GL/)

project(dfgl)
add_executable(dfgl dfgl/dfgl.c)

target_link_libraries(dfgl SDL2)
target_link_libraries(dfgl GL)
