////
//// Created by Viviane Alves on 27/03/2019.
////
//#include <stdlib.h>
//#include <GL/glut.h>
//
//void inicializa(void){
//    //cor de fundo da janela
//	glClearColor(0.0f, 0.0f,0.0f,1.0f);
//
//    // Define a janela de visualização 2D
//    glMatrixMode(GL_PROJECTION);
//    gluOrtho2D(0.0,10.0,0.0,10.0);
//
//}
//
//void desenha(void){
//	glClear(GL_COLOR_BUFFER_BIT);
//
//    // Define a cor de desenho: vermelho
//	glColor3f(0.0f,0.0f,0.0f);
//// Desenha um triângulo no centro da janela
//    glBegin(GL_POINTS);
//    glVertex2i(100,50);
//    glVertex2i(100,130);
//    glVertex2i(150,130);
//    glEnd();
//
//	glFlush();
//}
//
//void teclado(unsigned char key, int x, int y){
//    if (key==27)
//        exit(0);
//}
//
//
//int main(int argc, char **argv){
//	glutInit(&argc, argv);
//
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutCreateWindow("Primeira Janela");
//	glutDisplayFunc(desenha);
//	inicializa();
//	glutKeyboardFunc(teclado);
//	glutMainLoop();
//
//	return 0;
//}
