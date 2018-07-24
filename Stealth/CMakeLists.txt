cmake_minimum_required(VERSION 3.2)
project(Stealth_Cpp CXX)


# Sub-projects

add_subdirectory(engine)


# Flags

# C++17
set(CMAKE_CXX_STANDARD 17)  # more compatibility, as g++ uses -std=c++17 and clang uses -std=c++1z
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-logical-op-parentheses")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z")

# Produce debugging information on debug, optimize on release
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

# If clang is used for compilation, force it to emit debug information for libstc++
# https://stackoverflow.com/questions/41745527/cannot-view-stdstring-when-compiled-with-clang
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG")


# Output paths

set(CMAKE_BINARY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/build-${CMAKE_BUILD_TYPE}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")  # executable output directory


# Input files

set(GAME_SOURCE_FILES
        game/include/application/StealthGameApplication.h
        game/include/component/CharacterMotor.h
        game/include/component/DynamicCharacterMotor.h
        game/include/controller/AIController.h
        game/include/controller/AIController.h
        game/include/controller/Controller.h
        game/include/controller/PlayerController.h
        game/include/entity/AICharacter.h
        game/include/entity/Character.h
        game/include/entity/DynamicCharacter.h
        game/include/entity/Guard.h
        game/include/entity/PlayerCharacter.h
        game/include/entity/PlayerDynamicCharacter.h
        game/include/entity/Spy.h
        game/src/application/StealthGameApplication.cpp
        game/src/component/CharacterMotor.cpp
        game/src/component/DynamicCharacterMotor.cpp
        game/src/controller/AIController.cpp
        game/src/controller/AIController.cpp
        game/src/controller/Controller.cpp
        game/src/controller/PlayerController.cpp
        game/src/entity/AICharacter.cpp
        game/src/entity/Character.cpp
        game/src/entity/DynamicCharacter.cpp
        game/src/entity/Guard.cpp
        game/src/entity/PlayerCharacter.cpp
        game/src/entity/PlayerDynamicCharacter.cpp
        game/src/entity/Spy.cpp
        game/src/main.cpp
        )


# Executable

add_executable(StealthCpp ${GAME_SOURCE_FILES})

target_include_directories(StealthCpp PUBLIC engine/include)
target_include_directories(StealthCpp PUBLIC game/include)

# Copy game-specific resources
message(STATUS "Copying game resources from ${PROJECT_SOURCE_DIR}...")
add_copy_command(StealthCpp "resources")
add_copy_command(StealthCpp "engine/resources")  # may cause conflicts with game resources if same name, consider subfolder "engine"

# Link to static engine library
target_link_libraries(StealthCpp
    engine
)

# Allow to run game executable with "make run"
add_custom_target(run
    COMMAND StealthCpp
    DEPENDS StealthCpp
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)
