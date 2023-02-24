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
        src/logic/environment/static_objects/server/Server.h src/ui/widgets/Widget.cpp src/ui/widgets/Widget.h src/ui/widgets/Button.cpp src/ui/widgets/Button.h src/ui/constans.h src/ui/widgets/Window.cpp src/ui/widgets/Window.h src/ui/widgets/Label.cpp src/ui/widgets/Label.h src/ui/widgets/Layout.cpp src/ui/widgets/Layout.h src/logic/ui_id_list.h src/ui/widgets/TextInput.cpp src/ui/widgets/TextInput.h src/ui/FunctionalKey.h src/ui/FunctionalKey.cpp)
add_executable(PixelGame ${SOURCE_FILES})

INCLUDE_DIRECTORIES(  /usr/local/Cellar/allegro/5.2.8.0_2/include )
LINK_DIRECTORIES(  /usr/local/Cellar/allegro/5.2.8.0_2/lib )

file(GLOB LIBRARIES "/usr/local/Cellar/allegro/5.2.8.0_2/lib/*.dylib")
message("LIBRARIES = ${LIBRARIES}")

TARGET_LINK_LIBRARIES(PixelGame  ${LIBRARIES})