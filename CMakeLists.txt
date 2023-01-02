cmake_minimum_required(VERSION 3.17)
project(Frogger)

set(CMAKE_CXX_STANDARD 14)

set(SDL2_INCLUDE_DIR C:/Conda/SDL2-devel-2.26.1-VC/SDL2/include)
set(SDL2_LIB_DIR C:/Conda/SDL2-devel-2.26.1-VC/SDL2/lib/x86)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

add_executable(Frogger main.cpp colission.cpp draw.cpp scores_file.cpp stages.cpp)

target_link_libraries(${PROJECT_NAME} SDL2main SDL2)
