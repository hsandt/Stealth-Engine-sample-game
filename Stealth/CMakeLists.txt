cmake_minimum_required(VERSION 3.2)
project(Stealth_Cpp)

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
    engine/src/entity/GameObjectFactory.cpp
        engine/include/GameObjectFactory.h
engine/include/FactoryUtils.h
engine/src/entity/Actor.cpp
engine/include/Actor.h
engine/src/component/Component.cpp
engine/include/Component.h
engine/src/component/RenderComponent.cpp
engine/include/RenderComponent.h
engine/src/component/SquareRenderComponent.cpp
engine/include/SquareRenderComponent.h
engine/src/component/Transform.cpp
engine/include/Transform.h
)

set(GAME_SOURCE_FILES
        engine/src/service/Locator.cpp
        engine/include/Locator.h
        game/src/application/GameApplication.cpp
        game/src/application/GameApplication.h
        game/src/application/ApplicationContainer.cpp
        game/src/application/ApplicationContainer.h
        game/src/entity/Guard.cpp
        game/src/entity/Guard.h
        game/src/entity/Spy.cpp
        game/src/entity/Spy.h
        game/src/main.cpp
        )

set(TEST_ENGINE_SOURCE_FILES
        engine/tests/catch.hpp
        engine/tests/catch_with_main.hpp
        engine/tests/testmain.cpp
        engine/tests/geometry/testvec3.cpp
        )


# Cmake packages


# DEBUG: if libgcc... of MingW is missing and you prefer building statically with standard libraries for dist
# libraries that need to be copied as DLL or statically compiled:
# libgcc
# libstdc++
# libwinpthread-1.dll

#Set Linker flags
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
#set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static-libwinpthread")

# or
#> if (MINGW)
#>>     set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -static-libgcc")
#>>     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc
#>> -static-libstdc++")
#>>     set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS
#>> "${CMAKE_SHARED_LIBRARY_LINK_C_FLAGS} -static-libgcc -s")
#>>     set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS
#>> "${CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS} -static-libgcc -static-libstdc++
#>> -s")
#>> endif()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
#SET(CMAKE_FIND_LIBRARY_SUFFIXES .a .lib)
#SET(CMAKE_FIND_LIBRARY_SUFFIXES .dll)
SET(CMAKE_FIND_LIBRARY_SUFFIXES .dll .lib)

message(WARNING "v1.1")

# Physics

#SET(BOX2D_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/engine/libs/include)
#
#find_package(Box2D)
#if (BOX2D_FOUND)
#    include_directories(${BOX2D_INCLUDE_DIR})
#else (BOX2D_FOUND)
#    message(SEND_ERROR "BOX2D not found!")
#endif (BOX2D_FOUND)
#message(WARNING ${BOX2D_INCLUDE_DIR})

# Box2D: static linking
find_library(Box2D Box2D ${PROJECT_SOURCE_DIR}/engine/libs)
message(WARNING "Box2D lib path: ${Box2D}")

# Rendering

find_package(OpenGL REQUIRED)
if (OPENGL_FOUND)
    include_directories(${OpenGL_INCLUDE_DIRS})
    link_directories(${OpenGL_LIBRARY_DIRS})
    add_definitions(${OpenGL_DEFINITIONS})
else (OPENGL_FOUND)
    message(SEND_ERROR "OPENGL not found!")
endif (OPENGL_FOUND)
message(WARNING ${OPENGL_LIBRARIES})

#find_package(GLEW REQUIRED HINTS "${PROJECT_SOURCE_DIR}/libs")
#find_package(GLEW REQUIRED)
#if (GLEW_FOUND)
#    include_directories($(GLEW_INCLUDE_DIR))
#    link_directories(${GLEW_LIBRARY})
#    add_definitions(-DGLEW_STATIC)
#    add_definitions(-DGLEW_MX)
#endif()

# non-static causes undefined reference to `__imp___glewGenVertexArrays' and so one
# static cause: Warning: corrupt .drectve at end of def file
# glew32s.lib(tmp/glew_static/Release/x64/glew.obj):(.text$mn+0xd): undefined reference to `__imp_wglGetProcAddress'
#find_library(GLEW glew32s ${PROJECT_SOURCE_DIR}/engine/libs)  # static
find_library(GLEW glew32d ${PROJECT_SOURCE_DIR}/engine/libs)  # static??
#find_library(GLEW glew ${PROJECT_SOURCE_DIR}/engine/libs)  # static??
#find_library(GLEW glew32 ${PROJECT_SOURCE_DIR}/engine/libs)
#add_definitions(-DGLEW_STATIC)
#add_definitions(-DGLEW_MX)  # single context enough for 1 window
message(WARNING "GLEW lib path: ${GLEW}")


# IMPROVE: create or download FindGLFW.cmake somewhere
find_library(GLFW glfw3 ${PROJECT_SOURCE_DIR}/engine/libs)
#set(GLFW_LOCATION libs)
#find_package(GLFW)  # does not work with .a (detected in priority with MingW-w64)
message(WARNING "glfw lib path: ${GLFW}")
message(WARNING "glfw include dir: ${GLFW_INCLUDE_DIR}")
#add_definitions(-DGLFW_DLL) (if using .a, do not use DLL (crashes as can't detect libgcc... and glfw3.dll anyway)




# target

# DEUBG: in case target_include_directories does not work
include_directories(engine/include engine/libs/include)
include_directories(engine/tests)  # not performant, really need to isolate target include directories
include_directories(game/src)

add_library(engine ${ENGINE_SOURCE_FILES})
#target_include_directories(engine PUBLIC engine/include PRIVATE engine/libs/include)

add_executable(test_engine ${TEST_ENGINE_SOURCE_FILES})
#target_include_directories(engine_test PUBLIC engine/tests)  # does not seem to work, need full path?

add_executable(StealthCpp ${GAME_SOURCE_FILES})
#target_include_directories(StealthCpp PUBLIC game/src)  # does not seem to work, need full path?


# linking

target_link_libraries(engine
        ${Box2D}
        ${OPENGL_LIBRARIES}
        ${GLEW}
        ${GLFW}
        )

target_link_libraries(test_engine
        engine
        )

target_link_libraries(StealthCpp
        engine
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
)
