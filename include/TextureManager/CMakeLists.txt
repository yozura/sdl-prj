cmake_minimum_required(VERSION 3.11)

set(TM_SOURCES TextureManager.cpp TextureManager.h)

add_library(TextureManager ${TM_SOURCES})

target_include_directories(TextureManager PRIVATE ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(TextureManager PRIVATE ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

