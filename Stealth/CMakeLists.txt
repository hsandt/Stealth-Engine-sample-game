cmake_minimum_required(VERSION 3.2)
project(Stealth_Cpp)

# TODO: require clang if needed
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z")

set(CMAKE_BINARY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/build")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")  # executable output directory
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")  # static libraries output directory
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")  # dynamic libraries output directory (unused)

set(ENGINE_SOURCE_FILES
        engine/src/application/ApplicationContainer.cpp
        engine/include/application/ApplicationContainer.h
        engine/src/service/Locator.cpp
        engine/include/service/Locator.h
        engine/src/entity/GameObject.cpp
        engine/include/entity/GameObject.h
        engine/include/input/Key.h
        engine/include/input/KeyEvent.h
        engine/include/input/ButtonState.h
        engine/include/input/KeyStates.h
        engine/include/geometry/Vector2.h
        engine/include/geometry/Vector3.cpp
        engine/include/geometry/Vector3.h
        engine/src/utils/Color.cpp
        engine/include/utils/Color.h
        engine/include/utils/infix_iterator.h
        engine/src/scene/Scene.cpp
        engine/include/scene/Scene.h
        engine/src/service/InputManager.cpp
        engine/include/service/InputManager.h
        engine/src/factory/Factory.cpp
        engine/include/factory/Factory.h
        engine/include/factory/FactoryUtils.h
        engine/src/entity/Actor.cpp
        engine/include/entity/Actor.h
        engine/src/component/Component.cpp
        engine/include/component/Component.h
        engine/src/component/ActorComponent.cpp
        engine/include/component/ActorComponent.h
        engine/src/component/RenderComponent.cpp
        engine/include/component/RenderComponent.h
        engine/src/component/SquareRenderComponent.cpp
        engine/include/component/SquareRenderComponent.h
        engine/src/component/Transform.cpp
        engine/include/component/Transform.h
        engine/src/renderer/Renderer.cpp
        engine/include/renderer/Renderer.h
        engine/src/object/Object.cpp
        engine/include/object/Object.h
        engine/src/factory/GameObjectCreator.cpp
        engine/include/factory/GameObjectCreator.h
        engine/src/factory/ComponentCreator.cpp
        engine/include/factory/ComponentCreator.h
#        engine/include/GameObject_TImpl.cpp
        engine/src/renderer/ShaderUtils.cpp
        engine/include/renderer/ShaderUtils.h
        engine/src/component/InputComponent.cpp
        engine/include/component/InputComponent.h
        engine/include/input/KeyBinding.h
        engine/include/input/KeyData.h
        engine/include/input/AxisKeyBinding.h
        engine/include/utils/MathUtil.h
#        engine/include/debug/Logger.tpp
        engine/include/debug/Logger.h
        engine/include/utils/TraitsUtil.h)

set(GAME_SOURCE_FILES
        game/src/application/GameApplication.cpp
        game/include/application/GameApplication.h
        game/src/controller/AIController.cpp
        game/include/controller/AIController.h
        game/src/controller/Controller.cpp
        game/include/controller/Controller.h
        game/src/controller/PlayerController.cpp
        game/include/controller/PlayerController.h
        game/src/controller/AIController.cpp
        game/include/controller/AIController.h
        game/src/entity/Character.cpp
        game/include/entity/Character.h
        game/src/entity/PlayerCharacter.cpp
        game/include/entity/PlayerCharacter.h
        game/src/entity/AICharacter.cpp
        game/include/entity/AICharacter.h
        game/src/entity/Guard.cpp
        game/include/entity/Guard.h
        game/src/entity/Spy.cpp
        game/include/entity/Spy.h
        game/src/main.cpp
        )

