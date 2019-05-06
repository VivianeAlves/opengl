//#include <stdlib.h>
//#include <GL/glut.h>
//
//GLfloat escala = 1;
//GLfloat rotacao = 0;
//GLfloat movx = 0, movy = 0;
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
//    glTranslatef(movx, movy, 0);
//    glScalef(escala, escala, 0);
//    //        angulo  x   y  z
//    glRotatef(rotacao,1, 0, 0);
//
//
//
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
//void teclas(unsigned char key, GLint x, GLint y) {
//    switch (key) {
//        case '+':
//            escala++;
//            break;
//        case '-':
//            escala--;
//            break;
//        case 'a':
//            rotacao += 3;
//            break;
//        case 'd':
//            rotacao -= 3;
//            break;
//    }
//    desenha();
//}
//
//
//void teclasEspeciais(GLint tecla, GLint x, GLint y) {
//    switch (tecla) {
//        case GLUT_KEY_UP:
//            movy++;
//            break;
//        case GLUT_KEY_DOWN:
//            movy--;
//            break;
//        case GLUT_KEY_LEFT:
//            movx--;
//            break;
//        case GLUT_KEY_RIGHT:
//            movx++;
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
//    glutCreateWindow("mudando rotacao");
//    glutDisplayFunc(desenha);
//    glutKeyboardFunc(teclas);
//    glutSpecialFunc(teclasEspeciais);
//    glutMainLoop();
//
//    return 0;
//}