//#define SIMPLE_OBJ_IMP
//#include <GL/glut.h>
//#include "simple_obj.h"
//
//
//
//GLfloat rotateX;
//GLfloat rotateY;
//
//GLfloat luzY = 1.0;
//GLfloat luzX = 1.0;
//GLfloat material_diffuse_monkey[] = {1.0, 0.0, 0.0, 1.0};
//GLfloat material_diffuse_pillar[] = {1.0, 1.0, 0.0, 1.0};
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
//    gluPerspective(45.0, (GLfloat) w / (GLfloat) h, 2.0, 20.0);
//    glMatrixMode(GL_MODELVIEW);
//}
//
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glLoadIdentity();
//
//    gluLookAt(2, 4, 2,
//              0, 0, 0,
//              0, 1, 0);
//
//    //posição da luz
//    light_position[1] = luzY;
//    light_position[0] = luzX;
//    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//    glPushMatrix();
//    glTranslatef(-1, -5, -3);
//  //  glutSolidTeapot(1.0);
////glutSolidSphere(2,60,30);
//
//    glRotatef(-90, 1, 0, 0);
//    //cor do material do objeto
//    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse_monkey);
//    SimpleObj_t *myObj = loadObj("C:\\Users\\Viviane Alves\\Documents\\Axe.obj");
//    drawObj(myObj);
//    glPopMatrix();
//
////
////    glPushMatrix();
////    glTranslatef(-3, -3, -1);
////
////    //cor do material do objeto
////    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse_pillar);
////
////
////
////
////
////
////    SimpleObj_t *myObj1 = loadObj("C:\\Users\\Viviane Alves\\Desktop\\MarioTyper-master\\3DGame\\res\\mario_obj.obj");
////    drawObj(myObj1);
////    glPopMatrix();
//
//    glFlush();
//}
//
//void teclado(int key, int x, int y) {
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
//int main(int argc, char **argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
//    glutInitWindowSize(350, 350);
//    glutInitWindowPosition(0, 0);
//    glutCreateWindow("Material Ambience");
//    init();
//
//    glutDisplayFunc(display);
//    glutReshapeFunc(reshape);
//    glutSpecialFunc(teclado);
//    glutMainLoop();
//    return 0;
//}
