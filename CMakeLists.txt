cmake_minimum_required(VERSION 3.5)
project(PixelGame)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        src/main.cpp
        src/graphics/GraphicEngine.cpp
        src/logic/GameEngine.cpp
        src/logic/environment/Environment.cpp
        src/logic/environment/chunks/TestChunkGenerator.cpp
        src/logic/environment/chunks/ChunkGenerator.h
        src/logic/environment/chunks/Chunk.cpp
        src/logic/environment/constans.h
        src/ui/UIEngine.cpp
        src/ui/UIEngine.h
        src/graphics/constans.h
        src/stuff/Rectangle.cpp
        src/stuff/Rectangle.h
        src/logic/environment/static_objects/StaticObject.cpp
        src/logic/environment/static_objects/StaticObject.h
        src/logic/environment/static_objects/server/Server.cpp
        src/logic/environment/static_objects/server/Server.h src/ui/widgets/Widget.cpp src/ui/widgets/Widget.h src/ui/widgets/Button.cpp src/ui/widgets/Button.h src/ui/widgets/TextField.cpp src/ui/widgets/TextField.h)
add_executable(PixelGame ${SOURCE_FILES})

INCLUDE_DIRECTORIES(  /usr/local/Cellar/allegro/5.2.8.0_2/include )
LINK_DIRECTORIES(  /usr/local/Cellar/allegro/5.2.8.0_2/lib )

file(GLOB LIBRARIES "/usr/local/Cellar/allegro/5.2.8.0_2/lib/*.dylib")
message("LIBRARIES = ${LIBRARIES}")

TARGET_LINK_LIBRARIES(PixelGame  ${LIBRARIES})