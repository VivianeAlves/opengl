////
//// Created by Viviane Alves on 21/04/2019.
////
//
//#include <GL/gl.h>
//#include <GL/glut.h>
//
//GLfloat rotacao = 0.0;
//
//void display() {
//
//    /* clear window */
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    /* future matrix manipulations should affect the modelview matrix */
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//
//    gluLookAt(rotacao, 0.0, 5.0,
//              0.0, 0.0, 0.0,
//              0.0, 1.0, 0.0);
//
//    /* draw scene */
//    glPushMatrix();
//    glPushMatrix();
//
//    glTranslatef(0, 0, -3);
//    glutWireTeapot(1);                // middle teapot
//    glTranslatef(0, 2, 0);
//    glutSolidTeapot(1);               // top teapot
//    glPopMatrix();
//
//    glTranslatef(0, -2, -1);
//    glutSolidTeapot(1);               // bottom teapot
//
//    glPopMatrix();
//
//    /* flush drawing routines to the window */
//    glFlush();
//
//}
//
//
//void teclas(unsigned char key, GLint x, GLint y) {
//
//    switch (key) {
//        case 'a':
//            rotacao += 0.1;
//            break;
//        case 'd':
//            rotacao -= 0.1;
//            break;
//    }
//    glutPostRedisplay();
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
//    glutKeyboardFunc(teclas);
//
//    /* define the projection transformation */
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluPerspective(60, 1, 1, 10);
//
//    /* define the viewing transformation */
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//
//
//    /* tell GLUT to wait for events */
//    glutMainLoop();
//}