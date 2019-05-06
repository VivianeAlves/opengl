//
//// Created by Viviane Alves on 06/04/2019.
////
//
//#include <GL/glut.h>
//
//GLfloat rotacao = 0;
//
//void teclas(unsigned char key, GLint x, GLint y) {
//
//    switch (key) {
//        case 'a':
//            rotacao += 3;
//            break;
//        case 'd':
//            rotacao -= 3;
//            break;
//    }
//    glutPostRedisplay();
//}
//
//
//void desenha(void) {
//
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glDisable(GL_DEPTH_TEST);
//    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//
//    // Define a janela de visualização 2D
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-20, 20, -20, 20);
//    glPointSize(10);
//
//    glColor3f(0, 0, 1);
//    glBegin(GL_POINTS);
//    glVertex2i(-7, 4);
//    glEnd();
//
//
//    glColor3f(1, 0, 0);
//    glPushMatrix();
//    glRotatef(rotacao, 1, 0, 0);
//    glBegin(GL_QUADS);
//    glVertex2i(-8, 4);
//    glVertex2i(-8, -7);
//    glVertex2i(-6, -7);
//    glVertex2i(-6, 4);
//    glEnd();
//    glPopMatrix();
//
//
//    glColor3f(1, 1, 0);
//    glBegin(GL_QUADS);
//    glVertex2i(-6, -7);
//    glVertex2i(-6, -1);
//    glVertex2i(-5, -1);
//    glVertex2i(-5, -7);
//    glEnd();
//
//
//    glColor3f(0, 1, 1);
//    glBegin(GL_QUADS);
//    glVertex2i(-6, 4);
//    glVertex2i(-6, 0);
//    glVertex2i(-5, 0);
//    glVertex2i(-5, 4);
//    glEnd();
//
//    glFlush();
//}
//
//int main(int argc, char **argv) {
//
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(800, 600);
//    glutInitWindowPosition(320, 150);
//    glutCreateWindow("mudando rotacao");
//    glutDisplayFunc(desenha);
//    glutKeyboardFunc(teclas);
//    glutMainLoop();
//
//    return 0;
//}