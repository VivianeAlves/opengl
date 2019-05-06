//#include <stdlib.h>
//#include <GL/glut.h>
//
//GLfloat escala = 1;
//
//void desenha(void) {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
//
//    // Define a janela de visualização 2D
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-5, 5, -5, 5);
//
//
//    glScalef(escala, escala, 0);
//    glMatrixMode(GL_MODELVIEW);
//    // Define a cor de desenho: vermelho
//    glColor3f(0.0f, 0.0f, 0.0f);
//// Desenha um triângulo no centro da janela
//    glBegin(GL_TRIANGLES);
//    glVertex2f(-2, 0);
//    glVertex2f(0, 2);
//    glVertex2f(2, 0);
//    glEnd();
//
//    glFlush();
//}
//
//void teclado(unsigned char key, GLint x, GLint y) {
//    switch (key) {
//        case '+':
//            escala++;
//            break;
//        case '-':
//            escala--;
//            break;
//    }
//    desenha();
//}
//
//
//int main(int argc, char **argv) {
//    glutInit(&argc, argv);
//
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(800, 600);
//    glutInitWindowPosition(320, 150);
//    glutCreateWindow("mudando escala");
//    glutDisplayFunc(desenha);
//    glutKeyboardFunc(teclado);
//    glutMainLoop();
//
//    return 0;
//}