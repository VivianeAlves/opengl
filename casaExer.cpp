//#include <stdlib.h>
//#include <GL/glut.h>
//#include <math.h>
//#include <stdio.h>
//
//
//GLfloat win, deslocamentoX, deslocamentoY;
//
//GLsizei largura, altura;
//
//
//// Fun��o callback de redesenho da janela de visualiza��o
//void Desenha(void){
//
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//
//    // Limpa a janela de visualiza��o com a cor
//    // de fundo definida previamente
//    glClear(GL_COLOR_BUFFER_BIT);
//
//
//    // Altera a cor do desenho para azul
//    glColor3f(0.0f, 0.0f, 1.0f);
//    // Desenha a casa
//    glBegin(GL_QUADS);
//    glVertex2f(-15.0f,-15.0f);
//    glVertex2f(-15.0f,  5.0f);
//    glVertex2f( 15.0f,  5.0f);
//    glVertex2f( 15.0f,-15.0f);
//    glEnd();
//
//    // Altera a cor do desenho para marron
//    glColor3f(0.5f, 0.4f, 0.1f);
//    // Desenha a porta e a janela
//    glBegin(GL_QUADS);
//    glVertex2f(-4.0f,-14.0f);
//    glVertex2f(-4.0f,  0.0f);
//    glVertex2f( 4.0f,  0.0f);
//    glVertex2f( 4.0f,-14.0f);
//    glEnd();
//
//
//
//    // Altera a cor do desenho para vermelho
//    glColor3f(1.0f, 0.0f, 0.0f);
//    // Desenha o telhado
//
//    glBegin(GL_TRIANGLES);
//    glVertex2f(-20.0f, 5.0f);
//    glVertex2f(  0.0f,20.0f);
//    glVertex2f( 20.0f, 5.0f);
//    glEnd();
//
//
//
//    // Executa os comandos OpenGL
//    glFlush();
//}
//
//
//
//void EspecificaParametrosDeVisualizacao(void)
//{
//    // Inicializa o sistema de coordenadas
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//
//    // Estabelece a janela de sele��o (esquerda, direita, inferior,
//    // superior) mantendo a propor��o com a janela de visualiza��o
//    if (largura <= altura)
//        gluOrtho2D (-win+deslocamentoX, win+deslocamentoX,
//                    -win*altura/largura+deslocamentoY, win*altura/largura+deslocamentoY);
//    else
//        gluOrtho2D (-win*largura/altura+deslocamentoX, win*largura/altura+deslocamentoX,
//                    -win+deslocamentoY, win+deslocamentoY);
//
//
//    glutPostRedisplay();
//}
//
//// Fun��o callback chamada quando o tamanho da janela � alterado
//void AlteraTamanhoJanela(GLsizei w, GLsizei h){
//    // Evita a divisao por zero
//    if(h == 0) h = 1;
//
//    // Atualiza as vari�veis
//    largura = w;
//    altura = h;
//
//    // Especifica as dimens�es da Viewport
//    glViewport(0, 0, largura, altura);
//
//    EspecificaParametrosDeVisualizacao();
//}
//
//// Fun��o callback chamada para gerenciar eventos de teclas especiais(F1,PgDn,...)
//void TeclasEspeciais(int key, int x, int y){
//    switch(key){
//        case GLUT_KEY_UP:
//
//            deslocamentoY += 2;
//            break;
//
//        case GLUT_KEY_DOWN:
//
//            deslocamentoY -= 2;
//            break;
//
//        case GLUT_KEY_LEFT:
//
//            deslocamentoX -= 2;
//            break;
//
//        case GLUT_KEY_RIGHT:
//
//            deslocamentoX += 2;
//            break;
//
//        case GLUT_KEY_PAGE_UP:
//            if (win > 0)
//                win -= 5.0f;
//            break;
//
//        case GLUT_KEY_PAGE_DOWN:
//            if (win < 900)
//                win += 5.0f;
//            break;
//    }
//
//    EspecificaParametrosDeVisualizacao();
//
//}
//
//
//
//// Fun��o callback chamada quando s�o notificados os eventos do mouse
//void GerenciaMouse(int button, int state, int x, int y){
//    if (button == GLUT_LEFT_BUTTON)
//        if (win > 0)	win = 50.0f;
//    deslocamentoX = 0.0f;
//    deslocamentoY = 0.0f;
//    win -= 5.0f;
//
//
//    if (button == GLUT_RIGHT_BUTTON)
//        if (win < 900)
//            win += 5.0f;
//
//    EspecificaParametrosDeVisualizacao();
//
//}
//
//
//
//// Fun��o callback chamada para gerenciar eventos de teclas
//void Teclado (unsigned char key, int x, int y) {
//    if (key == 27)
//        exit(0);
//}
//
//
//// Fun��o respons�vel por inicializar par�metros e vari�veis
//void Inicializa (void){
//
//    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//    win = 50.0f;
//    deslocamentoX = 0.0f;
//    deslocamentoY = 0.0f;
//}
//
//
//
//// Programa Principal
//int main(int argc, char **argv)
//{
//    glutInit(&argc,argv);
//    // Define do modo de opera��o da GLUT
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//
//    // Especifica a posi��o inicial da janela GLUT
//    glutInitWindowPosition(5,5);
//
//    // Especifica o tamanho inicial em pixels da janela GLUT
//    glutInitWindowSize(450,450);
//
//    // Cria a janela passando como argumento o t�tulo da mesma
//    glutCreateWindow("Exemplo");
//
//    // Registra a fun��o callback de redesenho da janela de visualiza��o
//    glutDisplayFunc(Desenha);
//
//    // Registra a fun��o callback de redimensionamento da janela de visualiza��o
//    glutReshapeFunc(AlteraTamanhoJanela);
//
//    // Registra a fun��o callback para tratamento das teclas especiais
//    glutSpecialFunc(TeclasEspeciais);
//
//    // Registra a fun��o callback para tratamento das teclas ASCII
//    glutKeyboardFunc (Teclado);
//
//    // Registra a fun��o callback que gerencia os eventos do mouse
//    glutMouseFunc(GerenciaMouse);
//
//    // Chama a fun��o respons�vel por fazer as inicializa��es
//    Inicializa();
//
//    // Inicia o processamento e aguarda intera��es do usu�rio
//    glutMainLoop();
//
//    return 0;
//}