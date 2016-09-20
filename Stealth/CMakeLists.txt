cmake_minimum_required(VERSION 3.2)
project(Stealth_C)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(ENGINE_SOURCE_FILES
    engine/src/entity/AIController.cpp
        engine/include/AIController.h
    engine/src/entity/Character.cpp
        engine/include/Character.h
    engine/src/entity/Controller.cpp
        engine/include/Controller.h
    engine/src/entity/GameObject.cpp
        engine/include/GameObject.h
    engine/src/entity/HumanController.cpp
        engine/include/HumanController.h
    engine/src/entity/Intention.cpp
        engine/include/Intention.h
        engine/include/enum/Button.h
        engine/include/enum/ButtonEvent.h
        engine/include/enum/ButtonState.h
        engine/include/geometry/Point3.h
    engine/src/helper/helper.cpp
        engine/include/helper.h
    engine/src/scene/Scene.cpp
        engine/include/Scene.h
    engine/src/service/InputManager.cpp
        engine/include/InputManager.h
    engine/src/entity/GameObjectFactory.cpp
        engine/include/GameObjectFactory.h engine/include/FactoryUtils.h engine/src/entity/Actor.cpp engine/include/Actor.h engine/src/component/Component.cpp engine/include/Component.h engine/src/component/RenderComponent.cpp engine/include/RenderComponent.h engine/src/component/SquareRenderComponent.cpp engine/include/SquareRenderComponent.h engine/src/component/Transform.cpp engine/include/Transform.h)


set(ENGINE_TEST_SOURCE_FILES
        engine/tests/TestGameObjectFactory.cpp)

set(SOURCE_FILES
        engine/src/service/Locator.cpp
        engine/include/Locator.h
        engine/src/application/GameApplication.cpp
        engine/include/GameApplication.h
    game/src/application/SdlApplication.cpp
        game/include/SdlApplication.h
    game/src/entity/Guard.cpp
        game/include/Guard.h
    game/src/entity/Spy.cpp
        game/include/Spy.h
    game/src/main.cpp
)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

#pkg_search_module(SDL2 REQUIRED SDL2)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

# for the engine
include_directories(engine/include)

# for the game
include_directories(.)  # just to have access to engine headers by including "engine/include/..."
include_directories(game/include)

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

add_executable(TestEngine ${ENGINE_TEST_SOURCE_FILES})
target_link_libraries(TestEngine
        engine
        UnitTest++
)