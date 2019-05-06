////
//// Created by Viviane Alves on 27/03/2019.
////
//
//#include <windows.h>
//#include <stdlib.h>
//#include <GL/glut.h>
//#include <math.h>
//#include <stdio.h>
//#include <GL/glu.h>
//
//GLfloat red, green, blue;
//
//// Função callback de redesenho da janela de visualização
//void Desenha(void)
//{
//	// Limpa a janela de visualização com a cor
//	// de fundo definida previamente
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	// Desenha uma casinha composta de um quadrado e um triângulo
//
//	// Altera a cor do desenho para azul
//	glColor3f(red, blue, green);
//	// Desenha a casa
//	glBegin(GL_QUADS);
//		glVertex2f(-15.0,-15.0);
//		glVertex2f(-15.0,  5.0);
//		glVertex2f( 15.0,  5.0);
//		glVertex2f( 15.0,-15.0);
//	glEnd();
//
//    glColor3f(1.0, 1.0, 0.0);
//    glBegin(GL_POINTS);
//    glVertex2f(15,5);
//    glVertex2f(15,-15);
//    glVertex2f(35,5);
//    glVertex2f(35,15);
//    glEnd();
//
//
//
//    // Altera a cor do desenho para branco
//	glColor3f(1.0f, 1.0f, 1.0f);
//	// Desenha a porta e a janela
//	glBegin(GL_QUADS);
//		glVertex2f(-4.0f,-14.5f);
//		glVertex2f(-4.0f,  0.0f);
//		glVertex2f( 4.0f,  0.0f);
//		glVertex2f( 4.0f,-14.5f);
//		glVertex2f( 7.0f,-5.0f);
//		glVertex2f( 7.0f,-1.0f);
//		glVertex2f(13.0f,-1.0f);
//		glVertex2f(13.0f,-5.0f);
//	glEnd();
//
//	// Altera a cor do desenho para azul
//	glColor3f(0.0f, 0.0f, 1.0f);
//	// Desenha as "linhas" da janela
//	glBegin(GL_LINES);
//		glVertex2f( 7.0f,-3.0f);
//		glVertex2f(13.0f,-3.0f);
//		glVertex2f(10.0f,-1.0f);
//		glVertex2f(10.0f,-5.0f);
//	glEnd();
//
//	// Altera a cor do desenho para vermelho
//	glColor3f(1.0f, 0.0f, 0.0f);
//	// Desenha o telhado
//	glBegin(GL_TRIANGLES);
//		glVertex2f(-19.0f, 5.0f);
//		glVertex2f(  0.0f,17.0f);
//		glVertex2f( 19.0f, 5.0f);
//	glEnd();
//
//	// Executa os comandos OpenGL
//	glFlush();
//}
//
//// Função callback chamada quando o tamanho da janela é alterado
//void AlteraTamanhoJanela(GLsizei w, GLsizei h){
//	if(h==0)
//		h=1;
//	glViewport(0, 0, w, h);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//
//	if(w<= h)
//		gluOrtho2D(-50.0, 50.0, -50.0*h/w, 50.0*w/w);
//	else
//		gluOrtho2D(-50.0*h/w, 50.0*w/w, -50.0, 50.0);
//}
//
//
//
//// desenha texto (GLUT_BITNAP_TIMES
//void DesenhaTexto(void *font, char *string)
//{
//	// Exibe caractere a caractere
//	while(*string)
//		glutBitmapCharacter(GLUT_BITMAP_9_BY_15,*string++);
//}
//
//
//// Função callback chamada para gerenciar eventos de teclas
//void Teclado (unsigned char key, int x, int y){
//	if (key == 27)
//		exit(0);
//}
//
//// Função responsável por inicializar parâmetros e variáveis
//void Inicializa (void){
//	// Define a cor de fundo da janela de visualização como branca
//	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//}
//
//// Programa Principal
//int main(int argc, char **argv)
//{
//    glutInit(&argc, argv);
//
//	// Define do modo de operação da GLUT
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//
//	// Especifica a posição inicial da janela GLUT
//	glutInitWindowPosition(5,5);
//
//	// Especifica o tamanho inicial em pixels da janela GLUT
//	glutInitWindowSize(450,450);
//
//	// Cria a janela passando como argumento o título da mesma
//	glutCreateWindow("Desenho de uma casa");
//
//	// Registra a função callback de redesenho da janela de visualização
//	glutDisplayFunc(Desenha);
//
//	// Registra a função callback de redimensionamento da janela de visualização
//	glutReshapeFunc(AlteraTamanhoJanela);
//
//	// Registra a função callback para tratamento das teclas ASCII
//	glutKeyboardFunc (Teclado);
//
//	// Chama a função responsável por fazer as inicializações
//	Inicializa();
//
//	// Inicia o processamento e aguarda interações do usuário
//	glutMainLoop();
//
//	return 0;
//}