cmake_minimum_required(VERSION 3.12)

project(cee_graphics)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_COMPILER clang)

file(GLOB SOURCES "src/*.c")

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 3.3 REQUIRED)

add_executable(build ${SOURCES})
target_link_libraries(build OpenGL::GL GLUT::GLUT glfw)

