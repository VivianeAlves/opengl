////
//// Created by Viviane Alves on 05/04/2019.
////
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <GL/glut.h>
//
//// Declaração de variáveis globais
////GLfloat tx = 0;
//GLfloat ang1 = 0, ang2 = -90, ang3 = 90;
////GLfloat win = 25;
//
//GLfloat win, deslocamentoX, deslocamentoY;
//GLsizei largura, altura;
//
//// Função para desenhar um "braço" do objeto
//void DesenhaBraco()
//{
//    glLineWidth(2);
//    glColor3f(0.0f, 0.0f, 1.0f);
//    glBegin(GL_LINE_LOOP);
//    glColor3f(1.0f, 0.0f, 0.5f);
//    glVertex2f(1.0,4.6);
//    glVertex2f(1.0,-0.8);
//    glColor3f(0.5f, 1.0f, 0.5f);
//    glVertex2f(-1.0,-0.8);
//    glVertex2f(-1.0,4.6);
//    glEnd();
//    glPointSize(2);
//    glBegin(GL_POINTS);
//    glVertex2i(0,0);
//    glEnd();
//}
//
//void DesenhaDedo()
//{
//    glLineWidth(2);
//    glColor3f(0.0f, 0.0f, 1.0f);
//    glBegin(GL_LINE_LOOP);
//    glColor3f(1.0f, 0.0f, 0.5f);
//    glVertex2f(0.2,4.6);
//    glVertex2f(0.2,-0.8);
//    glColor3f(0.5f, 1.0f, 0.5f);
//    glVertex2f(-0.2,-0.8);
//    glVertex2f(-0.2,4.6);
//    glEnd();
//    glPointSize(2);
//    glBegin(GL_POINTS);
//    glVertex2i(0,0);
//    glEnd();
//}
//
//// Função para desenhar a base do objeto
//void DesenhaBase()
//{
//    glLineWidth(2);
//    glBegin(GL_LINE_LOOP);
//    glVertex2f(1.8,1);
//    glVertex2f(1.8,-1.5);
//    glVertex2f(1.0,-1.5);
//    glVertex2f(1.0,-1);
//    glVertex2f(-1.0,-1);
//    glVertex2f(-1.0,-1.5);
//    glVertex2f(-1.8,-1.5);
//    glVertex2f(-1.8,1);
//    glEnd();
//}
//
//// Função callback de redesenho da janela de visualização
//void Desenha(void)
//{
//    // Muda para o sistema de coordenadas do modelo
//    glMatrixMode(GL_MODELVIEW);
//    // Inicializa a matriz de transformação corrente
//    glLoadIdentity();
//
//    // Limpa a janela de visualização com a cor de fundo definida previamente
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    // Desenha a linha da superfície
//    glColor3f(0.0f,0.0f,0.0f);
//    glLineWidth(4);
//    glBegin(GL_LINE_LOOP);
//    glVertex2f(-win,-3.9);
//    glVertex2f(win,-3.9);
//    glEnd();
//
//    // Desenha um objeto modelado com transformações hierárquicas
//
//    glPushMatrix();
//
//    glTranslatef(deslocamentoX,0.0f,0.0f); //Função de translação de acordo com o parâmetro tx
//
//    glPushMatrix();
//    glScalef(2.5f,2.5f,1.0f);
//    glColor3f(1.0f,0.0f,0.0f);
//    DesenhaBase();
//    glPopMatrix();
//
//    glTranslatef(0.0f,1.5f,0.0f);
//    glRotatef(ang1,0.0f,0.0f,1.0f); //Função de Rotação de acordo com o parâmetro do ângulo (ang1)
//    glScalef(1.4f,1.4f,1.0f);
//    glColor3f(0.0f,1.0f,0.0f);
//    DesenhaBraco();
//
//    glTranslatef(0.4f,2.6f,0.0f);
//    glRotatef(ang2,0.0f,0.0f,1.0f);
//    glColor3f(0.0f,0.0f,1.0f);
//    DesenhaBraco();
//
//    glTranslatef(0.4f,2.6f,0.0f);
//    glRotatef(ang3,0.0f,0.0f,1.0f);
//    glColor3f(0.0f,0.0f,1.0f);
//    DesenhaDedo();
//
//    glPopMatrix();
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
//    // Estabelece a janela de sele??o (esquerda, direita, inferior,
//    // superior) mantendo a propor??o com a janela de visualiza??o
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
//
//// Função callback chamada quando o tamanho da janela é alterado
//void AlteraTamanhoJanela(GLsizei w, GLsizei h)
//{
//    // Evita a divisao por zero
//    if(h == 0) h = 1;
//
//    // Atualiza as vari?veis
//    largura = w;
//    altura = h;
//
//    // Especifica as dimens?es da Viewport
//    glViewport(0, 0, largura, altura);
//
//    EspecificaParametrosDeVisualizacao();
//}
//
//// Função callback chamada para gerenciar eventos de teclas especiais(F1,PgDn,...)
//void TeclasEspeciais(int key, int x, int y){
//    switch(key){
//        case GLUT_KEY_UP:
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
//
//
//            // Rotaciona braco1
//        case GLUT_KEY_HOME:
//            ang1-=5;
//            break;
//
//        case GLUT_KEY_END:
//            ang1+=5;
//            break;
//
//    }
//    EspecificaParametrosDeVisualizacao();
//}
//
//
//void GerenciaMouse(int button, int state, int x, int y){
//switch (button){
//    case GLUT_RIGHT_BUTTON:
//        if (win < 900)
//            win += 5.0f;
//        break;
//    case GLUT_LEFT_BUTTON:
//        if (win > 0)
//            win -= 5.0f;
//        break;
//}
//
//    EspecificaParametrosDeVisualizacao();
//
//}
//
//// Função callback chamada para gerenciar eventos de teclas
//void Teclado (unsigned char key, int x, int y)
//{
//    if (key == 27)
//        exit(0);
//}
//
//
//// Função responsável por inicializar parâmetros e variáveis
//void Inicializa (void)
//{
//    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//    win = 50.0f;
//    deslocamentoX = 0.0f;
//    deslocamentoY = 0.0f;
//}
//
//// Programa Principal
//int main(int argc, char **argv)
//{
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowPosition(5,5);
//    glutInitWindowSize(450,300);
//    glutCreateWindow("Objeto com transformações Geométricas hierárquicas");
//
//    // Registra a função callback de redesenho da janela de visualização
//    glutDisplayFunc(Desenha);
//
//    // Registra a função callback de redimensionamento da janela de visualização
//    glutReshapeFunc(AlteraTamanhoJanela);
//
//    // Registra a função callback para tratamento das teclas especiais
//    glutSpecialFunc(TeclasEspeciais);
//
//    // Registra a função callback para tratamento das teclas ASCII
//    glutKeyboardFunc (Teclado);
//
//    // Registra a fun??o callback que gerencia os eventos do mouse
//    glutMouseFunc(GerenciaMouse);
//
//    // Chama a função responsável por fazer as inicializações
//    Inicializa();
//
//    // Inicia o processamento e aguarda interações do usuário
//    glutMainLoop();
//
//    return 0;
//}
//
