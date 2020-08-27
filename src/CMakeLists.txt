set(source
    main.cpp
    ui/ui.cpp
    ffmpeg/ffmpeg_handler.cpp
)

add_library(ffmpeg_yt_downloader ${source})
if (MSVC)
    target_compile_options(ffmpeg_yt_downloader PRIVATE /W4)
else()
    target_compile_options(ffmpeg_yt_downloader PRIVATE -Wall -Wextra)
endif()

add_executable(yt_downloader ${source})
