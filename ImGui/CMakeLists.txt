cmake_minimum_required(VERSION 3.10)
project(ImGuiApp)

set(CMAKE_CXX_STANDARD 17)

# GLFW
find_package(glfw3 REQUIRED)

# ImGui sources
set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/imgui)

file(GLOB IMGUI_SRC
    ${IMGUI_DIR}/*.cpp
    ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)

add_executable(ImGuiApp
    main.cpp
    ${IMGUI_SRC}
)

target_include_directories(ImGuiApp PRIVATE
    ${IMGUI_DIR}
    ${IMGUI_DIR}/backends
)

# OpenGL
find_package(OpenGL REQUIRED)

target_link_libraries(ImGuiApp
    glfw
    OpenGL::GL
)