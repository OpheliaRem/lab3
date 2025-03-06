cmake_minimum_required(VERSION 3.5.0) #Версия CMAKE
project(lab3 VERSION 0.1.0 LANGUAGES C) #Мой проект, его версия и выбранные языки.
#В моём случае это C. Если хочешь (а ты хочешь) использовать плюсы, то
#пиши project(lab3 VERSION 0.1.0 LANGUAGES C CXX)


#Далее идут написанные мной самим библиотеки. Если ты напишешь свою, то это будет образцом
add_library(my_obj_parser STATIC my_obj_parser.c) #Написанная мной либа
add_library(ListOfVertices STATIC lists/ListOfVertices.c) #Написанная мной либа
add_library(ListOfTextures STATIC lists/ListOfTextures.c) #Написанная мной либа
add_library(ListOfFaces STATIC lists/ListOfFaces.c) #Написанная мной либа
add_library(ListOfNormals STATIC lists/ListOfNormals.c) #Написанная мной либа
add_library(ObjParametersTuple STATIC ObjParametersTuple.c) #Написанная мной либа

add_executable(lab3 main.c) #Добавляем исполняемый файл

find_package(GLUT REQUIRED) #Ищем на компе установленный GLUT
find_package(OpenGL REQUIRED) #Ищем на компе установленный OpenGL

include_directories(${GLUT_INCLUDE_DIRS}) #Добавляем в команду #include директории GLUT
include_directories(${OpenGL_INCLUDE_DIRS}) #Добавляем в команду #include директории OpenGL

#Самая важная инструкция: подключаем все либы. Первый аргумент --- имя проекта. Далее через пробел
#полетели все наши библиотеки. Тебе надо только ${GLUT_LIBRARIES} OpenGL::GL. Если понадобится
#либа glu, допишешь GLU. Также возможно тебе понадобится математическая библиотека math.h --- m.
target_link_libraries(lab3 
${GLUT_LIBRARIES} OpenGL::GL GLU
my_obj_parser ListOfVertices ListOfTextures ListOfFaces ListOfNormals ObjParametersTuple
m)
