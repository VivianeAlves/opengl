////
//// Criado por Viviane Alves e Marcia Cristina em 29/03/2019.
////
//
//#include <stdlib.h>
//#include <GL/glut.h>
//
//void glutBitmapCharacter(void *font, int
//character);
//
//void desenha() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-20, 20, -20, 20);
//    glPointSize(4);
//
//    //casa branca
//    glColor3f(0.94, 0.97, 1);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//    glBegin(GL_QUADS);
//    glVertex2f(4, 4);
//    glVertex2f(4, -4);
//    glVertex2f(-1, -4);
//    glVertex2f(-1, 4);
//    glEnd();
//
//    //telhado casa branca
//    glColor3f(0.87, 0.72, 0.53);
//    glBegin(GL_TRIANGLES);
//    glVertex2f(5, 4);
//    glVertex2f(-2, 4);
//    glVertex2f(1.6, 8);
//    glEnd();
//
//    //janela casa branca
//    glColor3f(0.55, 0.27, 0.07);
//    glBegin(GL_QUADS);
//    glVertex2f(3.5, 3);
//    glVertex2f(2, 3);
//    glVertex2f(2, 0);
//    glVertex2f(3.5, 0);
//    glEnd();
//
//
//    //linhas janela casa branca
//    glLineWidth(0.5);
//    glColor3f(1, 1, 1);
//    glBegin(GL_LINES);
//    glVertex2f(2.75, 3);
//    glVertex2f(2.7, 0);
//    glVertex2f(2, 1.5);
//    glVertex2f(3.5, 1.5);
//    glEnd();
//
//    //porta casa branca
//    glPointSize(4);
//    glColor3f(0.24, 0.17, 0.12);
//    glBegin(GL_QUADS);
//    glVertex2f(-0.5, 1);
//    glVertex2f(1, 1);
//    glVertex2f(1, -4);
//    glVertex2f(-0.5, -4);
//    glEnd();
//
//
//    //casa cinza
//    glColor3f(0.86, 0.86, 0.86);
//    glBegin(GL_QUADS);
//    glVertex2f(4, 0.5);
//    glVertex2f(7, 0.5);
//    glVertex2f(7, -4);
//    glVertex2f(4, -4);
//    glEnd();
//
//    //casa cinza janelas
//    glColor3f(0.55, 0.27, 0.07);
//    glBegin(GL_QUADS);
//    //primeiro quadrado janela
//    glVertex2f(6.5, -0.3);
//    glVertex2f(4.5, -0.3);
//    glVertex2f(4.5, -1);
//    glVertex2f(6.5, -1);
//    glEnd();
//
//    //segundo quadrado janela
//    glColor3f(0.55, 0.27, 0.07);
//    glBegin(GL_QUADS);
//    glVertex2f(6.5, -1.5);
//    glVertex2f(4.5, -1.5);
//    glVertex2f(4.5, -2.2);
//    glVertex2f(6.5, -2.2);
//    glEnd();
//
//
//    //telhado casa cinza
//    glPointSize(4);
//    glColor3f(0.89, 0.45, 0.36);
//    glBegin(GL_TRIANGLES);
//    glVertex2f(4, 0.5);
//    glVertex2f(7.5, 0.5);
//    glVertex2f(4, 3.5);
//    glEnd();
//
//    //chão verde
//    glColor3f(0.13, 0.55, 0.13);
//    glBegin(GL_QUADS);
//    glVertex2f(8, -6);
//    glVertex2f(-6, -6);
//    glVertex2f(-6, -3.5);
//    glVertex2f(8, -3.5);
//    glEnd();
//
//
//    //cabeça da arvore
//    glColor3f(0, 0.39, 0);
//    glBegin(GL_TRIANGLES);
//    glVertex2f(-11, 0);
//    glVertex2f(-15, 0);
//    glVertex2f(-13, 5);
//
//    glColor3f(0, 0.39, 0);
//    glVertex2f(-9, -4);
//    glVertex2f(-17, -4);
//    glVertex2f(-13, 3);
//    glEnd();
//
//    //tronco da arvore
//    glColor3f(0.8, 0.47, 0.13);
//    glBegin(GL_QUADS);
//    glVertex2f(-14, -6.4);
//    glVertex2f(-12, -6.4);
//    glVertex2f(-12, -4);
//    glVertex2f(-14, -4);
//    glColor3f(0.18, 0.31, 0.31);
//    glEnd();
//
//
//    // posição do texto na tela
//    glRasterPos2f(-10, -13);
//
//    // texto a ser escrito
//    char *p = (char *) "Criado por: Viviane Alves e Marcia Cristina";
//    while (*p != '\0') {
//        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,
//                            *p++);
//    }
//
//    glFlush();
//}
//
//int main(int argc, char **argv) {
//    glutInit(&argc, argv);
//
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(800, 600);
//    glutCreateWindow("Aplicacao");
//    glutDisplayFunc(desenha);
//    glClearColor(0.66, 0.66, 0.66, 0);
//    glutMainLoop();
//
//
//    return 0;
//}
//
//
//
