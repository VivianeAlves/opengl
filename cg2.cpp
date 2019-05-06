////
//// Criado por Viviane Alves e Marcia Cristina em 09/04/2019.
////
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <GL/glut.h>
//
//// Declaração de variáveis globais
//GLfloat ang1 = 0, ang2 = -90, ang3 = 90;
//
//GLfloat win, deslocamentoX, deslocamentoY, panX, panY;
//GLsizei largura, altura;
//
//GLfloat movy = 0;
//GLfloat movy1 = 0;
//GLfloat movy2 = 0;
//GLint trans = 0;
//GLint escala = 1;
//
//
//// Função para desenhar um "braço" do objeto
//void DesenhaBraco()
//{
//    glLineWidth(2);
//    glColor3f(0.0f, 0.0f, 1.0f);
//    glBegin(GL_QUADS);
//    glColor3f(1.0f, 0.0f, 0.5f);
//    glVertex2f(1.0,4.6);
//    glVertex2f(1.0,-0.8);
//    glColor3f(0.5f, 0.9f, 0.5f);
//    glVertex2f(-1.0,-0.8);
//    glVertex2f(-1.0,4.6);
//    glEnd();
//    glPointSize(2);
//    glColor3f(0.0f, 0.0f, 0.0f);
//    glBegin(GL_POINTS);
//    glVertex2i(0,0);
//    glEnd();
//}
//
//void DesenhaDedo()
//{
//    glLineWidth(2);
//    glColor3f(0.0f, 0.0f, 1.0f);
//    glBegin(GL_QUADS);
//    glColor3f(1.0f, 0.0f, 0.5f);
//    glVertex2f(2.0,4.6);
//    glVertex2f(0.2,-0.8);
//    glColor3f(0.5f, 0.0f, 0.5f);
//    glVertex2f(-0.2,-0.8);
//    glVertex2f(-0.2, 4.6);
//    glEnd();
//    glPointSize(2);
//    glColor3f(0.0f, 0.0f, 0.0f);
//    glBegin(GL_POINTS);
//    glVertex2i(0,0);
//    glEnd();
//}
//
//// Função para desenhar a base do objeto
//void DesenhaBase()
//{
//    glLineWidth(2);
//    glColor3f(0.5f, 0.7f, 0.5f);
//    glBegin(GL_TRIANGLES);
//    glVertex2f(1.8,-0.8);
//    glVertex2f(-1.8,-0.8);
//    glVertex2f(0.0,1.5);
//    glEnd();
//}
//
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
//// Função callback de redesenho da janela de visualização
//void Desenha(void)
//{
//    // Muda para o sistema de coordenadas do modelo
//    glMatrixMode(GL_MODELVIEW);
//    // Inicializa a matriz de transformação corrente
//    glLoadIdentity();
//
//    // Limpa a janela de visualização com a cor de fundo definida previamente
//    glClear(GL_COLOR_BUFFER_BIT |  GL_DEPTH_BUFFER_BIT);
//
//    // Desenha um objeto modelado com transformações hierárquicas
//    glTranslatef(deslocamentoX,0.0f,0.0f); //Função de translação de acordo com o parâmetro deslocamentoX
//
//    glPushMatrix();
//
//    glPushMatrix();
//
//    glScalef(2.5f,2.5f,1.0f);
//    glColor3f(1.0f,0.0f,0.0f);
//    DesenhaBase();
//    glPopMatrix();
//
//    glDisable(GL_DEPTH_TEST);
//    glTranslatef(0.0f,1.5f,0.0f);
//    glRotatef(ang1,0.0f,0.0f,1.0f); //Função de Rotação de acordo com o parâmetro do ângulo (ang1)
//    glScalef(1.4f,1.4f,1.0f);
//    glColor3f(0.0f,1.0f,0.0f);
//    DesenhaBraco();
//    glEnable(GL_DEPTH_TEST);
//
//    glTranslatef(0.4f,2.6f,0.0f);
//    glRotatef(ang2,0.0f,0.0f,1.0f);//Função de Rotação de acordo com o parâmetro do ângulo (ang2)
//    glColor3f(0.0f,0.0f,1.0f);
//    DesenhaBraco();
//
//    glPushMatrix();
//    glTranslatef(0.0f, 4.5f,0.0f);
//    glRotatef(ang3,0.0f,0.0f,1.0f);//Função de Rotação de acordo com o parâmetro do ângulo (ang2)
//    glColor3f(0.0f,0.0f,1.0f);
//
//
//    DesenhaDedo();
//
//    glPopMatrix();
//
//    glPopMatrix();
//
//
//    glDisable(GL_DEPTH_TEST);
//    //elemento2 - mochila
//    glPushMatrix();
//    glTranslatef(25, 7.6, 0);
//    glScalef(escala, escala, 0);
//
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
//        gluOrtho2D (-win+panX, win+panX,
//                    -win*altura/largura+panY, win*altura/largura+panY);
//    else
//        gluOrtho2D (-win*largura/altura+panX, win*largura/altura+panX,
//                    -win+panY, win+panY);
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
//// Função callback chamada para gerenciar eventos de teclas especiais
//void TeclasEspeciais(int key, int x, int y){
//    switch(key){
//
//        case GLUT_KEY_LEFT:
//
//            deslocamentoX-= 2;
//            break;
//
//        case GLUT_KEY_RIGHT:
//
//            deslocamentoX+= 2;
//            break;
//
//
//        case GLUT_KEY_HOME:
//            ang1-=5;
//            break;
//
//        case GLUT_KEY_END:
//            ang1+=5;
//            break;
//
//        case GLUT_KEY_PAGE_DOWN:
//            ang2-=5;
//            break;
//
//        case GLUT_KEY_PAGE_UP:
//            ang2+=5;
//            break;
//
//        case GLUT_KEY_DOWN:
//            ang3-=5;
//            break;
//
//        case GLUT_KEY_UP:
//            ang3+=5;
//            break;
//
//
//    }
//    EspecificaParametrosDeVisualizacao();
//}
//
//
//void GerenciaMouse(int button, int state, int x, int y){
//    if (button == GLUT_LEFT_BUTTON)
//        if (win > 0){
//            deslocamentoX = 0.0f;
//            deslocamentoY = 0.0f;
//            win -= 5.0f;
//        }
//
//    if (button == GLUT_RIGHT_BUTTON)
//        if (win < 900)
//            win += 5.0f;
//
//    EspecificaParametrosDeVisualizacao();
//
//};
//
//
//// Função callback chamada para gerenciar eventos de teclas
//void Teclado (unsigned char key, int x, int y)
//{
//    switch(key){
//        case 119:
//            panY+=3.0f;
//            break;
//        case 115:
//            panY-=3.0f;
//            break;
//        case 97:
//            panX-=3.0f;
//            break;
//        case 100:
//            panX+=3.0f;
//            break;
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
//        case 27:
//            exit(0);
//            break;
//    }
//    EspecificaParametrosDeVisualizacao();
//
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
//    panX=panY=0.0f;
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
