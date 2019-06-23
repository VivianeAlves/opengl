//// Created by Viviane Alves on 04/05/2019.
////
//
//// Textura.cpp - Isabel H. Manssour
//// Um programa OpenGL que exemplifica a visualiza��o
//// de objetos 3D com mapeamento de textura.
//// Este c�digo est� baseado nos exemplos dispon�veis no livro
//// "OpenGL SuperBible", 2nd Edition, de Richard S. e Wright Jr.
//
//#include <gl/glut.h>
//#include <stdio.h>
//#include <GL/glaux.h>
//#include "basket.h"
//#include "prato.h"
//#include "basket1.h"
//#include "bandeja2.h"
//
////Fun��o para Carregar uma imagem .BMP
//AUX_RGBImageRec *LoadBMP(char *Filename) {
//    FILE *File = NULL;
//    if (!Filename) {
//        return NULL;
//    }
//    File = fopen(Filename, "r");
//    if (File)    // Se o arquivo existe
//    {
//        fclose(File);
//        return auxDIBImageLoad(Filename);//Retorna a imagem
//    }
//    return NULL;
//}
//
//// Vari�veis globais
//GLfloat angle, fAspect, rotX, rotY, obsZ;
//GLuint idTextura;
//AUX_RGBImageRec *imagemTextura;
//
//// Fun��o respons�vel pela especifica��o dos par�metros de ilumina��o
//void DefineIluminacao(void) {
//    GLfloat luzAmbiente[4] = {0.2, 0.2, 0.2, 1.0};
//    GLfloat luzDifusa[4] = {0.7, 0.7, 0.7, 1.0};       // "cor"
//    GLfloat luzEspecular[4] = {1.0, 1.0, 1.0, 1.0};// "brilho"
//    GLfloat posicaoLuz[4] = {0.0, -40.0, 0.0, 1.0};
//
//    // Capacidade de brilho do material
//    GLfloat especularidade[4] = {1.0, 1.0, 1.0, 1.0};
//    GLint especMaterial = 60;
//
//    // Define a reflet�ncia do material
//    glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);
//    // Define a concentra��o do brilho
//    glMateriali(GL_FRONT, GL_SHININESS, especMaterial);
//
//    // Ativa o uso da luz ambiente
//    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);
//
//    // Define os par�metros da luz de n�mero 0
//    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
//    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
//    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
//    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);
//
//    // Habilita o modelo de coloriza��o de Gouraud
//    glShadeModel(GL_SMOOTH);
//}
//
//// Fun��o callback chamada para fazer o desenho
//void Desenha(void) {
//    // Limpa a janela e o depth buffer
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//    glEnableClientState(GL_VERTEX_ARRAY); //enable vertex array
//    glEnableClientState(GL_NORMAL_ARRAY); //enable normal array
//    glEnableClientState(GL_TEXTURE_COORD_ARRAY); //enable texcoord array
//
//    glVertexPointer(3, GL_FLOAT, 0, bandeja2Verts);
//    glNormalPointer(GL_FLOAT, 0, bandeja2Normals);
//    glTexCoordPointer(2, GL_FLOAT, 0, bandeja2TexCoords);
//    glDrawArrays(GL_TRIANGLES, 0, bandeja2NumVerts);
//
//
////
////    float vertices1[] = {
////            // f 231/242/231 132/142/132 131/141/131
////            0.172233487787643, -0.0717437751698985, 0.228589675538813,
////            0.176742968653347, -0.0680393472738536, 0.2284149434494,
////            0.167979223684599, -0.0670168837233226, 0.24286384937854};
////
////            float texturas1[]={
////                0.077604, 0.136185,
////                        0.074129, 0.144479,
////                        0.068596, 0.115074
////            };
////
////            glEnableClientState(GL_VERTEX_ARRAY);
////            glVertexPointer(3, GL_FLOAT, 0, vertices1);
////            glEnableClientState(GL_TEXTURE_COORD_ARRAY);
////            glTexCoordPointer(2, GL_FLOAT, 0, texturas1);
////            glDrawArrays(GL_TRIANGLES, 0, 3);
//
//
//
//////exemplo externo
////// using vertex arrays
////    GLfloat vertices[] = {-4.0f,-4.0f,0.0f, 4.0f,-4.0f,0.0f, 4.0f,4.0f,0.0f, -4.0f,4.0f,0.0f};
////    GLfloat texcoords[] = {0.0f,0.0f, 1.0f,0.0f, 1.0f,1.0f, 0.0f,1.0f};
////    glEnableClientState(GL_VERTEX_ARRAY);
////    glVertexPointer(3, GL_FLOAT, 0, vertices);
////    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
////    glTexCoordPointer(2, GL_FLOAT, 0, texcoords);
////    glDrawArrays(GL_QUADS, 0, 4);
////    glDisableClientState(GL_VERTEX_ARRAY);
////    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
////    //exemplo externo
////    // using imeddiate mode
////    glBegin(GL_QUADS);
////    glTexCoord2f(0.0f, 0.0f);
////    glVertex3f(-4.0f, -4.0f, 0.0f);
////    glTexCoord2f(1.0f, 0.0f);
////    glVertex3f(4.0f, -4.0f, 0.0f);
////    glTexCoord2f(1.0f, 1.0f);
////    glVertex3f(4.0f, 4.0f, 0.0f);
////    glTexCoord2f(0.0f, 1.0f);
////    glVertex3f(-4.0f, 4.0f, 0.0f);
////    glEnd();
//
//
////glBegin(GL_TRIANGLES);
////
////glEnd();
//
////    // Desenha um cubo no qual a textura � aplicada
////    glBegin ( GL_QUADS );
////    // Face frontal
////    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
////    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
////    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
////    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
////    // Face posterior
////    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
////    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
////    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
////    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
////    // Face superior
////    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
////    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
////    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
////    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
////    // Face inferior
////    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
////    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
////    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
////    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
////    // Face lateral direita
////    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
////    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
////    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
////    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
////    // Face lateral esquerda
////    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
////    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
////    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
////    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
////    glEnd();
//
//            glutSwapBuffers();
//    }
//
//// Fun��o usada para especificar a posi��o do observador virtual
//    void PosicionaObservador(void) {
//        // Especifica sistema de coordenadas do modelo
//        glMatrixMode(GL_MODELVIEW);
//        // Inicializa sistema de coordenadas do modelo
//        glLoadIdentity();
//        DefineIluminacao();
//        // Especifica posi��o do observador e do alvo
//        glTranslatef(0, 0, -obsZ);
//        glRotatef(rotX, 1, 0, 0);
//        glRotatef(rotY, 0, 1, 0);
//    }
//
//// Inicializa par�metros de rendering
//    void Inicializa(void) {
//        // Define a cor de fundo da janela de visualiza��o como preta
//        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//
//        // Habilita a defini��o da cor do material a partir da cor corrente
//        glEnable(GL_COLOR_MATERIAL);
//        //Habilita o uso de ilumina��o
//        glEnable(GL_LIGHTING);
//        // Habilita a luz de n�mero 0
//        glEnable(GL_LIGHT0);
//        // Habilita o depth-buffering
//        glEnable(GL_DEPTH_TEST);
//
//        // Inicializa a vari�vel que especifica o �ngulo da proje��o
//        // perspectiva
//        // angle=50;
//
//        angle = 20;
//
//        // Inicializa as vari�veis usadas para alterar a posi��o do
//        // observador virtual
//        rotX = 30;
//        rotY = 0;
//        obsZ = 10;
//
//        // Comandos de inicializa��o para textura
//        imagemTextura = LoadBMP("C:\\Users\\Viviane Alves\\CLionProjects\\opengl\\texturas\\palha2.bmp");
//        glGenTextures(1, &idTextura);
//        glBindTexture(GL_TEXTURE_2D, idTextura);
//        glTexImage2D(GL_TEXTURE_2D, 0, 3, imagemTextura->sizeX,
//                     imagemTextura->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE,
//                     imagemTextura->data);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//        glEnable(GL_TEXTURE_2D);
//    }
//
//// Fun��o usada para especificar o volume de visualiza��o
//    void EspecificaParametrosVisualizacao(void) {
//        // Especifica sistema de coordenadas de proje��o
//        glMatrixMode(GL_PROJECTION);
//        // Inicializa sistema de coordenadas de proje��o
//        glLoadIdentity();
//
//        // Especifica a proje��o perspectiva(angulo,aspecto,zMin,zMax)
//        gluPerspective(angle, fAspect, 0.5, 500);
//
//        PosicionaObservador();
//    }
//
//// Fun��o callback chamada quando o tamanho da janela � alterado
//    void AlteraTamanhoJanela(GLsizei w, GLsizei h) {
//        // Para previnir uma divis�o por zero
//        if (h == 0) h = 1;
//
//        // Especifica as dimens�es da viewport
//        glViewport(0, 0, w, h);
//
//        // Calcula a corre��o de aspecto
//        fAspect = (GLfloat) w / (GLfloat) h;
//
//        EspecificaParametrosVisualizacao();
//    }
//
//// Fun��o callback chamada para gerenciar eventos do mouse
//    void GerenciaMouse(int button, int state, int x, int y) {
//        if (button == GLUT_LEFT_BUTTON)
//            if (state == GLUT_DOWN) {  // Zoom-in
//                if (angle >= 10) angle -= 5;
//            }
//        if (button == GLUT_RIGHT_BUTTON)
//            if (state == GLUT_DOWN) {  // Zoom-out
//                if (angle <= 130) angle += 5;
//            }
//        EspecificaParametrosVisualizacao();
//        glutPostRedisplay();
//    }
//
//// Callback para gerenciar eventos do teclado para teclas especiais
//    void TeclasEspeciais(int key, int x, int y) {
//        switch (key) {
//            case GLUT_KEY_LEFT:
//                rotY--;
//                break;
//            case GLUT_KEY_RIGHT:
//                rotY++;
//                break;
//            case GLUT_KEY_UP:
//                rotX++;
//                break;
//            case GLUT_KEY_DOWN:
//                rotX--;
//                break;
//            case GLUT_KEY_HOME:
//                obsZ++;
//                break;
//            case GLUT_KEY_END:
//                obsZ--;
//                break;
//            case GLUT_KEY_F10:// "camera reset"
//                rotX = 30;
//                rotY = 0;
//                obsZ = 10;
//                angle = 50;
//                EspecificaParametrosVisualizacao();
//                break;
//        }
//        PosicionaObservador();
//        glutPostRedisplay();
//    }
//
//// Programa Principal
//    int main(int argc, char **argv) {
//        glutInit(&argc, argv);
//        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//        glutInitWindowSize(400, 350);
//        glutCreateWindow("Visualizacao 3D com Mapeamento de Textura");
//        glutDisplayFunc(Desenha);
//        glutReshapeFunc(AlteraTamanhoJanela);
//        glutMouseFunc(GerenciaMouse);
//        glutSpecialFunc(TeclasEspeciais);
//        Inicializa();
//        glutMainLoop();
//    }