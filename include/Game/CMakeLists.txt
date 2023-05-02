cmake_minimum_required(VERSION 3.11)

set(GAME_SOURCES Game.cpp Game.h)

add_library(Game ${GAME_SOURCES})

target_include_directories(Game PRIVATE ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ../TextureManager)
target_link_libraries(Game PRIVATE ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} TextureManager)