set(TEST_ENGINE_SOURCE_FILES
        engine/tests/catch.hpp
        engine/tests/catch_with_main.hpp
        engine/tests/testmain.cpp
        # All actual test cpp files added from here
        engine/tests/geometry/testvec2.cpp
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
SET(CMAKE_FIND_LIBRARY_SUFFIXES .dll .so .lib)

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
message(STATUS "Box2D lib path: ${Box2D}")

# Rendering

# FindOpenGL.cmake is required to find_package! (on Linux)
find_package(OpenGL REQUIRED)
if (OPENGL_FOUND)
    include_directories(${OpenGL_INCLUDE_DIRS})
    link_directories(${OpenGL_LIBRARY_DIRS})
    add_definitions(${OpenGL_DEFINITIONS})
else (OPENGL_FOUND)
    message(SEND_ERROR "OPENGL not found!")
endif (OPENGL_FOUND)
message(STATUS OpenGL gl lib: ${OPENGL_gl_LIBRARY})
message(STATUS OpenGL glu lib: ${OPENGL_glu_LIBRARY})
message(STATUS OpenGL xmesa lib: ${OPENGL_xmesa_LIBRARY})
message(STATUS OpenGL include dir: ${OPENGL_INCLUDE_DIR})
message(STATUS OpenGL libs: ${OPENGL_LIBRARIES})

# LINUX: I installed libGLEW.so from GLEW 2.0 with some API changes, check compatibility!

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
find_library(GLEW GLEW ${PROJECT_SOURCE_DIR}/engine/libs)  # static??
if (NOT GLEW_FOUND)
    find_library(GLEW glew32d ${PROJECT_SOURCE_DIR}/engine/libs)  # static??
endif(NOT GLEW_FOUND)
#find_library(GLEW glew32 ${PROJECT_SOURCE_DIR}/engine/libs)
#add_definitions(-DGLEW_STATIC)
#add_definitions(-DGLEW_MX)  # single context enough for 1 window
message(STATUS "GLEW lib path: ${GLEW}")


# IMPROVE: create or download FindGLFW.cmake somewhere
# VERSION NOTES: Windows glfw3.dll is GLFW 3.2.0, libglfw.so.3.2 is GLFW 3.2.1 (API compatible)
find_library(GLFW glfw ${PROJECT_SOURCE_DIR}/engine/libs)
#set(GLFW_LOCATION libs)
#find_package(GLFW)  # does not work with .a (detected in priority with MingW-w64)
message(STATUS "glfw lib path: ${GLFW}")
message(STATUS "glfw libs: ${GLFW_LIBRARIES}")
message(STATUS "glfw include dir: ${GLFW_INCLUDE_DIR}")
#add_definitions(-DGLFW_DLL) (if using .a, do not use DLL (crashes as can't detect libgcc... and glfw3.dll anyway)




# target

# DEBUG: in case target_include_directories does not work
include_directories(engine/include engine/libs/include)
include_directories(engine/tests)  # not performant, really need to isolate target include directories
include_directories(game/include)

add_library(engine ${ENGINE_SOURCE_FILES})
#target_include_directories(engine PUBLIC engine/include PRIVATE engine/libs/include)

add_executable(test_engine ${TEST_ENGINE_SOURCE_FILES})
#target_include_directories(engine_test PUBLIC engine/tests)  # does not seem to work, need full path?

add_executable(StealthCpp ${GAME_SOURCE_FILES})
#target_include_directories(StealthCpp PUBLIC game/src)  # does not seem to work, need full path?


# http://qrikko.blogspot.fr/2016/05/cmake-and-how-to-copy-resources-during.html
# Scan through resource folder for updated files and copy if none existing or changed
message(WARNING ${PROJECT_SOURCE_DIR})

file (GLOB_RECURSE resources "${PROJECT_SOURCE_DIR}/engine/resources/*.*")
foreach(resource ${resources})
get_filename_component(filename ${resource} NAME)
get_filename_component(dir ${resource} DIRECTORY)
get_filename_component(dirname ${dir} NAME)

set (output "")

while(NOT ${dirname} STREQUAL resources)
get_filename_component(path_component ${dir} NAME)
set (output "${path_component}/${output}")
get_filename_component(dir ${dir} DIRECTORY)
get_filename_component(dirname ${dir} NAME)
endwhile()

set(output "${CMAKE_BINARY_DIR}/bin/resources/${output}/${filename}")

# custom command with OUTPUT suggested by the same website does not work
#add_custom_command(
#COMMENT "Moving updated resource-file '${filename}'"
#OUTPUT ${output}
#DEPENDS ${resource}
#COMMAND ${CMAKE_COMMAND} -E copy_if_different
#${resource}
#${output}
#)
#add_custom_target(${filename} ALL DEPENDS ${resource} ${output})

# POST_BUILD command works
# http://stackoverflow.com/questions/13429656/cmake-how-to-copy-contents-of-a-directory-into-build-directory-after-make
add_custom_command(
    TARGET StealthCpp POST_BUILD COMMAND
    ${CMAKE_COMMAND} -E copy_if_different
    ${resource}
    ${output}
    COMMENT "Moving updated resource-file '${filename}'"
)

endforeach()


# linking

target_link_libraries(engine
#        ${Box2D}
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
