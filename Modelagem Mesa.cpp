////
//// Created by Viviane Alves on 23/04/2019.
////
//
//#include <stdlib.h>
//#include <stdio.h>
//#include <GL/glut.h>
//
//#define TABLE 1
//int posY = 0;
//int posX = 0;
//
//void init(void) {
//    glClearColor(0.0, 0.0, 0.0, 0.0);
//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//    // Inicializa display lists
//
//    glNewList(TABLE, GL_COMPILE); // Mesa
//    glPushMatrix();
//    glScalef(15, 1, 15);
//    glutWireCube(1);
//
//    //
//    // Use aqui as primitivas e transformacoes geometricas
//    // do OpenGL para modelar a mesa.
//    //
//
//    glPopMatrix();
//    glPushMatrix();
//    glColor3f(1, 0, 0);
//    glTranslatef(9, -9, 1);
//    glScalef(1, -10, 1);
//    glutWireCube(1);
//    glPopMatrix();
//
//    glPushMatrix();
//    glColor3f(1, 0, 0);
//    glTranslatef(-9, -9, 1);
//
//    glScalef(1, -10, 1);
//    glutWireCube(1);
//    glPopMatrix();
//
//    glEndList();
//}
//
//void display(void) {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(1.0, 1.0, 1.0);
//    glLoadIdentity();
//
//    // Chama o display list da mesa para exibi-la
//    glPushMatrix();
//    glCallList(TABLE);
//    glPopMatrix();
//
//    glFlush();
//}
//
//void reshape(int w, int h) {
//    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluPerspective(60.0, (GLfloat) w / (GLfloat) h, 1.0, 100.0);
//    gluLookAt(-5.0, 15.0, 30.0,
//              0.0, -2.0, 0.0,
//              0.0, 1.0, 0.0);
//    glMatrixMode(GL_MODELVIEW);
//}
//
//void keyboard(unsigned char key, int x, int y) {
//    switch (key) {
//        case 27:
//            exit(0);
//            break;
//        case 'w':
//            posY++;
//            break;
//        case 's':
//            posY--;
//            break;
//        case 'a':
//            posX--;
//            break;
//        case 'd':
//            posX++;
//            printf("%d", posX);
//            break;
//    }
//    glutPostRedisplay();
//
//}
//
//int main(int argc, char **argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(400, 300);
//    glutInitWindowPosition(100, 100);
//    glutCreateWindow(argv[0]);
//    init();
//    glutDisplayFunc(display);
//    glutReshapeFunc(reshape);
//    glutKeyboardFunc(keyboard);
//    glutMainLoop();
//    return 0;
//}