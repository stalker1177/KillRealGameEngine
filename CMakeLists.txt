﻿cmake_minimum_required (VERSION 3.8)

project ("MyGameEngine")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

add_subdirectory(lib/glad/)
add_subdirectory(lib/imgui/)


add_subdirectory(src)

set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set_target_properties(glad imgui PROPERTIES FOLDER HiddenTargets)
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES FOLDER AppTools)