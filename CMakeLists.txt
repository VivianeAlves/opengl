cmake_minimum_required(VERSION 3.13)
project(opengl)

#set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_PREFIX_PATH "C:/Users/Viviane Alves/Documents/glew")
set(CMAKE_LIBRARY_PATH "C:/Users/Viviane Alves/Documents/glew/bin")
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

add_executable(opengl teapotsgalore.cpp trabalho2.cpp teste.c trackball.cpp primitive.cpp a2.cpp AndroidBot_Main.c AndroidBot_Activity.c AndroidBot_Display.c AndroidBot_Modeling.c skating.cpp main.cpp glm.c main1.cpp Teapot_Study.cpp lerBMP.cpp lightposition.c camera.cpp textures.cpp e1_loadandprint.cpp helloTeapot.cpp teapotsgalore.cpp Cenario1.cpp textglaux.cpp carroTextura.cpp lerObjetoTextura.c trabalho2.cpp luz.cpp wchar.h)

target_link_libraries(opengl ${GLEW_LIBRARIES} -lGlaux -lOpenGL32 -lfreeGLUT -lwinmm -lgdi32 glu32.lib)