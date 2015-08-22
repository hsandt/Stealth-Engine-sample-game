cmake_minimum_required(VERSION 3.2)
project(Stealth_C)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(ENGINE_SOURCE_FILES
    engine/src/entity/AIController.cpp
    engine/src/entity/AIController.h
    engine/src/entity/Character.cpp
    engine/src/entity/Character.h
    engine/src/entity/Controller.cpp
    engine/src/entity/Controller.h
    engine/src/entity/GameObject.cpp
    engine/src/entity/GameObject.h
    engine/src/entity/HumanController.cpp
    engine/src/entity/HumanController.h
    engine/src/entity/Intention.cpp
    engine/src/entity/Intention.h
    engine/src/enum/Button.h
    engine/src/enum/ButtonEvent.h
    engine/src/enum/ButtonState.h
    engine/src/geometry/Point3.h
    engine/src/helper/helper.cpp
    engine/src/helper/helper.h
    engine/src/scene/Scene.cpp
    engine/src/scene/Scene.h
    engine/src/service/InputManager.cpp
    engine/src/service/InputManager.h
)

set(SOURCE_FILES
    game/src/service/Locator.cpp
    game/src/service/Locator.h
    game/src/application/GameApplication.cpp
    game/src/application/GameApplication.h
    game/src/application/SdlApplication.cpp
    game/src/application/SdlApplication.h
    game/src/entity/Guard.cpp
    game/src/entity/Guard.h
    game/src/entity/Spy.cpp
    game/src/entity/Spy.h
    game/src/main.cpp
)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

#pkg_search_module(SDL2 REQUIRED SDL2)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(engine/src)
include_directories(game/src)

include_directories(${SDL2_INCLUDE_DIR}
                    ${SDL2_IMAGE_INCLUDE_DIR}
                    ${SDL2_TTF_INCLUDE_DIR})

add_library(engine ${ENGINE_SOURCE_FILES})

add_executable(StealthCpp ${SOURCE_FILES})

target_link_libraries(StealthCpp
        engine
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
)