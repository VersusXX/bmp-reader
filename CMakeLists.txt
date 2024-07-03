cmake_minimum_required(VERSION 3.28)
project(BMP_Reader C)

set(CMAKE_C_STANDARD 11)

add_executable(BMP_Reader main.c src/GeneralFunctions.c)

target_include_directories(BMP_Reader PRIVATE ${PROJECT_SOURCE_DIR}/include)
