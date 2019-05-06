////#define STB_IMAGE_IMPLEMENTATION
//#include <GL/glew.h>
//#include <GL/glut.h>
//#include <stdio.h>
////#include "OBJ_Loader.h"
//#include "banana.h"
//#include "axe.h"
//#include "bola.h"
//#include "carro.h"
//#include "RgbImage.h"
//GLuint textura[2];
//
//GLfloat CarPosZ = 3;
//GLfloat CarPosY = -5;
//GLfloat CarPosX = -3;
//
//GLfloat olhoX = 4;
//GLfloat olhoY = 11;
//GLfloat olhoZ = 3;
//
//GLfloat alvoX = 1;
//GLfloat alvoY = 6;
//GLfloat alvoZ = 1;
//
//
//GLfloat luzY = 1.0;
//GLfloat luzX = 1.0;
//
//GLfloat material_diffuse_banana[] = {1.0, 1.0, 0.0, 1.0};
//GLfloat light_position[] = {1.0, 1.0, 1.0, 1.0};
//
//void init(void) {
//    glClearColor(0.0, 0.0, 0.0, 0.0);
//    // glShadeModel(GL_SMOOTH);
//    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_LIGHTING);
//    glEnable(GL_LIGHT0);
//}
//
//
//void reshape(int w, int h) {
//    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluPerspective(60, (GLfloat) w / (GLfloat) h, 0.1, 30.0);
//    glMatrixMode(GL_MODELVIEW);
//}
//
//void especiais(int key, int x, int y) {
//
//    switch (key) {
//        case GLUT_KEY_UP:
//            luzY += 3;
//            break;
//        case GLUT_KEY_DOWN:
//            luzY -= 3;
//            break;
//        case GLUT_KEY_LEFT:
//            luzX += 3;
//            break;
//        case GLUT_KEY_RIGHT:
//            luzX -= 3;
//            break;
//    }
//    glutPostRedisplay();
//}
//
//
//void carregarTextura(char* arquivo, char* arquivo1){
//
//    RgbImage theTexMap(arquivo);
//
//}
//
//
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glLoadIdentity();
//
//    gluLookAt(olhoX, olhoY, olhoZ,
//              alvoX, alvoY, alvoZ,
//              0, 1, 0);
//
//
//    glEnable ( GL_TEXTURE_2D );
//    glBindTexture(GL_TEXTURE_2D, textura[0]);
//// set the texture wrapping/filtering options (on the currently bound texture object)
////desenha aqui....
//    char TextureFile[] = "C:\\Users\\Viviane Alves\\CLionProjects\\opengl\\1_store.bmp";
//
//
//
//
//
//    glEnableClientState(GL_VERTEX_ARRAY); //enable vertex array
//    glEnableClientState(GL_NORMAL_ARRAY); //enable normal array
//    glEnableClientState(GL_TEXTURE_COORD_ARRAY); //enable texcoord array
//    light_position[1] = luzY;
//    light_position[0] = luzX;
//    //posição luz
//    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//
//
//
//
//    glPushMatrix();
//    glTranslatef(CarPosX, CarPosY, CarPosZ);
////    glutSolidTeapot(1.0);
////glutSolidSphere(2,60,30);
//
//    //cor do material do objeto
////    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse_banana);
//
//    glTranslatef(1, 6, -6);
//
//    glScalef(10, 10, 10);
//
//    glVertexPointer(3, GL_FLOAT, 0, axeVerts);
//    glNormalPointer(GL_FLOAT, 0, axeNormals);
//    glTexCoordPointer(2, GL_FLOAT, 0, axeTexCoords);
//    glDrawArrays(GL_TRIANGLES, 0, axeNumVerts);
//
//
//
//    glPopMatrix();
//
//
////    glPushMatrix();
////    glTranslatef(-3, -3, -6);
////    //cor do material do objeto
////    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse_ponte);
////
////    //objl::Loader loader;
////    // loader.LoadFile("C:\\Users\\Viviane Alves\\Documents\\car.obj");
////
////    glPopMatrix();
//
//
//    glFlush();
//}
//
//void teclaNormal(unsigned char tecla, int x, int y) {
//    switch (tecla) {
//        case 'w':
//            CarPosZ--;
//            printf("CarPosZ:%f \n", CarPosZ);
//            break;
//        case 's':
//            CarPosZ++;
//            printf("CarPosZ:%f \n", CarPosZ);
//            break;
//        case 'a':
//            CarPosX--;
//            printf("CarPosX:%f \n", CarPosX);
//            break;
//        case 'd':
//            CarPosX++;
//            printf("CarPosX:%f \n", CarPosX);
//            break;
//        case 'g':
//            CarPosY--;
//            printf("CarPosY:%f \n", CarPosY);
//            break;
//        case 't':
//            CarPosY++;
//            printf("CarPosY:%f \n", CarPosY);
//            break;
//        case 'y':
//            olhoX++;
//            printf("Olho X:%f \n", olhoX);
//            break;
//        case 'u':
//            olhoY++;
//            printf("Olho Y:%f \n", olhoY);
//            break;
//        case 'i':
//            olhoZ++;
//            printf("Olho Z:%f \n", olhoZ);
//            break;
//        case 'j':
//            olhoX--;
//            printf("Olho X:%f \n", olhoX);
//            break;
//        case 'k':
//            olhoY--;
//            printf("Olho Y:%f \n", olhoZ);
//            break;
//        case 'l':
//            olhoZ--;
//            printf("Olho Z:%f \n", olhoZ);
//            break;
//        case 'z':
//            alvoX++;
//            printf("AlvoX:%f \n", alvoX);
//            break;
//        case 'x':
//            alvoY++;
//            printf("AlvoY:%f \n", alvoY);
//            break;
//        case 'c':
//            alvoZ++;
//            printf("AlvoZ:%f \n", alvoZ);
//            break;
//        case 'v':
//            alvoX--;
//            printf("AlvoX:%f \n", alvoX);
//            break;
//        case 'b':
//            alvoY--;
//            printf("AlvoY:%f \n", alvoY);
//            break;
//        case 'n':
//            alvoZ--;
//            printf("AlvoZ:%f \n", alvoZ);
//            break;
//
//
//    }
//    glutPostRedisplay();
//}
//
//
//int main(int argc, char **argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
//    glutInitWindowSize(350, 350);
//    glutInitWindowPosition(0, 0);
//    glutCreateWindow("Banana");
//    init();
//    glutDisplayFunc(display);
//    glutKeyboardFunc(teclaNormal);
//    glutSpecialFunc(especiais);
//    glutReshapeFunc(reshape);
//    glutMainLoop();
//    return 0;
//}
