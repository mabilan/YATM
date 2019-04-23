# CMakeLists.txt


########################################################################
# Setup
########################################################################

cmake_minimum_required(VERSION 3.0)

project(yatm)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++14 -Wall -O3")
include_directories(
    "include"
    "ext/imgui"
)


########################################################################
# Find SFML
########################################################################

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED system window graphics network audio)


########################################################################
# Find OpenGL
########################################################################
find_package(OpenGL REQUIRED)


########################################################################
# Main executable (yatm)
########################################################################

# Define main source which does not get included in the testing
set(SOURCE_MAIN source/main.cpp)

# Define external sources
set(EXT_SOURCE_FILES
    ext/imgui/imgui.cpp
    ext/imgui/imgui_draw.cpp
    ext/imgui/imgui_widgets.cpp
    ext/imgui/imgui-SFML.cpp
)

# Define all sources which may get included in the testing
set(SOURCE_FILES
    source/graphics.cpp
    source/category.cpp
    source/task.cpp
    source/task_grid.cpp
)

# Define sources and main executable
set(EXECUTABLE_NAME yatm)
add_executable(${EXECUTABLE_NAME} ${SOURCE_MAIN} ${SOURCE_FILES} ${EXT_SOURCE_FILES})

# Include SFML and OpenGL
include_directories(${SFML_INCLUDE_DIR})
include_directories(${OPENGL_INCLUDE_DIRS})

# Link SFML and OpenGL
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${OPENGL_LIBRARIES})
