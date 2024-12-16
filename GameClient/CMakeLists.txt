cmake_minimum_required(VERSION 3.5.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

# Include directories for SFML
include_directories("C:/SFML-2.6.2/include")

# Link directories for SFML 
link_directories("C:/SFML-2.6.2/lib")


project(GameClient VERSION 0.1.0 LANGUAGES C CXX)
file(GLOB_RECURSE SRC_FILES "src/*.cpp")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
add_executable(GameClient ${SRC_FILES})
target_precompile_headers(GameClient PRIVATE "${CMAKE_SOURCE_DIR}/src/pch.h")

# Add SFML static preprocessor define
target_compile_definitions(GameClient PRIVATE SFML_STATIC)

# Link SFML libraries 
target_link_libraries(GameClient debug sfml-main-d sfml-graphics-s-d sfml-window-s-d sfml-system-s-d sfml-network-s-d sfml-audio-s-d)
target_link_libraries(GameClient optimized sfml-main sfml-graphics-s sfml-window-s sfml-system-s sfml-network-s sfml-audio-s) 
target_link_libraries(GameClient opengl32 freetype winmm gdi32 flac ogg vorbis vorbisfile vorbisenc openal32) 
# Add dependencies for SFML (for static linking) 

