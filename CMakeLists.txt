cmake_minimum_required(VERSION 3.2)
project(Stealth_C)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Stealth/src/engine/entity/AIController.cpp
    Stealth/src/engine/entity/AIController.h
    Stealth/src/engine/entity/Character.cpp
    Stealth/src/engine/entity/Character.h
    Stealth/src/engine/entity/Controller.cpp
    Stealth/src/engine/entity/Controller.h
    Stealth/src/engine/entity/GameObject.cpp
    Stealth/src/engine/entity/GameObject.h
    Stealth/src/engine/entity/HumanController.cpp
    Stealth/src/engine/entity/HumanController.h
    Stealth/src/engine/entity/Intention.cpp
    Stealth/src/engine/entity/Intention.h
    Stealth/src/engine/enum/Button.h
    Stealth/src/engine/enum/ButtonEvent.h
    Stealth/src/engine/enum/ButtonState.h
    Stealth/src/engine/geometry/Point3.h
    Stealth/src/engine/helper/helper.cpp
    Stealth/src/engine/helper/helper.h
    Stealth/src/engine/scene/Scene.cpp
    Stealth/src/engine/scene/Scene.h
    Stealth/src/engine/service/InputManager.cpp
    Stealth/src/engine/service/InputManager.h
    Stealth/src/game/service/Locator.cpp
    Stealth/src/game/service/Locator.h
    Stealth/src/game/application/GameApplication.cpp
    Stealth/src/game/application/GameApplication.h
    Stealth/src/game/application/SdlApplication.cpp
    Stealth/src/game/application/SdlApplication.h
    Stealth/src/game/entity/Guard.cpp
    Stealth/src/game/entity/Guard.h
    Stealth/src/game/entity/Spy.cpp
    Stealth/src/game/entity/Spy.h
    Stealth/src/game/main.cpp)

include_directories(Stealth/src)
include_directories(Stealth/src/engine)
include_directories(Stealth/src/game)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/Stealth/cmake")

#pkg_search_module(SDL2 REQUIRED SDL2)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIR}
                    ${SDL2_IMAGE_INCLUDE_DIR}
                    ${SDL2_TTF_INCLUDE_DIR})

add_executable(Stealth_C ${SOURCE_FILES})

target_link_libraries(Stealth_C ${SDL2_LIBRARY}
                             ${SDL2_IMAGE_LIBRARIES}
                             ${SDL2_TTF_LIBRARIES})