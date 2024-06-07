cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(OpenGLProject)

# Especificar la versión de C++
set(CMAKE_CXX_STANDARD 11)

# Agregar ejecutable
add_executable(OpenGLProject main.cpp)

# Vincular bibliotecas
target_link_libraries(OpenGLProject GL GLU glut)
