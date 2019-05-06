////
//// Created by Viviane Alves on 05/04/2019.
////
//
//#include <stdlib.h>
//#include <GL/glut.h>
//
//int x1 = -30, y1 = -60, x2 = 30, y2 = -60, x3 = 0, y3 = 60;
//
//void init() {
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-50.0, 50.0, -100.0, 100.0);
//}
//
///*-----------------minha funcao desenho ( ) ---------------------*/
//void desenho(void) {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glBegin(GL_LINE_LOOP);
//    glColor3f(1.0, 1.0, 1.0);
//    glVertex2i(x1, y1);
//    glVertex2i(x2, y2);
//    glVertex2i(x3, y3);
//    glEnd();
//    glFlush();
//}
//
///*-----------------minhas funções de  mouse ( ) -----------------*/
//void mouse(int button, int state, int x, int y) {
//    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//        exit(0);
//    }
//}  /*-----------------minhas funções teclado ( ) -------------------*/
//void teclado(unsigned char key, int x, int y) {
//    switch (key) {
//        case '+':
//            x1 += 05;
//            y1 += 05;
//            x2 += 05;
//            y2 += 05;
//            break;
//        case '-':
//            x1 -= 05;
//            y1 -= 05;
//            x2 -= 05;
//            y2 -= 05;
//            break;
//    }
//    glutPostRedisplay();
//}
//
//void especiais(int key, int x, int y) {
//    switch (key) {
//        case GLUT_KEY_F4:
//            exit(0);
//            break;
//    }
//}  /*-----------------main ---------------------*/
//int main(int argc, char **argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(640, 480);
//    glutInitWindowPosition(100, 100);
//    glutCreateWindow("Para fechar a janela: Bt Direito do Mouse ou F4 | Mover pontos: '+' ou '-' ");
//    glutDisplayFunc(desenho);
//    glutMouseFunc(mouse);
//    glutKeyboardFunc(teclado);
//    glutSpecialFunc(especiais);
//    init();
//    glutMainLoop();
//    return 0;
//}