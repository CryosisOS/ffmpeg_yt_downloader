########################################################################################################################
# To generate makefiles:
# cmake -B bin
#
# To build:
# cmake --build bin
########################################################################################################################

cmake_minimum_required(VERSION 3.17)
project(ffmpeg_yt_downloader)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

file(GLOB_RECURSE SRC_CPP "src/*.cpp")
add_executable(yt_downloader ${SRC_CPP})
