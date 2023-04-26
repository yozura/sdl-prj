cmake_minimum_required(VERSION 3.11)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE BOOL "Enable/Disable output of compile commands during generation" FORCE)

###################################################################
# Project Config
####################################################################

# Set Include path
set(SDL2_INCLUDE_PATH /usr/include/SDL2/)
set(GL_INCLUDE_PATH /usr/include/GL/)

# Set Project Names
set(DFGL "dfgl")
set(ONLYSDL "onlysdl")

# DFGL
project(${DFGL})
add_executable(${DFGL} ${DFGL}/${DFGL}.c)

target_include_directories(${DFGL} PRIVATE ${SDL2_INCLUDE_PATH}	${GL_INCLUDE_PATH})

target_link_libraries(${DFGL} SDL2)
target_link_libraries(${DFGL} GL)

# ONLYSDL
project(${ONLYSDL})
add_executable(${ONLYSDL} ${ONLYSDL}/${ONLYSDL}.cpp)

target_include_directories(${ONLYSDL} PRIVATE ${SDL2_INCLUDE_PATH})

target_link_libraries(${ONLYSDL} SDL2)
####################################################################
