cmake_minimum_required(VERSION 3.10)
project(CGame)

set(CMAKE_CXX_STANDARD 11)

add_executable(CGame main.cpp)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR})
add_executable(C__SDLTEST main.cpp)

find_package(SDL2 REQUIRED)

find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIR} //Include directories tar directoriesen till dina packages
${SDL2_IMAGE_INCLUDE_DIR} //SDL_IMAGE_INCLUDE_DIR är som alla INCLUDE_DIR här en path till SDL2
${SDL2TTF_INCLUDE_DIR})
target_link_libraries(CGame ${SDL2_LIBRARY}
${SDL2_IMAGE_LIBRARIES}
${SDL2_TTF_LIBRARY})

