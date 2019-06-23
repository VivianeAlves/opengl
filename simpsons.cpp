//#include <GL/glut.h>
//#include <iostream>
//#include <cmath>
//#include "simpsonsModels.h"
//
//// angle of rotation for the camera direction
//float angle=0.0;
//bool cameraUp = 1;
//// XZ position of the camera
//float xEye=0.0f,zEye=7.5f;
//// Translation variables
//float tHomer = 1;
//float xHomer= -6, zHomer= 4,homerAngle = 0, homermotion2Angle = 0;;
//bool homerDirection = 1, homer1 = 1;
//float tMarge = 1;
//float xMarge= -6, zMarge= 4;
//bool margeDirection = 1;
//float tLisa = 1;
//float xLisa= -6, zLisa= 4, yLisa= 0;
//bool lisaDirection = 1,lisaZigzag = 0;
//float tBart = 1;
//float bartRotatex = 0,bartRotatez = 0, bartRotatey=0;
//float xBart= -6, zBart= 4,yBart = 0;
//bool bartDirection = 1, bart1 = 1;
//float tMillhouse = 1;
//float xMillhouse= -6, zMillhouse= 4, yMillhouse = 0;
//bool millhouseDirection = 1;
//float tKrusty = 1;
//float krustyAngle = 1;
//float xKrusty= -6, zKrusty= 4;
//bool krustyDirection = 1;
//// control booleans
//bool animate = 1, homerAnimate= 1, bartAnimate = 1, margeAnimate = 1, lisaAnimate = 1, krustyAnimate = 1, millhouseAnimate = 1;
//
//
//void wall(double thickness){
//	glPushMatrix();
//	glTranslated(0.5,0.5*thickness,0.5);
//	glScaled(1.0,thickness,1.0);
//	glutSolidCube(1);
//	glPopMatrix();
//}
//
//void drawWalls() {
//    // right wall
//	glColor3d(1,0,0);
//	glPushMatrix();
//	glTranslated(-7, 10, -7);
//	glRotated(90, 1, 0, 0);
//	glScaled(14, 14, 14);
//	wall(0.001);
//	glPopMatrix();
//	// left wall
//	glColor3d(1,0,0);
//    glPushMatrix();
//    glTranslated(-7,  -0.7, -7);
//	glRotated(90, 0, 0, 1);
//	glScaled(14, 14, 14);
//	wall(0.001);
//    glPopMatrix();
//    // right wall near
//	glColor3d(1,0,0);
//	glPushMatrix();
//	glTranslated(-7, 10, 7);
//	glRotated(90, 1, 0, 0);
//	glScaled(14, 14, 14);
//	wall(0.001);
//	glPopMatrix();
//	// left wall near
//	glColor3d(1,0,0);
//    glPushMatrix();
//    glTranslated(7,  -0.7, -7);
//	glRotated(90, 0, 0, 1);
//	glScaled(14, 14, 14);
//	wall(0.001);
//	glPopMatrix();
//
//	// floor
//	glColor3d(0,1,0);
//    glPushMatrix();
//    glTranslated(-7, -0.7, -7);
//	glScaled(14, 14, 14);
//	wall(0.001);
//	glPopMatrix();
//}
//
//void Reshape(int w, int h) {
//
//    // Prevent a divide by zero, when window is too short
//    if(h == 0)
//        h = 1;
//    float ratio = 1.0* w / h;
//
//    // Use the Projection Matrix
//    glMatrixMode(GL_PROJECTION);
//
//    // Reset Matrix
//    glLoadIdentity();
//
//    // Set the viewport to be the entire window
//    glViewport(0, 0, w, h);
//
//    // Set the correct perspective.
//    gluPerspective(45,ratio,1,1000);
//
//    // Get Back to the Modelview
//    glMatrixMode(GL_MODELVIEW);
//}
//
//void SetupLights(){
//	GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7, 1.0f };
//	GLfloat mat_diffuse[] = { 0.6f, 0.6f, 0.6, 1.0f };
//	GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0, 1.0f };
//	GLfloat mat_shininess[] = { 50 };
//	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
//	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
//	//set the light source properties
//	GLfloat lightIntensity[] = { 0.7f, 0.7f, 1, 1.0f };
//	GLfloat light_position[] = { -7.0f, 6.0f, 3.0f, 0.0f };
//	glLightfv(GL_LIGHT0, GL_POSITION, lightIntensity);
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
//}
//
//void setupCamera() {
//	glMatrixMode(GL_PROJECTION);
//    gluPerspective(0, 640 / 480, 0.001, 100);
//	glMatrixMode(GL_MODELVIEW);
//
//    if (cameraUp) {
//        gluLookAt(	0, 14.0f, 1,
//            0.0f, 0.0f,  0.0f,
//            0.0, 1.0f,  0.0);
//    } else {
//        gluLookAt(xEye, 1.0f, zEye,
//            0.0f, 1.0f,  0.0f,
//            0.0, 1.0f,  0.0);
//    }
//}
//
//void Key(unsigned char key, int x, int y) {
//
//	if (key==27)
//        exit(EXIT_SUCCESS);
//    if (key == 'b' || key == 'B'){
//        bart1 = !bart1;
//        if (bart1){
//            yBart = 0;
//            bartRotatey=0;
//        }else {
//            bartRotatex = 90;
//            bartRotatez = 90;
//        }
//    }
//    if (key == 'h' || key == 'H'){
//        homer1 = !homer1;
//        if (!homer1) {
//            homerAngle = 90;
//        }
//
//    }
//    if (key == 'a' || key == 'A'){
//
//        animate = !animate;
//    }
//
//    if (key == '1'){
//        homerAnimate = !homerAnimate;
//    }
//    if (key == '2'){
//        margeAnimate = !margeAnimate;
//    }
//    if (key == '3'){
//        lisaAnimate = !lisaAnimate;
//    }
//    if (key == '4'){
//        krustyAnimate = !krustyAnimate;
//    }
//    if (key == '5'){
//        bartAnimate = !bartAnimate;
//    }
//    if (key == '6'){
//        millhouseAnimate = !millhouseAnimate;
//    }
//
//	glutPostRedisplay();
//}
//
//void SpecialKeys(int key, int xx, int yy) {
//
//    float radius = 7.0f;
//
//    switch (key) {
//        case GLUT_KEY_UP :
//            cameraUp = !cameraUp;
//            break;
//    }
//
//    // ask OpenGL to recall the display function to reflect the changes on the window
//	glutPostRedisplay();
//}
//
//
//void Timer(int value) {
//    angle += 0.01f;
//    xEye = 7.5f * sin(angle) ;
//    zEye = 7.5f * cos(angle);
//    if (animate) {
//            if (homerAnimate) {
//            if ( homer1) {
//                moveHomer( &homerDirection ,&tHomer, &xHomer, &zHomer,&homerAngle);
//            } else {
//                moveHomer2(&xHomer, &zHomer,&homermotion2Angle,&homerAngle);
//            }
//        }
//        if (margeAnimate)
//            moveMarge( &margeDirection ,&tMarge, &xMarge, &zMarge);
//        if(lisaAnimate)
//            moveLisa( &lisaDirection ,&tLisa, &xLisa, &zLisa, &yLisa, &lisaZigzag);
//        if(krustyAnimate)
//            moveKrusty( &krustyDirection ,&tKrusty, &xKrusty, &zKrusty, &krustyAngle);
//        if(bartAnimate)
//            if (bart1) {
//                moveBart( &bartDirection ,&tBart, &xBart, &zBart,&bartRotatex, &bartRotatez);
//            }else {
//                moveBart2( &bartDirection ,&tBart, &xBart, &yBart, &bartRotatey);
//            }
//        if(millhouseAnimate)
//            moveMillhouse(&millhouseDirection ,&tMillhouse, &xMillhouse, &zMillhouse, &yMillhouse);
//    }
//    glutPostRedisplay();
//    glutTimerFunc(5, Timer, 0);
//}
//
//
//void Display(void){
//
//	//start drawing
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glLoadIdentity();
//
//	// Setup light
//	SetupLights();
//	//set the camera
//    setupCamera();
//
//    drawWalls();
//
//    glPushMatrix();
//    glTranslated(xHomer,0,zHomer);
//    glRotated(homerAngle,0,1,0);
//    glScaled(0.3,0.3,0.3);
//    modelHomer();
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(xMarge,0,zMarge);
//    glScaled(0.35,0.3,0.3);
//    modelMarge();
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(xLisa,yLisa,zLisa);
//    glScaled(0.35,0.3,0.3);
//    modelLisa();
//    glPopMatrix();
//
//
//    glPushMatrix();
//    glTranslated(xBart,yBart,zBart);
//    glRotated(bartRotatex,1,0,0);
//    glRotated(bartRotatez,0,0,1);
//    glRotated(bartRotatey,0,1,0);
//    glRotated(180,0,1,0);
//    glScaled(0.35,0.3,0.3);
//    modelBart();
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(xKrusty,0,zKrusty);
//    glRotated(krustyAngle,0,1,0);
//    glScaled(0.3,0.3,0.3);
//    modelKrusty();
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(xMillhouse,yMillhouse,zMillhouse);
//    glScaled(0.35,0.3,0.3);
//    modelMillhouse();
//    glPopMatrix();
//
//    glutSwapBuffers();
//
//}
//
//
//int main(int argc, char** argv) {
//    // Initialization
//	glutInit(&argc, argv);
//
//	glutInitWindowPosition(50, 50);
//	glutInitWindowSize(640, 480);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//    glutCreateWindow("a2");
//
//	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
//
//	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	glEnable(GL_NORMALIZE);
//	glEnable(GL_COLOR_MATERIAL);
//	glShadeModel(GL_SMOOTH);
//
//    // Calbacks
//    glutDisplayFunc(Display);
//    glutKeyboardFunc(Key);
//    glutReshapeFunc(Reshape);
//    glutSpecialFunc(SpecialKeys);
//    glutTimerFunc(0, Timer, 0);
//
//
//	glutMainLoop();
//
//	return 0;
//}