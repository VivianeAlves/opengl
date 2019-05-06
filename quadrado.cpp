////
//// Created by Viviane Alves on 27/03/2019.
////
//#include <windows.h>
//#include <GL/glut.h>
//
//
//GLfloat trans_x = 0, rod = 1, es=1;
//
//void Teclado(unsigned char key, int x, int y) {
//    switch (key) {
//        case 'a':
//            trans_x += 10;
//            break;
//        case 'q':
//            rod += 1;
//            break;
//        case 'e':
//            rod -= 1;
//            break;
//        case 'z ':
//            es += 1;
//            break;
//        case 'm':
//            es -= 1;
//            break;
//        case '27':
//            exit(0);
//    }
//
//    glutPostRedisplay();
//}
//
//void desenha() {
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//    //glTranslatef(trans_x, 0, 0);
////    glRotatef(rod, 0.0, 0.0, 1.0);
//glScalef(es,es,1.0);
//
//    glClear(GL_COLOR_BUFFER_BIT);
//    //cor do quadrado
//    glColor3f(1.0, 0.0, 0.0);
//    glBegin(GL_QUADS);
//    glVertex2i(100, 150);
//    glVertex2i(100, 100);
//
//    glColor3f(0.0, 0.0, 1.0);
//    glVertex2i(150, 100);
//    glVertex2i(150, 150);
//    glEnd();
//
//    glFlush();
//}
//
//void inicializa() {
//    //cor da janela é preta
//    glClearColor(0.0, 0.0, 0.0, 1.0);
//}
//
//void alteraTamanhoJanela(GLsizei w, GLsizei h) {
//    if (h == 0) h = 1;
//
//    glViewport(0, 0, w, h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//
//    if (w <= h)
//        gluOrtho2D(0.0, 250.0, 0.0, 250.0 * h / w);
//    else
//        gluOrtho2D(0.0, 250.0 * w / h, 0.0, 250.0);
//
//
//}
//
//
//int main(int argc, char **argv) {
//    glutInit(&argc, argv);
//
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(400, 350);
//    glutInitWindowPosition(10, 10);
//    glutCreateWindow("Quadrado");
//    glutDisplayFunc(desenha);
//    glutReshapeFunc(alteraTamanhoJanela);
//    glutKeyboardFunc(Teclado);
//    inicializa();
//    glutMainLoop();
//    return 0;
//}