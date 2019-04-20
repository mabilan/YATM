# CMakeLists.txt


########################################################################
# Setup
########################################################################

cmake_minimum_required(VERSION 3.0)

project(yatm)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++17 -Wall -O3")
include_directories("include")


########################################################################
# Find SFML
########################################################################

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED system window graphics network audio)


########################################################################
# Main executable (yatm)
########################################################################

# Define main source which does not get included in the testing
set(SOURCE_MAIN source/main.cpp)

# Define all sources which may get included in the testing
set(SOURCE_FILES
    source/graphics.cpp
)

# Define sources and main executable
set(EXECUTABLE_NAME yatm)
add_executable(${EXECUTABLE_NAME} ${SOURCE_MAIN} ${SOURCE_FILES})

# Link SFML
include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
