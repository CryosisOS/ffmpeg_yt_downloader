########################################################################################################################
# To generate makefiles:
# cmake -B bin
#
# To build:
# cmake --build bin
########################################################################################################################
cmake_minimum_required(VERSION 3.17)
project(
    ffmpeg_yt_downloader
    VERSION 1.0
    DESCRIPTION "YT Video Downloader"
    LANGUAGES CXX
)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED true)
    set(CMAKE_CXX_EXTENSIONS off)
endif()

include_directories(include)
add_subdirectory(src)
