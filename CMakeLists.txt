########################################################################################################################
# cmake -B bin
# cmake --build bin
########################################################################################################################

cmake_minimum_required(VERSION 3.19)
project(
    ffmpeg_yt_downloader
    VERSION 1.0
    DESCRIPTION "YT Video Downloader"
    LANGUAGES CXX
)

if (PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
    message(FATAL_ERROR
        "In source builds not supported, use `cmake -B bin`."
    )
endif()

# use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# executable and include dir
add_executable(downloader
    src/main.cpp
    src/ffmpeg/ffmpeg_handler.cpp
)
target_include_directories(downloader PRIVATE
    include/
)

# compiler warnings
if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra)
endif()
