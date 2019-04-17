cmake_minimum_required(VERSION 3.4)

project(YATM-backend CXX)

add_library(task_lib include/task.hpp)
set_target_properties(task_lib PROPERTIES LINKER_LANGUAGE CXX)

add_executable(test src/main.cpp src/task.cpp)
target_link_libraries(test task_lib)