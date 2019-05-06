////
//// Created by Viviane Alves on 16/04/2019.
////
//#include <GL/glut.h>
//#include <stdlib.h>
//
////angulo de abertura da lente/camera
//GLfloat fAspect;
//
//void especifica_ParametrosVisualizacao() {
//    //especifica sistema de coordenação para projeção
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    //especifica a projeção perspectiva (angulo,aspecto,zNear)
//    gluPerspective(30, fAspect, 1.0, 500);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//    //       (obsX,osY,obsZ,Alvx,Alvy,Alvz,upX,upY,upZ)
//    gluLookAt(30, 20, 100, 0, 0, 0, 0, 1, 0);
//
//    /*
//     * Onde:
//     * obsX,osY,obsZ são usados para definir a posição da camera
//     * Alvx,Alvy,Alvz são usados para definir a posição do alvo
//     * upX,upY,upZ são as coordenadas que determinam o vetor up (o quando ele pode se mover pelas coordenadas)
//     * */
//}
//
//void desenha_piramide(){
//
//}
//
//void desenha_cubo() {
//
//    glColor3f(0, 0, 0);
//    glBegin(GL_POINTS);
//    glVertex3f(10, -10, 10);
//    glVertex3f(10, 10, 10);
//    glVertex3f(-10, 10, 10);
//    glVertex3f(-10, -10, 10);
//    glEnd();
//
//
//    glColor3f(1, 0, 0);
//    glBegin(GL_POLYGON);
//    glVertex3f(-10, -10, 10);
//    glVertex3f(-10, 10, 10);
//    glVertex3f(-10, 10, -10);
//    glVertex3f(-10, -10, -10);
//    glEnd();
//
//
//    glColor3f(1, 1, 0);
//    glBegin(GL_POLYGON);
//    glVertex3f(10, -10, -10);
//    glVertex3f(10, -10, 10);
//    glVertex3f(-10, -10, 10);
//    glVertex3f(-10, -10, -10);
//    glEnd();
//
//    glColor3f(0, 0, 1);
//    glBegin(GL_POLYGON);
//    glVertex3f(10, 10, 10);
//    glVertex3f(10, 10, -10);
//    glVertex3f(-10, 10, -10);
//    glVertex3f(-10, 10, 10);
//    glEnd();
//
//    glColor3f(0, 1, 0);
//    glBegin(GL_POLYGON);
//    glVertex3f(10, -10, -10);
//    glVertex3f(10, 10, -10);
//    glVertex3f(-10, 10, 10);
//    glVertex3f(-10, -10, 10);
//    glEnd();
//}
//
//
//void desenha(void) {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glClearColor(1.0, 1.0, 1.0, 1.0);
//    especifica_ParametrosVisualizacao();
//glColor3f(1,0,0);
//    glutWireTeapot(20);
//
//   // desenha_cubo();
//    glFlush();
//}
//
//
//
//void alterarTamanhoJanela(GLsizei w, GLsizei h) {
//    if (h == 0)
//        h = 1;
//
//    glViewport(0, 0, w, h);
//
//    //calcula a correção de abertura do espectro
//    fAspect = (GLfloat) w / (GLfloat) h;
//}
//
//void teclado(unsigned char key, int x, int y) {
//    if (key == 27) {
//        exit(0);
//    }
//}
//
//
//
//int main(int argc, char **argv) {
//    glutInit(&argc, argv);
//
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(500, 500);
//    glutCreateWindow("Aplicacao");
//
//    glutReshapeFunc(alterarTamanhoJanela);
//    glutDisplayFunc(desenha);
//
//
//    glutMainLoop();
//
//    return 0;
//}