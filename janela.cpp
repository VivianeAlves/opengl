////
//// Created by Viviane Alves on 29/03/2019.
////
//
//#include <stdlib.h>
//#include <GL/glut.h>
//#include <stdio.h>
//
//void desenha() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glClearColor(0, 0, 0, 0);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    //coordenadas de plano cartesiano
//    //x vai de -3 a 3 e y vai de -3 a 3
//    //gluOrtho2D(-5, 5, -5, 5);
//
////    glColor3f(1, 1, 0);
////    glMatrixMode(GL_MODELVIEW);
////    glLoadIdentity();
////        glBegin(GL_QUADS);
////        //um ponto
////        glVertex2f(2,2);
////        //outro ponto
////        //dois pontos formam uma linha
////        glVertex2f(2,-2);
////        //linha vai de -2 do eixo x, ate 2 do x;
////
////
////        glColor3f(0,0,0);
////        glVertex2f(-2,-2);
////        glVertex2f(-2,2);
////
////        glEnd();
//
//
////    glBegin(GL_TRIANGLES);
////    glVertex2f(-2, 0);
////    glVertex2f(2, 0);
////    glVertex2f(0, 2);
//
//    glEnd();
//
//
//    glFlush();
//}
//
//
//void alteraJanela(GLsizei h, GLsizei w) {
//    printf("Novo tamanho tela: %d x %d\n", h, w);
//}
//
//void teclado(unsigned char tecla, int x , int y){
//    if(tecla=='a')
//        glutFullScreen();
//
//    if(tecla=='b'){
//        glutReshapeWindow(500,500);
//        glutPositionWindow(100,100);
//    }
//
//    if(tecla=='r'){
//        glutReshapeWindow(800,600);
//        glutPositionWindow(100,100);
//    }
//
//}
//
//int main(int argc, char **argv) {
//    glutInit(&argc, argv);
//
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(800, 600);
//    glutInitWindowPosition(100,100);
//    glutCreateWindow("Aplicacao");
//    glutDisplayFunc(desenha);
//    glutReshapeFunc(alteraJanela);
//    glutKeyboardFunc(teclado);
//
//    glutMainLoop();
//
//
//    return 0;
//}
//
