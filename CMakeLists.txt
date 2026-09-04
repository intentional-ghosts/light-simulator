cmake_minimum_required(VERSION 3.20)
project(light_simulator C CXX)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ---- GLFW: prebuilt static lib (libglfw3.a), no source/CMakeLists available ----
add_library(glfw STATIC IMPORTED)
set_target_properties(glfw PROPERTIES
    IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/external_includes/lib/libglfw3.a
    INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}/external_includes/GLFW
)

# ---- glad: no CMakeLists.txt of its own — build it as a small static lib ----
add_library(glad STATIC external_includes/glad/glad.c)
target_include_directories(glad PUBLIC external_includes)

# ---- nativefiledialog-extended: has its own CMakeLists.txt ----
set(NFD_BUILD_TESTS OFF CACHE BOOL "" FORCE)
add_subdirectory(external_includes/nativefiledialog-extended)

# ---- Dear ImGui: no CMakeLists.txt, list sources manually ----
set(IMGUI_ROOT gui/dear_imgui/imgui-master)

add_library(imgui STATIC
    ${IMGUI_ROOT}/imgui.cpp
    ${IMGUI_ROOT}/imgui_draw.cpp
    ${IMGUI_ROOT}/imgui_tables.cpp
    ${IMGUI_ROOT}/imgui_widgets.cpp
    ${IMGUI_ROOT}/imgui_demo.cpp
    ${IMGUI_ROOT}/backends/imgui_impl_glfw.cpp
    ${IMGUI_ROOT}/backends/imgui_impl_opengl3.cpp
)

target_include_directories(imgui PUBLIC
    ${IMGUI_ROOT}
    ${IMGUI_ROOT}/backends
)

target_include_directories(imgui PRIVATE
    external_includes
)

# ---- Your app ----
add_executable( light_simulator
    main.cpp
    core/window.cpp
    core/input.cpp
    core/shader.cpp
    core/texture.cpp
    core/renderer.cpp
    core/scene_manager.cpp
    core/primitives.cpp
    gui/gui.cpp
)

target_include_directories( light_simulator PRIVATE
    core
    gui
    external_includes
    external_includes/glm
    ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries( light_simulator PRIVATE
    glfw
    glad
    nfd
    imgui
    opengl32
    gdi32
)

target_link_options( light_simulator PRIVATE -mconsole -Wl,-e,mainCRTStartup)