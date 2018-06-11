cmake_minimum_required(VERSION 3.5.2)
project(game)

set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

include_directories(include)

set(SOURCE_FILES
                 ./src/Animations/Animation_effect.cpp
                 ./src/Animations/Animation.cpp
                 ./src/Animations/Standard_function_animation.cpp
                 ./src/Objects/Character_base.cpp
                 ./src/Objects/Luffy.cpp 
                 ./src/Objects/Object_base.cpp 
                 ./src/Objects/Object.cpp
                 ./src/Objects/Zoro.cpp 
                 ./src/States/Menu_state.cpp
                 ./src/States/Play_state.cpp
                 ./src/States/State_base.cpp
                 ./src/Game.cpp
                 ./src/Music_player.cpp
                 ./src/main.cpp 
                 ./src/Resource_manager.cpp
                 ./src/Utility.cpp)

set(RESOURCE_FILES font/arial.ttf)

find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIRS})
    link_libraries(${SFML_LIBRARIES})
endif()

add_executable(game ${SOURCE_FILES})

find_library(TGUI_LIB tgui)
target_link_libraries(game "${TGUI_LIB}")