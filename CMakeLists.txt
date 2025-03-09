cmake_minimum_required(VERSION 3.5.0)
project(lab3 VERSION 0.1.0 LANGUAGES C)

include_directories(${CMAKE_SOURCE_DIR}/libs)

add_library(my_obj_parser STATIC my_obj_parser.c) 
add_library(ListOfVertices STATIC lists/ListOfVertices.c) 
add_library(ListOfTextures STATIC lists/ListOfTextures.c) 
add_library(ListOfFaces STATIC lists/ListOfFaces.c) 
add_library(ListOfNormals STATIC lists/ListOfNormals.c) 
add_library(ObjParametersTuple STATIC ObjParametersTuple.c) 

add_executable(lab3 main.c)

find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(${GLUT_INCLUDE_DIRS})
include_directories(${OpenGL_INCLUDE_DIRS})

target_link_libraries(lab3 
${GLUT_LIBRARIES} OpenGL::GL GLU
my_obj_parser ListOfVertices ListOfTextures ListOfFaces ListOfNormals ObjParametersTuple
m)
