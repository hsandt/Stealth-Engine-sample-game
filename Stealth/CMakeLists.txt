cmake_minimum_required(VERSION 3.2)
project(Stealth_Cpp CXX)


# Sub-projects

add_subdirectory(engine)


# Flags

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z")


# Output paths

set(CMAKE_BINARY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/build")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")  # executable output directory


# Input files

set(GAME_SOURCE_FILES
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
        game/src/application/StealthGameApplication.cpp game/include/application/StealthGameApplication.h)


# Executable

add_executable(StealthCpp ${GAME_SOURCE_FILES})

target_include_directories(StealthCpp PUBLIC engine/include)
target_include_directories(StealthCpp PUBLIC game/include)

# Link to static engine library
target_link_libraries(StealthCpp
    engine
)

# Scan through engine resources folder for updated files and copy any new or modified files to target resources folder
# http://qrikko.blogspot.fr/2016/05/cmake-and-how-to-copy-resources-during.html
message(STATUS "Copying resources from ${PROJECT_SOURCE_DIR}/engine/resources...")
file (GLOB_RECURSE resources "${PROJECT_SOURCE_DIR}/engine/resources/*.*")

foreach(resource ${resources})
    get_filename_component(filename ${resource} NAME)
    get_filename_component(dir ${resource} DIRECTORY)
    get_filename_component(dirname ${dir} NAME)

    # set output to the relative resource directory (including trailing "/")
    set (output "")
    while(NOT ${dirname} STREQUAL resources)
        get_filename_component(path_component ${dir} NAME)
        set (output "${path_component}/${output}")
        get_filename_component(dir ${dir} DIRECTORY)
        get_filename_component(dirname ${dir} NAME)
    endwhile()

    set(output "${CMAKE_BINARY_DIR}/bin/resources/${output}${filename}")

    # Add POST_BUILD command to copy resource file
    # http://stackoverflow.com/questions/13429656/cmake-how-to-copy-contents-of-a-directory-into-build-directory-after-make
    add_custom_command(
            TARGET StealthCpp POST_BUILD COMMAND
            ${CMAKE_COMMAND} -E copy_if_different
            ${resource}
            ${output}
            COMMENT "Moving updated engine resource-file '${filename}'"
    )
endforeach()

# TODO: copy resources for the game itself, reusing code above with a variable folder prefix
# that is first "engine" and then "game"

# Allow to run game executable with "make run"
add_custom_target(run
    COMMAND StealthCpp
    DEPENDS StealthCpp
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)
