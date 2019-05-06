cmake_minimum_required(VERSION 3.13)
project(opengl)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_PREFIX_PATH "C:/Users/Viviane Alves/Documents/glew")
set(CMAKE_LIBRARY_PATH "C:/Users/Viviane Alves/Documents/glew/bin")
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})




add_executable(opengl glm.c lightposition.c camera.cpp main.cpp textures.cpp e1_loadandprint.cpp basic_shapes.cpp janela.cpp pc.cpp casaFlat.cpp casa.cpp quadrado.cpp teste.cpp casaExer.cpp escala.cpp rotacao.cpp braco.cpp moverEixo.cpp mochila.cpp mochila2.cpp transform.cpp cg2.cpp "cubo 3D.cpp" Exemplo3D.cpp helloTeapot.cpp teapotsgalore.cpp "Teapot Study.cpp" "Modelagem Mesa.cpp" "aviao de papel.cpp" linha.cpp load.cpp Cenario1.cpp lerObjetos.cpp banana.h lerBMP.cpp other.cpp textglaux.cpp carroTextura.cpp lerObjetoTextura.c)

target_link_libraries(opengl ${GLEW_LIBRARIES} -lGlaux -lOpenGL32 -lfreeGLUT -lwinmm -lgdi32 glu32.lib)