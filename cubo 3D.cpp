////
//// Created by Viviane Alves on 14/04/2019.
////
//
//#include <stdlib.h>
//#include <GL/glut.h>
//#include <stdio.h>
//
//GLfloat fAspect;
//
//void desenha() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glClearColor(0, 0, 0, 0);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glOrtho(-65,65,-65,65,-400,400);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//    gluLookAt(40,60,100,0,0,0,0,1,0);
//    glColor3f(1,0,0);
//    glutWireCube(50);
//
//    glEnd();
//
//
//    glFlush();
//}
//
//
//int main(int argc, char **argv) {
//    glutInit(&argc, argv);
//
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(800, 600);
//    glutInitWindowPosition(100, 100);
//    glutCreateWindow("Aplicacao");
//    glutDisplayFunc(desenha);
//
//
//    glutMainLoop();
//
//
//    return 0;
//}
//
//
