cmake_minimum_required(VERSION 3.11)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE BOOL "Enable/Disable output of compile commands during generation" FORCE)

# Set Compiler
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

####################################################################
# Project Config
####################################################################

# Set Project Name
project(MyGame)

# Find Packages
find_package(SDL2       REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(OpenGL     REQUIRED)

# Add SubLibaries
add_subdirectory(include)

# Program
add_executable(${PROJECT_NAME} src/main.cpp)

# Include Directories
target_include_directories(
    ${PROJECT_NAME} PRIVATE 
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_IMAGE_INCLUDE_DIRS}
    include/Game
    include/TextureManager
)

# Link Libraries
target_link_libraries(
    ${PROJECT_NAME} PRIVATE
    ${SDL2_LIBRARIES}
    ${SDL2_IMAGE_LIBRARIES}
    Game
    TextureManager
)

####################################################################

