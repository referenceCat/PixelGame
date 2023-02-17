cmake_minimum_required(VERSION 3.5)
project(PixelGame)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        src/main.cpp
        src/graphics/GraphicEngine.cpp
        src/ui/graphics/GUIEngine.cpp
        src/logic/GameEngine.cpp
        src/logic/environment/Environment.cpp
        src/logic/environment/TestChunkGenerator.cpp
        src/logic/environment/ChunkGenerator.h
        src/logic/environment/Chunk.cpp src/logic/environment/constans.h src/ui/UIEventManager.cpp src/ui/UIEventManager.h src/graphics/constans.h src/stuff/Rectangle.cpp src/stuff/Rectangle.h)
add_executable(PixelGame ${SOURCE_FILES})

INCLUDE_DIRECTORIES(  /usr/local/Cellar/allegro/5.2.8.0_2/include )
LINK_DIRECTORIES(  /usr/local/Cellar/allegro/5.2.8.0_2/lib )

file(GLOB LIBRARIES "/usr/local/Cellar/allegro/5.2.8.0_2/lib/*.dylib")
message("LIBRARIES = ${LIBRARIES}")

TARGET_LINK_LIBRARIES(PixelGame  ${LIBRARIES})