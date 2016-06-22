cmake_minimum_required(VERSION 3.2)
project(Stealth_Cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


# source files

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
        engine/src/renderer/Renderer.cpp
        engine/src/renderer/Renderer.h
        engine/src/enum/KeyDynamicState.h
        )

set(GAME_SOURCE_FILES
        engine/src/service/Locator.cpp
        engine/src/service/Locator.h
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


# Cmake packages


# DEBUG: if libgcc... of MingW is missing and you prefer building statically with standard libraries for dist
#Set Linker flags
#set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
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
SET(CMAKE_FIND_LIBRARY_SUFFIXES .a )
# IMPROVE: create or download FindGLFW.cmake somewhere
find_library(GLFW glfw3 ${PROJECT_SOURCE_DIR}/engine/libs)

#set(GLFW_LOCATION libs)
#find_package(GLFW)  # does not work with .a (detected in priority with MingW-w64)
message(WARNING "glfw lib path: ${GLFW}")
message(WARNING "glfw include dir: ${GLFW_INCLUDE_DIR}")
#add_definitions(-DGLFW_DLL) (if using .a, do not use DLL (crashes as can't detect libgcc... and glfw3.dll anyway)

set(GRAPHICS_RENDERER "OpenGL")

if (GRAPHICS_RENDERER STREQUAL "SDL2")
    find_package(SDL2)
    find_package(SDL2_image)
    find_package(SDL2_ttf)
    if (SDL_FOUND)
        include_directories(${SDL2_INCLUDE_DIR}
                ${SDL2_IMAGE_INCLUDE_DIR}
                ${SDL2_TTF_INCLUDE_DIR})
        add_definitions(-DWITH_SDL2)
    else (SDL_FOUND)
        message(WARNING "SDL2 not found! Fall back to OpenGL")
        # set fallback renderer
        set(GRAPHICS_RENDERER "OpenGL")
    endif (SDL_FOUND)
endif (GRAPHICS_RENDERER STREQUAL "SDL2")

if (GRAPHICS_RENDERER STREQUAL "OpenGL")
    find_package(OpenGL REQUIRED)
    if (OPENGL_FOUND)
        include_directories(${OpenGL_INCLUDE_DIRS})
        link_directories(${OpenGL_LIBRARY_DIRS})
        add_definitions(${OpenGL_DEFINITIONS})
        add_definitions(-DWITH_OPENGL)
    else (OPENGL_FOUND)
        message(SEND_ERROR "OPENGL not found!")
    endif (OPENGL_FOUND)
    message(WARNING ${OPENGL_LIBRARIES})

endif (GRAPHICS_RENDERER STREQUAL "OpenGL")


# target

add_library(engine ${ENGINE_SOURCE_FILES})
target_include_directories(engine PUBLIC engine/src engine/libs/include)

add_executable(StealthCpp ${GAME_SOURCE_FILES})
target_include_directories(StealthCpp PUBLIC game/src)


# linking

target_link_libraries(engine
        ${GLFW}
        ${OPENGL_LIBRARIES}
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
        )

target_link_libraries(StealthCpp
        engine
        )