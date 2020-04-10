cmake_minimum_required(VERSION 3.12)
project(OnlyAddProjectC C)

set(CMAKE_C_STANDARD 99)
find_package(SDL2 REQUIRED)

add_executable(OnlyAddProjectC main.c math_utils.c math_utils.h sdl_utils.c sdl_utils.h)
target_link_libraries(OnlyAddProjectC "m" ${SDL2_LIBRARIES})