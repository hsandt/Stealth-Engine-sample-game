cmake_minimum_required(VERSION 2.8.4)
project(Stealth)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
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
    Stealth/src/engine/service/Locator.cpp
    Stealth/src/engine/service/Locator.h
    Stealth/src/game/application/GameApplication.cpp
    Stealth/src/game/application/GameApplication.h
    Stealth/src/game/application/SdlApplication.cpp
    Stealth/src/game/application/SdlApplication.h
    Stealth/src/game/entity/Guard.cpp
    Stealth/src/game/entity/Guard.h
    Stealth/src/game/entity/Spy.cpp
    Stealth/src/game/entity/Spy.h
    Stealth/src/game/main.cpp)

include_directories(Stealth/src/engine)
include_directories(Stealth/src/engine/entity)
include_directories(Stealth/src/engine/enum)
include_directories(Stealth/src/engine/geometry)
include_directories(Stealth/src/engine/helper)
include_directories(Stealth/src/engine/scene)
include_directories(Stealth/src/engine/service)
include_directories(Stealth/src/game)
include_directories(Stealth/src/game/application)
include_directories(Stealth/src/game/entity)

add_executable(Stealth ${SOURCE_FILES})