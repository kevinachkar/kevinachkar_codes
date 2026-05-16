cmake_minimum_required(VERSION 3.10)

project(imgui_test)

set(CMAKE_CXX_STANDARD 17)

set(IMGUI_DIR imgui)

file(GLOB IMGUI_SRC
    ${IMGUI_DIR}/*.cpp
    ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)

include_directories(
    ${IMGUI_DIR}
    ${IMGUI_DIR}/backends
)

add_subdirectory(glfw)

add_executable(imgui_test
    main.cpp
    ${IMGUI_SRC}
)

target_link_libraries(imgui_test glfw opengl32)