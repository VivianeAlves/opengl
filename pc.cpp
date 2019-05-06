////
//// Created by viviane on 15/04/19.
////
//
//#include <GL/glut.h>  // GLUT, include glu.h and gl.h
//
///* Global variables */
//
//int angulo = 0;
//
///* Initialize OpenGL Graphics */
//void initGL() {
//    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
//    glClearDepth(1.0f);                   // Set background depth to farthest
//    glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
//    glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
//    glShadeModel(GL_SMOOTH);   // Enable smooth shading
//    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
//    glEnable(GL_CULL_FACE);
//}
//
//void teclado(unsigned char tecla, int x, int y) {
//    switch (tecla) {
//        case 'a':
//            angulo -= 30;
//            break;
//        case 'd':
//            angulo += 30;
//            break;
//    }
//    glutPostRedisplay();
//}
//
///* Handler for window-repaint event. Called back when the window first appears and
//   whenever the window needs to be re-painted. */
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
//
//    glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
////gabinete pc
//    // Render a color-cube consisting of 6 quads with different colors
//    glLoadIdentity();                 // Reset the model-view matrix
//    glTranslatef(1.5f, 0.0f, -7.0f);  // Move right and into the screen
//    //glRotatef(angulo, 0, 0, 1);
//    glRotatef(angulo, 1, 0, 0);
//    glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
//    // Top face (y = 1.0f)
//    // Define vertices in counter-clockwise (CCW) order with normal pointing out
//    glColor3f(0.0f, 1.0f, 0.0f);     // Green
//    glVertex3f(1.0f, 1.0f, -1.0f);
//    glVertex3f(-1.0f, 1.0f, -1.0f);
//    glVertex3f(-1.0f, 1.0f, 1.0f);
//    glVertex3f(1.0f, 1.0f, 1.0f);
//
//
//    // Bottom face (y = -1.0f)
//    glColor3f(1.0f, 0.5f, 0.0f);     // Orange
//    glVertex3f(1.0f, -2.0f, 1.0f);
//    glVertex3f(-1.0f, -2.0f, 1.0f);
//    glVertex3f(-1.0f, -2.0f, -1.0f);
//    glVertex3f(1.0f, -2.0f, -1.0f);
//
//
//    // Front face  (z = 1.0f)
//    glColor3f(1.0f, 0.0f, 0.0f);     // Red
//    glVertex3f(1.0f, 1.0f, 1.0f);
//    glVertex3f(-1.0f, 1.0f, 1.0f);
//    glVertex3f(-1.0f, -2.0f, 1.0f);
//    glVertex3f(1.0f, -2.0f, 1.0f);
//
//    // Back face (z = -1.0f)
//    glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
//    glVertex3f(1.0f, -2.0f, -1.0f);
//    glVertex3f(-1.0f, -2.0f, -1.0f);
//    glVertex3f(-1.0f, 1.0f, -1.0f);
//    glVertex3f(1.0f, 1.0f, -1.0f);
//
//    // Left face (x = -1.0f)
//    glColor3f(0.0f, 0.0f, 1.0f);     // Blue
//    glVertex3f(-1.0f, 1.0f, 1.0f);
//    glVertex3f(-1.0f, 1.0f, -1.0f);
//    glVertex3f(-1.0f, -2.0f, -1.0f);
//    glVertex3f(-1.0f, -2.0f, 1.0f);
//
//    // Right face (x = 1.0f)
//    glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
//    glVertex3f(1.0f, 1.0f, -1.0f);
//    glVertex3f(1.0f, 1.0f, 1.0f);
//    glVertex3f(1.0f, -2.0f, 1.0f);
//    glVertex3f(1.0f, -2.0f, -1.0f);
//    glEnd();  // End of drawing color-cube
//
//    // glDisable(GL_CULL_FACE);
////detalhes gabinete
//    glBegin(GL_QUADS);
//    // Front face  (z = 1.0f)
//    glColor3f(1.0f, 1.0f, 1.0f);     // white
//    glVertex3f(0.5f, 0.2f, 1.0f);
//    glVertex3f(-0.5f, 0.2f, 1.0f);
//    glVertex3f(-0.5f, 0.5f, 1.0f);
//    glVertex3f(0.5f, 0.5f, 1.0f);
//    glEnd();
//
//
//    // Render a pyramid consists of 4 triangles
//    glLoadIdentity();
////monitor
//    // Reset the model-view matrix
//    glTranslatef(-1.5f, 0.0f, -6.0f);  // Move left and into the screen
//
//    glBegin(GL_QUADS);           // Begin drawing the pyramid with 4 triangles
//
//    //up
//    glColor3f(1.0f, 0.0f, 0.0f);     // Red
//    glVertex3f(1.0f, 1.0f, 1.0f);
//    glVertex3f(-1.0f, 1.0f, 1.0f);
//    glVertex3f(-1.0f, 1.0f, -1.0f);
//    glVertex3f(1.0f, 1.0f, -1.0f);
//
//    //left
//    glColor3f(0.0f, 0.0f, 1.0f);     // Blue
//    glVertex3f(-1.0f, 1.0f, 1.0f);
//    glVertex3f(-1.0f, 1.0f, -1.0f);
//    glVertex3f(-1.0f, -1.0f, -1.0f);
//    glVertex3f(-1.0f, -1.0f, 1.0f);
//
//
//    //bottom
//    glColor3f(1.0f, 1.0f, 0.0f);     // yellow
//    glVertex3f(1.0f, -1.0f, 1.0f);
//    glVertex3f(-1.0f, -1.0f, 1.0f);
//    glVertex3f(-1.0f, -1.0f, -1.0f);
//    glVertex3f(1.0f, -1.0f, -1.0f);
//
//    //right
//    glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
//    glVertex3f(1.0f, 1.0f, -1.0f);
//    glVertex3f(1.0f, 1.0f, 1.0f);
//    glVertex3f(1.0f, -1.0f, 1.0f);
//    glVertex3f(1.0f, -1.0f, -1.0f);
//
//    // Front
//    glColor3f(1.0f, 1.0f, 1.0f);     // white
//    glVertex3f(1.0f, 1.0f, 1.0f);
//    glVertex3f(-1.0f, 1.0f, 1.0f);
//    glVertex3f(-1.0f, -1.0f, 1.0f);
//    glVertex3f(1.0f, -1.0f, 1.0f);
//
//    // Back face (z = -1.0f)
//    glColor3f(0.0f, 1.0f, 0.0f);     // Yellow
//    glVertex3f(1.0f, -1.0f, -1.0f);
//    glVertex3f(-1.0f, -1.0f, -1.0f);
//    glVertex3f(-1.0f, 1.0f, -1.0f);
//    glVertex3f(1.0f, 1.0f, -1.0f);
//    glEnd();   // Done drawing the pyramid
//    // glEnable(GL_CULL_FACE);
//
//    glDisable(GL_CULL_FACE);
//    glPointSize(8);
//    //pescoço monitor
//    glTranslatef(-1.5f, -2.0f, -6.0f);
//    glBegin(GL_QUADS);           // Begin drawing the pyramid with 4 triangles
//    //up
//    glColor3f(1.0f, 0.63f, 0.48f);     // Red
//    glVertex3f(0.2f, 0.0f, 1.0f);
//    glVertex3f(-0.2f, 0.0f, 1.0f);
//    glVertex3f(-0.2f, 0.0f, -1.0f);
//    glVertex3f(0.2f, 0.0f, -1.0f);
//
////    //left
//    glColor3f(1.0f, 0.63f, 0.48f);        // Blue
//    glVertex3f(-0.2f, 0.0f, 1.0f);
//    glVertex3f(-0.2f, 0.0f, -1.0f);
//    glVertex3f(-0.2f, -0.5f, -1.0f);
//    glVertex3f(-0.2f, -0.5f, 1.0f);
//
//
////    //bottom
//    glColor3f(1.0f, 0.63f, 0.48f);     // Red
//    glVertex3f(0.2f, -0.5f, 1.0f);
//    glVertex3f(-0.2f, -0.5f, 1.0f);
//    glVertex3f(-0.2f, -0.5f, -1.0f);
//    glVertex3f(0.2f, -0.5f, -1.0f);
//
////    right
//    glColor3f(0.2f, 0.63f, 0.48f);       // Magenta
//    glVertex3f(0.2f, 0.0f, -1.0f);
//    glVertex3f(0.2f, 0.0f, 1.0f);
//    glVertex3f(0.2f, -0.5f, 1.0f);
//    glVertex3f(0.2f, -0.5f, -1.0f);
//
////    // Front
//    glColor3f(0.0f, 1.0f, 0.0f);     // green
//    glVertex3f(0.2f, 0.0f, 1.0f);
//    glVertex3f(-0.2f, 0.0f, 1.0f);
//    glVertex3f(-0.2f, -0.5f, 1.0f);
//    glVertex3f(0.2f, -0.5f, 1.0f);
//
//    // Back face (z = -1.0f)
//    glColor3f(0.2f, 0.63f, 0.48f);        // Yellow
//    glVertex3f(0.2f, -0.5f, -1.0f);
//    glVertex3f(-0.2f, -0.5f, -1.0f);
//    glVertex3f(-0.2f, 0.0f, -1.0f);
//    glVertex3f(0.2f, 0.0f, -1.0f);
//    glEnd();   // Done drawing the pyramid
//
//
//    glPointSize(8);
//    //teclado
//    glTranslatef(-1.2f, -1.0f, 0.0f);
//    glBegin(GL_QUADS);           // Begin drawing the pyramid with 4 triangles
//    //up
//    glColor3f(0.0f, 0.0, 1.0f);     // Red
//    glVertex3f(1.5f, 0.0f, 1.0f);
//    glVertex3f(-1.5f, 0.0f, 1.0f);
//    glVertex3f(-1.5f, 0.0f, -1.0f);
//    glVertex3f(1.5f, 0.0f, -1.0f);
//
////    //left
//    glColor3f(1.0f, 0.63f, 0.48f);        // Blue
//    glVertex3f(-1.5f, 0.0f, 1.0f);
//    glVertex3f(-1.5f, 0.0f, -1.0f);
//    glVertex3f(-1.5f, -0.2f, -1.0f);
//    glVertex3f(-1.5f, -0.2f, 1.0f);
//
//
//    //bottom
//    glColor3f(1.0f, 0.0f, 0.0f);     // Red
//    glVertex3f(1.5f, -0.2f, 1.0f);
//    glVertex3f(-1.5f, -0.2f, 1.0f);
//    glVertex3f(-1.5f, -0.2f, -1.0f);
//    glVertex3f(1.5f, -0.2f, -1.0f);
//
////    right
//    glColor3f(1.0f, 0.63f, 0.48f);        // Blue
//    glVertex3f(1.5f, 0.0f, 1.0f);
//    glVertex3f(1.5f, 0.0f, -1.0f);
//    glVertex3f(1.5f, -0.2f, -1.0f);
//    glVertex3f(1.5f, -0.2f, 1.0f);
//
////    front
//    glColor3f(0.0f, 1.0f, 0.0f);     // green
//    glVertex3f(1.5f, 0.0f, 1.0f);
//    glVertex3f(-1.5f, 0.0f, 1.0f);
//    glVertex3f(-1.5f, -0.2f, 1.0f);
//    glVertex3f(1.5f, -0.2f, 1.0f);
//
//    // Back face (z = -1.0f)
//    glColor3f(1, 1, 0);        // Yellow
//    glVertex3f(1.5f, -0.2f, -1.0f);
//    glVertex3f(-1.5f, -0.2f, -1.0f);
//    glVertex3f(-1.5f, 0.0f, -1.0f);
//    glVertex3f(1.5f, 0.0f, -1.0f);
//
//    glEnd();   // Done drawing the pyramid
//
//
//
//    glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
//}
//
///* Handler for window re-size event. Called back when the window first appears and
//   whenever the window is re-sized with its new width and height */
//void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
//    // Compute aspect ratio of the new window
//    if (height == 0) height = 1;                // To prevent divide by 0
//    GLfloat aspect = (GLfloat) width / (GLfloat) height;
//
//    // Set the viewport to cover the new window
//    glViewport(0, 0, width, height);
//
//    // Set the aspect ratio of the clipping volume to match the viewport
//    glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
//    glLoadIdentity();             // Reset
//    // Enable perspective projection with fovy, aspect, zNear and zFar
//    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
//}
//
///* Main function: GLUT runs as a console application starting at main() */
//int main(int argc, char **argv) {
//    glutInit(&argc, argv);            // Initialize GLUT
//    glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
//    glutInitWindowSize(640, 480);   // Set the window's initial width & height
//    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
//    glutCreateWindow("Computador desenho");          // Create window with the given title
//    glutDisplayFunc(display);       // Register callback handler for window re-paint event
//    glutReshapeFunc(reshape);       // Register callback handler for window re-size event
//    glutKeyboardFunc(teclado);
//    initGL();                       // Our own OpenGL initialization
//    glutMainLoop();                 // Enter the infinite event-processing loop
//    return 0;
//}
