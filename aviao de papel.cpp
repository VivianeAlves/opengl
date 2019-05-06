////
//// Created by Viviane Alves on 23/04/2019.
////
//
//#include <GL/glut.h>
//#include <stdlib.h>
//
//void init(void) {
//    glClearColor(0.0, 0.0, 0.0, 0.0);
//    glShadeModel(GL_FLAT);
//}
//
//void reshape(int w, int h) {
//    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0.0, (GLdouble) w / 10, 0.0, (GLdouble) h / 10);
//}
//
//void display(void) {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(1.0, 1.0, 1.0);
//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//    glPushMatrix();
//    glScalef(0.3, 0.3, 0.3);
//    glRotatef(-10.0, 0.0, 0.0, 1.0);
//    glColor3f(1, 0, 0);
//    glBegin(GL_TRIANGLE_FAN);
//    glVertex2f(5.0, 25.0);
//    glVertex2f(10.0, 5.0);
//    glVertex2f(15.0, 10.0);
//    glVertex2f(20.9, 8.9);
//    glVertex2f(21.3, 13.7);
//    glVertex2f(26.0, 17.5);
//    glEnd();
//    glPopMatrix();
//
//    glFlush();
//}
//
//int main(int argc, char **argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(600, 600);
//    glutInitWindowPosition(0, 0);
//    glutCreateWindow("Triangle Mode");
//    init();
//    glutDisplayFunc(display);
//    glutReshapeFunc(reshape);
//    glutMainLoop();
//    return 0;
//}