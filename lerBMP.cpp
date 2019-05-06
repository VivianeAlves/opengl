//#define SIMPLE_OBJ_IMP
//
//#include <GL/glut.h>
//#include "simple_obj.h"
//#include <stdio.h>
//#include "carro.h"
//#include "axe.h"
//#include "banana.h"
//GLfloat CarPosZ = -2;
//GLfloat CarPosY = -5;
//GLfloat CarPosX = -1;
//
//
//GLfloat material_diffuse_car[] = {1.0, 0.0, 0.0, 1.0};
//GLfloat material_diffuse_ponte[] = {0.48, 0.63, 0.36, 1.0};
//GLfloat material_diffuse_lua[] = {0.5, 0.5, 0.5, 1.0};
//GLfloat material_diffuse_arvore[] = {0.0, 0.39, 0.0, 1.0};
//GLfloat light_position[] = {-5.0, 1.0, 1.0, 1.0};
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
//    gluPerspective(60, (GLfloat) w / (GLfloat) h, 2.0, 30.0);
//    glMatrixMode(GL_MODELVIEW);
//}
//
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glLoadIdentity();
//
//    gluLookAt(8, 0, 5,
//              5, 0, 3,
//              0, 1, 0);
//
//    //posi��o da luz
//    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//    glPushMatrix();
//    glTranslatef(CarPosX, CarPosY, CarPosZ);
////    glutSolidTeapot(1.0);
////glutSolidSphere(2,60,30);
//
//glTranslatef(0,6,2);
//glScalef(5,5,5);
//
//    glEnableClientState(GL_VERTEX_ARRAY); //enable vertex array
//    glEnableClientState(GL_NORMAL_ARRAY); //enable normal array
//    glEnableClientState(GL_TEXTURE_COORD_ARRAY); //enable texcoord array
//
//
//    glVertexPointer(3, GL_FLOAT, 0, carroVerts);
//    glNormalPointer(GL_FLOAT, 0, carroNormals);
//    glTexCoordPointer(2, GL_FLOAT, 0, carroTexCoords);
//    glDrawArrays(GL_TRIANGLES, 0, carroNumVerts);
//
//
//    glFlush();
//}
//
//void teclaNormal(unsigned char tecla, int x, int y) {
//    switch (tecla) {
//        case 'w':
//            if (CarPosZ < -30.0)
//                CarPosZ = 2.0;
//            else
//                CarPosZ--;
//            break;
//        case 's':
//            if (CarPosZ > 2.0)
//                CarPosZ = -30.0;
//            else
//                CarPosZ++;
//            break;
//        case 'a':
//            CarPosX--;
//            break;
//        case 'd':
//            CarPosX++;
//            break;
//        case 'g':
//            CarPosY--;
//            break;
//        case 't':
//            CarPosY++;
//            break;
//    }
//    glutPostRedisplay();
//}
//
//
//
//int main(int argc, char **argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
//    glutInitWindowSize(350, 350);
//    glutInitWindowPosition(0, 0);
//    glutCreateWindow("Cenario 1");
//    init();
//
//    glutDisplayFunc(display);
//    glutKeyboardFunc(teclaNormal);
//    glutReshapeFunc(reshape);
//    glutMainLoop();
//    return 0;
//}
