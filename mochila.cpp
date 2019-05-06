////
//// Created by Viviane Alves on 06/04/2019.
////
//
//#include <GL/glut.h>
//#include <stdio.h>
//
//GLfloat movy = 0;
//GLfloat movy1 = 0;
//GLfloat movy2 = 0;
//int trans = 0;
//int escala = 1;
//
//void teclas(unsigned char key, GLint x, GLint y) {
//
//    switch (key) {
//
//        case 105:
//            movy = 5;
//            printf("%f\n", movy);
//            break;
//        case 107:
//            movy = 0;
//            printf("%f\n", movy);
//            break;
//        case 'p':
//            movy1 = 3;
//            printf("%f\n", movy1);
//            break;
//        case 'z':
//            movy1 = 0;
//            printf("%f\n", movy1);
//            break;
//        case 'y':
//            movy2 = 16;
//            movy = 5;
//            printf("%f\n", movy2);
//            break;
//        case 'h':
//            movy2 = 0;
//            movy = 0;
//            printf("%f\n", movy2);
//            break;
//
//        case 43:
//            escala++;
//            printf("%f\n", escala);
//            break;
//        case 45:
//            escala--;
//            printf("%f\n", escala);
//            break;
//        case 106:
//            trans++;
//            printf("%f\n", trans);
//            break;
//        case 108:
//            trans--;
//            printf("%f\n", trans);
//            break;
//    }
//    glutPostRedisplay();
//
//}
//
//void aba() {
//
//    //aba mochila
//    glColor3f(0, 0, 1);
//    glBegin(GL_QUADS);
//    glVertex2f(5.1, 7);
//    glVertex2f(-5.1, 7);
//    glVertex2f(-5.1, 0);
//    glVertex2f(5.1, 0);
//
//    glEnd();
//
//}
//
//void corpomochila() {
////corpo mochila
//    glColor3f(1, 0, 0);
//    glBegin(GL_QUADS);
//    glVertex2f(-5, -10);
//    glVertex2f(5, -10);
//    glVertex2f(5, 5);
//    glVertex2f(-5, 5);
//    glEnd();
//}
//
//void restobolsa(void) {
//    //fundo da mochila
//    glColor3f(0, 0, 0);
//    glBegin(GL_QUADS);
//    glVertex2f(-4, 0);
//    glVertex2f(4, 0);
//    glVertex2f(4, 4.7);
//    glVertex2f(-4, 4.7);
//    glEnd();
//
//
//    //bolso
//    glColor3f(0, 1, 0);
//    glBegin(GL_QUADS);
//    glVertex2f(-4, -4);
//    glVertex2f(4, -4);
//    glVertex2f(4, -9);
//    glVertex2f(-4, -9);
//    glEnd();
//
//
//    //corda superior
//    glColor3f(1, 1, 0);
//    glBegin(GL_POINTS);
//    glVertex2f(-3.5, 7);
//    glVertex2f(3.5, 7);
//    glEnd();
//
//
//}
//
//void fundobolso(void) {
//    //fundo bolso
//    glColor3f(0, 0, 0);
//    glBegin(GL_QUADS);
//    glVertex2f(-3.5, -4.3);
//    glVertex2f(3.5, -4.3);
//    glVertex2f(3.5, -6.6);
//    glVertex2f(-3.5, -6.6);
//    glEnd();
//}
//
//void bolsoext() {
//    //bolso exterior
//    glColor3f(0, 1, 1);
//    glBegin(GL_QUADS);
//    glVertex2f(-4.1, -4);
//    glVertex2f(4.1, -4);
//    glVertex2f(4.1, -7);
//    glVertex2f(-4.1, -7);
//    glEnd();
//}
//
//
//void cordas() {
//
//    //corda 1
//    glColor3f(1, 1, 0);
//    glBegin(GL_QUADS);
//    glVertex2f(-3.5, 0);
//    glVertex2f(-3.5, -4.5);
//    glVertex2f(-3, -4.5);
//    glVertex2f(-3, 0);
//    glEnd();
//
//    //corda 2
//    glColor3f(1, 1, 0);
//    glBegin(GL_QUADS);
//    glVertex2f(3.5, 0);
//    glVertex2f(3.5, -4.5);
//    glVertex2f(3, -4.5);
//    glVertex2f(3, 0);
//    glEnd();
//
//}
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
//
//
//    glPointSize(10);
//    glPushMatrix();
//    glScalef(escala, escala, 0);
//    glTranslatef(trans, 0, 0);
//
//    corpomochila();
//
//    glEnable(GL_DEPTH_TEST);
//    glMatrixMode(GL_MODELVIEW);
//
//
//    glPushMatrix();
//    glTranslatef(0, movy, 0);
//    aba();
//    glPopMatrix();
//
//    restobolsa();
//
//
//    glDisable(GL_DEPTH_TEST);
//    fundobolso();
//
//    glPushMatrix();
//    glTranslatef(0, movy1, 0);
//    bolsoext();
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(0, movy2, 0);
//    cordas();
//    glPopMatrix();
//    glPopMatrix();
//    glEnable(GL_DEPTH_TEST);
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