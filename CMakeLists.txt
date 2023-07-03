# CMake entry point
cmake_minimum_required (VERSION 3.0)
project (TP-OPENGL-TSI)

find_package(OpenGL REQUIRED)

# Compile external dependencies
add_subdirectory (external)

# On Visual 2005 and above, this module can set the debug working directory
cmake_policy(SET CMP0026 OLD)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/external/rpavlik-cmake-modules-fe2273")
include(CreateLaunchers)
include(MSVCMultipleProcessCompile) # /MP

include_directories(
        external/AntTweakBar-1.16/include/
        external/glfw-3.1.2/include/
        external/glm-0.9.7.1/
        external/glew-1.13.0/include/
        external/assimp-3.0.1270/include/
        external/bullet-2.81-rev2613/src/
        external/imgui-master/backends/
        external/imgui-master/

        .
)

set(ALL_LIBS
        ${OPENGL_LIBRARY}
        glfw
        GLEW_1130
)

add_definitions(
        -DTW_STATIC
        -DTW_NO_LIB_PRAGMA
        -DTW_NO_DIRECT3D
        -DGLEW_STATIC
        -D_CRT_SECURE_NO_WARNINGS
)


# Tutorial 17
add_executable(projet1
        projet1/projet1.cpp
        projet1/shader.cpp
        projet1/shader.hpp
        projet1/texture.cpp
        projet1/texture.hpp
        projet1/objloader.cpp
        projet1/objloader.hpp
        projet1/vboindexer.cpp
        projet1/vboindexer.hpp

        projet1/controls.cpp
        projet1/controls.hpp

        projet1/importutils.cpp
        projet1/importutils.h

        projet1/StandardShading.vertexshader
        projet1/StandardShading.fragmentshader

)
target_link_libraries(projet1
        ${ALL_LIBS}
        ANTTWEAKBAR_116_OGLCORE_GLFW
)

set_target_properties(projet1 PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/projet1/")
create_target_launcher(projet1 WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/projet1/")

add_custom_command(
   TARGET projet1 POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/projet1${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/projet1/"
)


