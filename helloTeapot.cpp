////
//// Created by Viviane Alves on 21/04/2019.
////
//
//#include <GL/gl.h>
//#include <GL/glut.h>
//
//void display() {
//
//    /* clear window */
//    glClear(GL_COLOR_BUFFER_BIT);
//    glClearColor(0, 0, 0, 0);
//    /* future matrix manipulations should affect the modelview matrix */
//    glMatrixMode(GL_MODELVIEW);
//
//    glColor3f(1, 0, 0);
//    glPushMatrix();
//    glTranslatef(1,0,0);
//    /* draw scene */
//    glutWireTeapot(.5);
//    glPopMatrix();
//
//
//    glColor3f(0, 1, 0);
//    glPushMatrix();
//    glTranslatef(-1, 0, 0);
//    /* draw scene */
//    glutWireTeapot(0.5);
//    glPopMatrix();
//
//    /* flush drawing routines to the window */
//    glFlush();
//
//}
//
//void reshape(int width, int height) {
//
//    /* define the viewport transformation */
//    glViewport(0, 0, width, height);
//
//}
//
//int main(int argc, char *argv[]) {
//
//    /* initialize GLUT, using any commandline parameters passed to the
//       program */
//    glutInit(&argc, argv);
//
//    /* setup the size, position, and display mode for new windows */
//    glutInitWindowSize(500, 500);
//    glutInitWindowPosition(0, 0);
//    glutInitDisplayMode(GLUT_RGB);
//
//    /* create and set up a window */
//    glutCreateWindow("hello, teapot!");
//    glutDisplayFunc(display);
//    glutReshapeFunc(reshape);
//
//    /* define the projection transformation */
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glFrustum(-2.0, 2.0, -2.0, 2.0, 1.0, 3.0);
////    gluPerspective(45,0,1.0,3.0);
//
//    /* define the viewing transformation */
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//    gluLookAt(0.0, 0.0, 1.0,
//              0.0, 0.0, 0.0,
//              0.0, 1.0, 0.0);
//
//    /* tell GLUT to wait for events */
//    glutMainLoop();
//}