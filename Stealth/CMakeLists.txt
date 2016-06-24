cmake_minimum_required(VERSION 3.2)
project(Stealth_Cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


# source files

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
        engine/src/renderer/Renderer.cpp
        engine/include/Renderer.h
        engine/include/enum/KeyDynamicState.h
        engine/include/utils/Color.cpp engine/include/utils/Color.h)

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
        engine/tests/testdummy.cpp
        engine/tests/testmain.cpp
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
SET(CMAKE_FIND_LIBRARY_SUFFIXES .dll)

message(WARNING "v1")

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
include_directories(engine/libs/include)
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
        ${OPENGL_LIBRARIES}
        ${GLEW}
        ${GLFW}
        )

target_link_libraries(test_engine
        engine
        )

target_link_libraries(StealthCpp
        engine
        )


# output path

set_target_properties( engine
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/lib"
        )

set_target_properties( StealthCpp
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin"
        )