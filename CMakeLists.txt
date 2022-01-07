cmake_minimum_required(VERSION 3.15)
project(Frogger_test)

set(prefix "/usr/local/Cellar/sdl2/2.0.10")
set(exec_prefix "${prefix}")
set(libdir "${exec_prefix}/lib")
set(SDL2_PREFIX "/usr/local/Cellar/sdl2/2.0.10")
set(SDL2_EXEC_PREFIX "/usr/local/Cellar/sdl2/2.0.10")
set(SDL2_LIBDIR "${exec_prefix}/lib")
set(SDL2_INCLUDE_DIRS "${prefix}/include/SDL2")
set(SDL2_LIBRARIES "-L${SDL2_LIBDIR}  -lSDL2")
string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES)

set(CMAKE_CXX_STANDARD 14)

add_executable(Frogger_test main.cpp colission.cpp draw.cpp scores_file.cpp stages.cpp)

INCLUDE (FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
#PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} )
#TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES})
