////
//// Created by Viviane Alves on 04/05/2019.
////
//
//// Textura.cpp - Isabel H. Manssour
//// Um programa OpenGL que exemplifica a visualização
//// de objetos 3D com mapeamento de textura.
//// Este código está baseado nos exemplos disponíveis no livro
//// "OpenGL SuperBible", 2nd Edition, de Richard S. e Wright Jr.
//
//#include <gl/glut.h>
//#include <stdio.h>
//#include "glaux.h"
//#include "banana.h"
//#include "basket.h"
//#include "bandeja2.h"
//#include "table.h"
//
//
//
//#define NUM_TEXTURES 4
//
//GLuint textureIDs[NUM_TEXTURES];
//GLuint currentTextureFilter=0;
//AUX_RGBImageRec *imagemTextura;
//AUX_RGBImageRec *imagemTextura2;
//AUX_RGBImageRec *imagemTextura3;
//AUX_RGBImageRec *imagemTextura4;
//
//
//GLfloat posx=1,posy=0,posz=2.5;
//
//
////Função para Carregar uma imagem .BMP
//AUX_RGBImageRec *LoadBMP(char *Filename){
//   FILE *File=NULL;
//   if (!Filename) {
//       return NULL;
//   }
//   File=fopen(Filename,"r");
//   if (File)	// Se o arquivo existe
//   {
//       fclose(File);
//       return auxDIBImageLoad(Filename);//Retorna a imagem
//   }
//   return NULL;
//}
//
//// Variáveis globais
//GLfloat angle, fAspect, rotX, rotY, obsZ;
//GLuint idTextura;
//// AUX_RGBImageRec *imagemTextura;
//
//// Função responsável pela especificação dos parâmetros de iluminação
//void DefineIluminacao (void)
//{
//   GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0};
//   GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};	   // "cor"
//   GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};// "brilho"
//   GLfloat posicaoLuz[4]={0.0, -40.0, 0.0, 1.0};
//
//   // Capacidade de brilho do material
//   GLfloat especularidade[4]={1.0,1.0,1.0,1.0};
//   GLint especMaterial = 60;
//
//   // Define a refletância do material
//   glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
//   // Define a concentração do brilho
//   glMateriali(GL_FRONT,GL_SHININESS,especMaterial);
//
//   // Ativa o uso da luz ambiente
//   glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);
//
//   // Define os parâmetros da luz de número 0
//   glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
//   glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
//   glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
//   glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );
//
//   // Habilita o modelo de colorização de Gouraud
//   glShadeModel(GL_SMOOTH);
//}
//
//// Função callback chamada para fazer o desenho
//
//
//
//void DesenhaMesa(){
//	glEnableClientState(GL_VERTEX_ARRAY); //enable vertex array
//   glEnableClientState(GL_NORMAL_ARRAY); //enable normal array
//   glEnableClientState(GL_TEXTURE_COORD_ARRAY); //enable texcoord array
//
//   glVertexPointer(3, GL_FLOAT, 0, tableVerts);
//   glNormalPointer(GL_FLOAT, 0, tableNormals);
//   glTexCoordPointer(2, GL_FLOAT, 0, tableTexCoords);
//   glDrawArrays(GL_TRIANGLES, 0, tableNumVerts);
//}
//
//void DesenhaCesta(){
//	glEnableClientState(GL_VERTEX_ARRAY); //enable vertex array
//   glEnableClientState(GL_NORMAL_ARRAY); //enable normal array
//   glEnableClientState(GL_TEXTURE_COORD_ARRAY); //enable texcoord array
//
//   glVertexPointer(3, GL_FLOAT, 0, bandeja2Verts);
//   glNormalPointer(GL_FLOAT, 0, bandeja2Normals);
//   glTexCoordPointer(2, GL_FLOAT, 0, bandeja2TexCoords);
//   glDrawArrays(GL_TRIANGLES, 0, bandeja2NumVerts);
//}
//
//
//void DesenhaBanana(){
//glEnableClientState(GL_VERTEX_ARRAY); //enable vertex array
//   glEnableClientState(GL_NORMAL_ARRAY); //enable normal array
//   glEnableClientState(GL_TEXTURE_COORD_ARRAY); //enable texcoord array
//
//   glVertexPointer(3, GL_FLOAT, 0, bananaVerts);
//   glNormalPointer(GL_FLOAT, 0, bananaNormals);
//   glTexCoordPointer(2, GL_FLOAT, 0, bananaTexCoords);
//   glDrawArrays(GL_TRIANGLES, 0, bananaNumVerts);
//}
//
//void caixa(){
//	 // Desenha um cubo no qual a textura é aplicada
//   glBegin ( GL_QUADS );
//   // Face frontal
//   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
//   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
//   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
//   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
//   // Face posterior
//   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
//   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
//   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
//   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
//    //Face superior
//   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
//   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
//   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
//   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
//   // Face inferior
//   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
//   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
//   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
//   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
//   // Face lateral direita
//   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
//   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
//   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
//   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
//   // Face lateral esquerda
//   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
//   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
//   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
//   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
//   glEnd();
//
//}
//
//
//void Desenha(void)
//{
//   // Limpa a janela e o depth buffer
//	  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//
//	  glPushMatrix();
//	   glEnable(GL_TEXTURE_2D);  // Enable 2D texture
//	   glTranslatef(posx,posy,posz);
//	  glScalef(0.3,0.3,0.3);
//	  glBindTexture(GL_TEXTURE_2D, textureIDs[0]);  // Select the texture
//	  caixa();
//	  glDisable(GL_TEXTURE_2D);
//	  glPopMatrix();
//
//
//  glPushMatrix();
//  glTranslatef(2.5,0,2);
//  glScalef(2,2,2);
//  glEnable(GL_TEXTURE_2D);  // Enable 2D texture
//   glBindTexture(GL_TEXTURE_2D, textureIDs[1]);  // Select the texture
//  DesenhaMesa();
//  glDisable(GL_TEXTURE_2D);
//  glPopMatrix();
//
//  glPushMatrix();
//  //jogar translação objetos
//  glTranslatef(0,0.58,0);
//
//    glPushMatrix();
//  glTranslatef(2.5,0,2);
//  glScalef(0.5,0.5,0.5);
//  glEnable(GL_TEXTURE_2D);  // Enable 2D texture
//   glBindTexture(GL_TEXTURE_2D, textureIDs[2]);  // Select the texture
//  DesenhaBanana();
//  glDisable(GL_TEXTURE_2D);
//  glPopMatrix();
//
//
//	   glPushMatrix();
//	    glTranslatef(2.5,-0.02,2);
//	   glRotatef(-90,0,1,0);
//
//  glEnable(GL_TEXTURE_2D);  // Enable 2D texture
//   glBindTexture(GL_TEXTURE_2D, textureIDs[3]);  // Select the texture
//  DesenhaCesta();
//  glDisable(GL_TEXTURE_2D);
//  glPopMatrix();
//   glPopMatrix();
//
//   glutSwapBuffers();
//}
//
//// Função usada para especificar a posição do observador virtual
//void PosicionaObservador(void)
//{
//   // Especifica sistema de coordenadas do modelo
//   glMatrixMode(GL_MODELVIEW);
//   // Inicializa sistema de coordenadas do modelo
//   glLoadIdentity();
//   DefineIluminacao();
//   // Especifica posição do observador e do alvo
//   glTranslatef(0,0,-obsZ);
//   glRotatef(rotX,1,0,0);
//   glRotatef(rotY,0,1,0);
//}
//
//// Inicializa parâmetros de rendering
//void Inicializa (void)
//{
//   // Define a cor de fundo da janela de visualização como preta
//   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//
//   // Habilita a definição da cor do material a partir da cor corrente
//   glEnable(GL_COLOR_MATERIAL);
//   //Habilita o uso de iluminação
//   glEnable(GL_LIGHTING);
//   // Habilita a luz de número 0
//   glEnable(GL_LIGHT0);
//   // Habilita o depth-buffering
//   glEnable(GL_DEPTH_TEST);
//
//   // Inicializa a variável que especifica o ângulo da projeção
//   // perspectiva
//   angle=50;
//
//   // Inicializa as variáveis usadas para alterar a posição do
//   // observador virtual
//   rotX = 30;
//   rotY = 0;
//   obsZ = 10;
//
//   // Comandos de inicialização para textura
//   imagemTextura = LoadBMP("C:\\Users\\casa\\Documents\\CIENCIA DA COMPUTACAO\\8 SEMESTRE\\COMPUTACAO GRAFICA\\opengl-master\\texturas\\1_store.bmp");
//
//    glGenTextures(NUM_TEXTURES, textureIDs);
//
//    // Texture ID 0: Use nearest filter which point-samples the texture with interpolation
//   glBindTexture(GL_TEXTURE_2D, textureIDs[0]);
//   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
// glTexImage2D(GL_TEXTURE_2D, 0, 3, imagemTextura->sizeX,
//                imagemTextura->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE,
//                imagemTextura->data);
//
//  imagemTextura2 = LoadBMP("C:\\Users\\casa\\Documents\\CIENCIA DA COMPUTACAO\\8 SEMESTRE\\COMPUTACAO GRAFICA\\opengl-master\\texturas\\darkwood.bmp");
//   // Texture ID 1: Use linear filter which average 2x2 texels for smoother appearance
//   glBindTexture(GL_TEXTURE_2D, textureIDs[1]);
//   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//   glTexImage2D(GL_TEXTURE_2D, 0, 3, imagemTextura2->sizeX,
//                imagemTextura2->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE,
//                imagemTextura2->data);
//
//
//			imagemTextura3 = LoadBMP("C:\\Users\\casa\\Documents\\CIENCIA DA COMPUTACAO\\8 SEMESTRE\\COMPUTACAO GRAFICA\\opengl-master\\texturas\\banana.bmp");
//			 glBindTexture(GL_TEXTURE_2D, textureIDs[2]);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//   glTexImage2D(GL_TEXTURE_2D, 0, 3, imagemTextura3->sizeX,
//                imagemTextura3->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE,
//                imagemTextura3->data);
//
//
//   imagemTextura4 = LoadBMP("C:\\Users\\casa\\Documents\\CIENCIA DA COMPUTACAO\\8 SEMESTRE\\COMPUTACAO GRAFICA\\opengl-master\\texturas\\palha.bmp");
//			 glBindTexture(GL_TEXTURE_2D, textureIDs[3]);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//   glTexImage2D(GL_TEXTURE_2D, 0, 3, imagemTextura4->sizeX,
//                imagemTextura4->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE,
//                imagemTextura4->data);
//
//
//}
//
//// Função usada para especificar o volume de visualização
//void EspecificaParametrosVisualizacao(void)
//{
//   // Especifica sistema de coordenadas de projeção
//   glMatrixMode(GL_PROJECTION);
//   // Inicializa sistema de coordenadas de projeção
//   glLoadIdentity();
//
//   // Especifica a projeção perspectiva(angulo,aspecto,zMin,zMax)
//   gluPerspective(angle,fAspect,0.5,500);
//
//   PosicionaObservador();
//}
//
//// Função callback chamada quando o tamanho da janela é alterado
//void AlteraTamanhoJanela(GLsizei w, GLsizei h)
//{
//   // Para previnir uma divisão por zero
//   if ( h == 0 ) h = 1;
//
//   // Especifica as dimensões da viewport
//   glViewport(0, 0, w, h);
//
//   // Calcula a correção de aspecto
//   fAspect = (GLfloat)w/(GLfloat)h;
//
//   EspecificaParametrosVisualizacao();
//}
//
//
//
//
//// Função callback chamada para gerenciar eventos do mouse
//void GerenciaMouse(int button, int state, int x, int y)
//{
//   if (button == GLUT_LEFT_BUTTON)
//       if (state == GLUT_DOWN) {  // Zoom-in
//           if (angle >= 10) angle -= 5;
//       }
//   if (button == GLUT_RIGHT_BUTTON)
//       if (state == GLUT_DOWN) {  // Zoom-out
//           if (angle <= 130) angle += 5;
//       }
//   EspecificaParametrosVisualizacao();
//   glutPostRedisplay();
//}
//
//// Callback para gerenciar eventos do teclado para teclas especiais
//void TeclasEspeciais(int key, int x, int y)
//{
//   switch (key)
//   {
//       case GLUT_KEY_LEFT:rotY--;
//           break;
//       case GLUT_KEY_RIGHT:rotY++;
//           break;
//       case GLUT_KEY_UP:rotX++;
//           break;
//       case GLUT_KEY_DOWN:rotX--;
//           break;
//       case GLUT_KEY_HOME:obsZ++;
//           break;
//       case GLUT_KEY_END:obsZ--;
//           break;
//       case GLUT_KEY_F10:// "camera reset"
//           rotX=30;
//           rotY=0;
//           obsZ=10;
//           angle=50;
//           EspecificaParametrosVisualizacao();
//
//           break;
//   }
//   PosicionaObservador();
//   glutPostRedisplay();
//}
//
//
//void Teclas(unsigned char key, int x, int y)
//{
//   switch (key)
//   {
//       case 'a':posx-=0.5;
//	   printf("posx: %f",posx);
//           break;
//       case 'd':posx+=0.5;
//       printf("posx: %f",posx);
//           break;
//       case 's':posy-=0.5;
//       printf("posy: %f",posy);
//           break;
//       case 'w':posy+=0.5;
//       printf("posy: %f",posy);
//           break;
//       case 't':posz+=0.5;
//       printf("posz: %f",posz);
//           break;
//       case 'g':posz-=0.5;
//       printf("posz: %f",posz);
//           break;
//   }
//  // PosicionaObservador();
//   glutPostRedisplay();
//}
//
//
//// Programa Principal
//int main(int argc, char **argv)
//{
//   glutInit(&argc, argv);
//   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//   glutInitWindowSize(400,350);
//   glutCreateWindow("Visualizacao 3D com Mapeamento de Textura");
//   glutDisplayFunc(Desenha);
//   glutReshapeFunc(AlteraTamanhoJanela);
//   glutMouseFunc(GerenciaMouse);
//   glutSpecialFunc(TeclasEspeciais);
//   glutKeyboardFunc(Teclas);
//   Inicializa();
//   glutMainLoop();
//}