//
//Acadêmicas: Marcia Cristina e Viviane Alves
//

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include "primitive.h"

#define NUM_TEXTURA 5

int statusLuz;
float angulo_torso;

// variaveis android
float angulo_cabeca;

float angulo_braco_esq;
float angulo_braco_esq_w;

float angulo_braco_dir;
float angulo_braco_dir_w;

float angulo_perna_x_esq;
float angulo_perna_x_dir;

float angulo_robo_x;
float angulo_robo_y;
float angulo_robo_z;

float escala_obj1;
float escala_obj2;
float escala_obj3;

float angulo_da_camera;

GLfloat aspecto;

GLfloat rotX_ini, rotY_ini;
GLfloat obsX_ini, obsY_ini, obsZ_ini;

float upX;
GLint x_ini, y_ini, bot;

GLfloat angle, fAspect;
GLfloat rotaciona_x, rotY;
GLfloat obsX, obsY, obsZ;

/*Variaveis cachorro*/
GLfloat angulo_x_cabeca_dog,
        angulo_y_cabeca_dog,
        angulo_x_rabo_dog,
        angulo_y_rabo_dog,
        angulo_movimento_rabo_dog,
        angulo_perna_dog;

//Variavel de mudança de luz
GLfloat posX;
GLfloat posY;
GLfloat posZ;

//variaveis camera e alvox
GLfloat camX, camY, camZ;
GLfloat alvoX, alvoY, alvoZ;

GLuint texture_id[NUM_TEXTURA];


struct tipo_luz {
    GLfloat posicao[4];
    GLfloat ambiente[4];
    GLfloat difusa[4];
    GLfloat especular[4];
    GLfloat especularidade[4];
};

struct tipo_luz luz;


char *texture_name[NUM_TEXTURA] = {"C:\\Users\\Viviane Alves\\CLionProjects\\opengl\\texturas\\darkwood.bmp",
                                   "C:\\Users\\Viviane Alves\\CLionProjects\\opengl\\texturas\\win030.bmp",
                                   "C:\\Users\\Viviane Alves\\CLionProjects\\opengl\\texturas\\tijolo.bmp"};

int LoadBMP(char *filename, bool mipmap) {
#define SAIR        {fclose(fp_arquivo); return -1;}
#define CTOI(C)     (*(int*)&C)

    GLubyte *image;
    GLubyte Header[0x54];
    GLuint DataPos, imageSize;
    GLsizei Width, Height;

    int nb = 0;

    FILE *fp_arquivo = fopen(filename, "rb");
    if (!fp_arquivo)
        return -1;
    if (fread(Header, 1, 0x36, fp_arquivo) != 0x36) SAIR;
    if (Header[0] != 'B' || Header[1] != 'M') SAIR;
    if (CTOI(Header[0x1E]) != 0) SAIR;
    if (CTOI(Header[0x1C]) != 24) SAIR;

    Width = CTOI(Header[0x12]);
    Height = CTOI(Header[0x16]);
    (CTOI(Header[0x0A]) == 0) ? (DataPos = 0x36) : (DataPos = CTOI(Header[0x0A]));

    imageSize = Width * Height * 3;

    image = (GLubyte *) malloc(imageSize);
    int retorno;
    retorno = fread(image, 1, imageSize, fp_arquivo);

    if (retorno != imageSize) {
        free(image);
        SAIR;
    }

    int t, i;

    for (i = 0; i < imageSize; i += 3) {
        t = image[i];
        image[i] = image[i + 2];
        image[i + 2] = t;
    }


    if (mipmap) {
        gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, Width, Height, GL_RGB,
                          GL_UNSIGNED_BYTE, image);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    } else {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Width, Height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }


    fclose(fp_arquivo);
    free(image);
    return 1;
}


void Texturizacao(void) {
    int i;

    glEnable(GL_TEXTURE_2D);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenTextures(NUM_TEXTURA, texture_id);

    for (i = 0; i < NUM_TEXTURA; i++) {
        glBindTexture(GL_TEXTURE_2D, texture_id[i]);
        LoadBMP(texture_name[i], false);
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_CLAMP);
}


void Define_Iluminacao() {

    glShadeModel(GL_SMOOTH);

    glEnable(GL_LIGHTING);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luz.ambiente);

    glLightfv(GL_LIGHT0, GL_POSITION, luz.posicao);

    glLightfv(GL_LIGHT0, GL_AMBIENT, luz.ambiente);

    glLightfv(GL_LIGHT0, GL_DIFFUSE, luz.difusa);

    glLightfv(GL_LIGHT0, GL_SPECULAR, luz.especular);

    if (statusLuz == 1) {
        glEnable(GL_LIGHT0);
    } else {
        glDisable(GL_LIGHT0);
    }

    glEnable(GL_COLOR_MATERIAL);

    glMaterialfv(GL_FRONT, GL_SPECULAR, luz.especularidade);

    glMateriali(GL_FRONT, GL_SHININESS, 10);

}


void android() {
    glPushMatrix();
    // torso
    glColor3f(0.0, 0.0, 0.0);
    glRotatef(angulo_torso, 1, 0, 0);
    glTranslatef(0.0, -50.0, 0.0);
    DrawCylinder(160, 160, 200);
    glPushMatrix();

    // ombro esquerdo
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(-175, 50, 0);
    glRotatef(90, 0, 0, 1);
    glRotatef(angulo_braco_esq, 0, 1, 0);
    glRotatef(angulo_braco_esq_w, 0, 0, 1);
    DrawSphere(35);

    // braco esquerdo
    glTranslatef(-60, 0, 0);
    glRotatef(90, 0, 0, 1);
    DrawCylinder(35, 35, 120);

    // palma esquerda
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(0, 90, 0);
    DrawCylinder(35, 35, 60);

    glTranslatef(0, 25, 0);
    DrawSphere(35);


    glRotatef(-145, 0, 0, 1);
    glPopMatrix();
    glPushMatrix();

    // ombro direito
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(175, 50, 0);
    glRotatef(90, 0, 0, 1);
    glRotatef(angulo_braco_dir, 0, 1, 0);
    glRotatef(angulo_braco_dir_w, 0, 0, 1);
    DrawSphere(35);

    // braco direito
    glTranslatef(-60, 0, 0);
    glRotatef(-90, 0, 0, 1);
    DrawCylinder(35, 35, 120);

    // palma direita
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(0, -90, 0);
    DrawCylinder(35, 35, 60);

    glTranslatef(0, -25, 0);
    DrawSphere(35);


    glRotatef(145, 0, 0, 1);
    glPopMatrix();
    glPushMatrix();


    // cabeca mickey mouse
    glColor3f(0.0, 0.0, 0.0);
    glRotatef(angulo_cabeca, 0, 1, 0);
    glTranslatef(0.0, 100.0, 0.0);
    DrawSphere(150);

    glPushMatrix();
    // orelhas
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(150.0, 150.0, 0.0);
    glRotatef(90, 1, 0, 0);
    DrawCylinder(80, 80, 20);

    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(-300, 0, 0);
    DrawCylinder(80, 80, 20);

    glPopMatrix();
    glPushMatrix();

    // cabeça android
    glColor3f(0, 1, 0);
    glTranslatef(0, 0, 5);
    DrawSphere(150);

    // olhos
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(-50, 65, 116);
    glRotatef(90, 1, 0, 0);
    DrawCylinder(10, 10, 30);

    glTranslatef(100, 0, 0);
    DrawCylinder(10, 10, 30);

    glRotatef(-90, 1, 0, 0);


    // contorno boca
    glTranslatef(-50, -61, -120);
    DrawCylinder(155, 155, 5);

    glPopMatrix();


    glRotatef(-90, 1, 0, 0);
    glPopMatrix();

    glPopMatrix();

    // calças
    glColor3f(1.0, 0.0, 0.0);
    glTranslatef(0.0, -100, 0.0);
    DrawCylinder(161, 161, 165);

    glPushMatrix();

    // botões
    glColor3f(1.0, 1.0, 1.0);
    glRotatef(90, 1, 0, 0);
    glTranslatef(50, 145, -20);
    DrawCylinder(40, 40, 35);
    glTranslatef(-100, 0, 0);
    DrawCylinder(40, 40, 35);

    // rabo
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(50, -350, 0);
    DrawCylinder(10, 10, 200);

    glTranslatef(0, -100, 0);
    DrawSphere(10);

    glRotatef(-90, 1, 0, 0);
    glPopMatrix();
    glPushMatrix();



    // tronco inferior esquerdo
    glColor3f(0.0, 0.0, 0.0);
    glRotatef(angulo_perna_x_esq, 1, 0, 0);
    glTranslatef(-70, -50, 0.0);
    DrawSphere(60);

    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(0, -80, 0);
    DrawCylinder(35, 35, 60);

    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(0, -50, 0);
    DrawCylinder(65, 65, 40);

    glPopMatrix();
    glPushMatrix();

    // tronco inferior direito

    glColor3f(0.0, 0.0, 0.0);
    glRotatef(angulo_perna_x_dir, 1, 0, 0);
    glTranslatef(70, -50.0, 0.0);
    DrawSphere(60);

    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(0, -80, 0);
    DrawCylinder(35, 35, 60);

    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(0, -50, 0);
    DrawCylinder(65, 65, 40);

    glPopMatrix();

}

void dog() {
    glPushMatrix();
    GLfloat color[4] = {0.92f, 0.814f, 0.382f, 1.0f};
    glColor4fv(color);
    GLfloat dog_shininess = 0.1f;

    glMaterialf(GL_FRONT, GL_SHININESS, dog_shininess);
    glMaterialf(GL_FRONT, GL_EMISSION, 0);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);

    //torso
    glPushMatrix();
    glScalef(2.0f * 0.3f, 2.0f * 0.3f, 4.0f * 0.3f);
    glutSolidSphere(1, 30, 30);
    glPopMatrix();

    //pernas
    glPushMatrix();
    glRotatef(angulo_perna_dog, 1, 0, 0);
    glTranslated(-1 * 0.3, -2.5 * 0.3, -2 * 0.3);
    glScalef(0.5f * 0.3f, 2.0f * 0.3f, 0.5f * 0.3f);
    glutSolidSphere(1, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-angulo_perna_dog, 1, 0, 0);
    glTranslated(0.3f, -2.5f * 0.3f, -0.6);
    glScalef(0.5f * 0.3f, 0.6f, 0.5f * 0.3f);
    glutSolidSphere(1, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glRotatef(angulo_perna_dog, 1, 0, 0);
    glTranslated(0.3f, -2.5f * 0.3f, 2.0 * 0.3f);
    glScalef(0.5f * 0.3f, 2.0f * 0.3f, 0.5f * 0.3f);
    glutSolidSphere(1, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-angulo_perna_dog, 1, 0, 0);
    glTranslated(-0.3f, -2.5f * 0.3f, 0.6);
    glScalef(0.5f * 0.3f, 2.0f * 0.3f, 0.5f * 0.3f);
    glutSolidSphere(1, 30, 30);
    glPopMatrix();

    //rabo
    glPushMatrix();
    glTranslated(0.0f, 0.0f, -3.8f * 0.3f);
    glRotatef(-30, 1, 0, 0);
    glRotatef(angulo_y_rabo_dog, 1, 0, 0);
    glRotatef(angulo_x_rabo_dog, 0, 1, 0);
    glRotatef(angulo_movimento_rabo_dog, 0, 1, 0);
    glScalef(0.5f * 0.3f, 0.5f * 0.3f, 1.8f * 0.3f);

    glutSolidSphere(1, 30, 30);
    glPopMatrix();

    //rotacao da cabeça
    glPushMatrix();
    glRotatef(angulo_y_cabeca_dog, 1, 0, 0);
    glRotatef(angulo_x_cabeca_dog, 0, 1, 0);

    //cabeça
    glPushMatrix();
    glTranslated(0.0f, 2.5f * 0.3f, 3.0f * 0.3f);
    glScalef(1.5f * 0.3f, 1.55f * 0.3f, 1.6f * 0.3f);
    glutSolidSphere(1, 30, 30);
    glPopMatrix();

    //nariz
    glPushMatrix();
    glTranslated(0.0f, 2.2f * 0.3f, 4.2f * 0.3f);
    glScalef(0.8f * 0.3f, 0.5f * 0.3f, 1.5f * 0.3f);
    glutSolidSphere(1, 30, 30);
    glPopMatrix();

    //orelhas
    glPushMatrix();
    glTranslated(-0.8f * 0.3f, 3.8f * 0.3f, 2.6f * 0.3f);
    glScalef(0.5f * 0.3f, 0.3f, 0.5f * 0.3f);
    glutSolidSphere(1, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.8f * 0.3f, 3.8f * 0.3f, 2.6f * 0.3f);
    glScalef(0.5f * 0.3f, 1.0f * 0.3f, 0.5f * 0.3f);
    glutSolidSphere(1, 30, 30);
    glPopMatrix();

    //olhos
    GLfloat eyes_specular[] = {0.4f, 0.4f, 0.4f},
            eyes_shininess = 1.0f;
    GLfloat black[] = {0, 0, 0, 1};
    glColor4fv(black);

    glMaterialfv(GL_FRONT, GL_SPECULAR, eyes_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, eyes_shininess);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, black);

    glPushMatrix();
    glTranslated(0.5f * 0.3f, 3.0f * 0.3f, 4.4f * 0.3f);
    glScalef(0.25f * 0.3f, 0.25f * 0.3f, 0.25f * 0.3f);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.5f * 0.3f, 3.0f * 0.3f, 4.4f * 0.3f);
    glScalef(0.25f * 0.3f, 0.25f * 0.3f, 0.25f * 0.3f);
    glutSolidCube(1);
    glPopMatrix();

    glPopMatrix();

    glPopMatrix();
}

void mesa() {
    glPushMatrix();
    GLfloat color[4] = {0.651f, 0.502f, 0.392f, 1.0f};
    glColor4fv(color);

    GLfloat shininess = 0.3f;

    glMaterialf(GL_FRONT, GL_SHININESS, shininess);
    glMaterialf(GL_FRONT, GL_EMISSION, 0);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
    glScalef(0.3f, 0.3f, 0.3f);


    //tampo
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture_id[2]);
    glScalef(7, 0.5, 7);
    glutSolidCube(1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //pernas
    glPushMatrix();
    glTranslated(-2.5, -1.75, -2);
    glScalef(1, 3.5, 1);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(2.5, -1.75, -2);
    glScalef(1, 3.5, 1);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-2.5, -1.75, 2);
    glScalef(1, 3.5, 1);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(2.5, -1.75, 2);
    glScalef(1, 3.5, 1);
    glutSolidCube(1);
    glPopMatrix();

    glPopMatrix();
}


void EspecificaParametrosVisualizacao(void) {

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(angulo_da_camera, aspecto, 0.1, 5000.0);

    glTranslatef(-obsX, -obsY, -obsZ);
    glRotatef(rotaciona_x, 1, 0, 0);
    glRotatef(rotY, 0, 1, 0);
}


void Desenha(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    EspecificaParametrosVisualizacao();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(camX, camY, camZ,
              alvoX, alvoY, alvoZ,
              upX, 1, 0);

    Define_Iluminacao();

    //ponto de luz
    glPushMatrix();
    glColor4f(1.0, 1.0, 1.0, 1.0);
    luz.posicao[0] = posX;
    luz.posicao[1] = posY;
    luz.posicao[2] = posZ;
    glTranslatef(luz.posicao[0], luz.posicao[1], luz.posicao[2]);
    glutSolidSphere(5, 10, 10);
    glPopMatrix();


    Texturizacao();

    //chao
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture_id[0]);

    glBegin(GL_QUADS);
    glNormal3f(0.0, -1.0, 0.0);
    glTexCoord2f(10.0, 0.0);
    glVertex3f(1000, -50, 500);
    glTexCoord2f(10.0, 10.0);
    glVertex3f(1000, -50, -2000);
    glTexCoord2f(0.0, 10.0);
    glVertex3f(-1000, -50, -2000);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-1000, -50, 500);
    glEnd();

    glDisable(GL_TEXTURE_2D);


    //teto
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture_id[1]);

    glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0, 0.0);
    glTexCoord2f(10.0, 0.0);
    glVertex3f(1000, 1000, 500);
    glTexCoord2f(10.0, 10.0);
    glVertex3f(1000, 1000, -2000);
    glTexCoord2f(0.0, 10.0);
    glVertex3f(-1000, 1000, -2000);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-1000, 1000, 500);
    glEnd();

    glDisable(GL_TEXTURE_2D);


    //fundo
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture_id[1]);

    glBegin(GL_QUADS);
    glNormal3f(0.0, 0.0, 1.0);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(1000, -200, -2000);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(1000, 1000, -2000);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-1000, 1000, -2000);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-1000, -200, -2000);
    glEnd();

    glDisable(GL_TEXTURE_2D);

    //direita
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture_id[1]);

    glBegin(GL_QUADS);
    glNormal3f(1.0, 0.0, 0.0);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(1000, -100, 500);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(1000, 1000, 500);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(1000, 1000, -2000);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(1000, -100, -2000);
    glEnd();


    //esquerdo
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture_id[1]);

    glBegin(GL_QUADS);
    glNormal3f(-1.0, 0.0, 0.0);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(-1000, -100, 500);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(-1000, 1000, 500);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-1000, 1000, -2000);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-1000, -100, -2000);
    glEnd();

    glDisable(GL_TEXTURE_2D);
    glPushMatrix();
    glRotatef(angulo_robo_y, 0, 1, 0);

    //desenha android Mickey
    glPushMatrix();
    glTranslatef(0, 55.8, 100);
    glScalef(.3, .3, .3);
    glScalef(escala_obj1, escala_obj1, escala_obj1);
    android();
    glPopMatrix();

    //desenha cachorro
    glPushMatrix();
    glTranslatef(-150, -9.8, 100);
    glScalef(30, 30, 30);
    glScalef(escala_obj2, escala_obj2, escala_obj2);
    dog();
    glPopMatrix();


    //desenha mesa
    glPushMatrix();
    glTranslatef(150, -18.5, 100);
    glScalef(30, 30, 30);
    glScalef(escala_obj3, escala_obj3, escala_obj3);
    mesa();
    glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();

}


void Inicializa(void) {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    posX = 100;
    posY = 100;
    posZ = 100;

    upX = 0;

    luz.posicao[0] = posX;
    luz.posicao[1] = posY;
    luz.posicao[2] = posZ;
    luz.posicao[3] = 1.0;

    luz.ambiente[0] = 0.2;
    luz.ambiente[1] = 0.2;
    luz.ambiente[2] = 0.2;
    luz.ambiente[3] = 1.0;

    luz.difusa[0] = 0.5;
    luz.difusa[1] = 0.5;
    luz.difusa[2] = 0.5;
    luz.difusa[3] = 1.0;

    luz.especular[0] = 0.8;
    luz.especular[1] = 0.8;
    luz.especular[2] = 0.8;
    luz.especular[3] = 1.0;

    luz.especularidade[0] = 0.8;
    luz.especularidade[1] = 0.8;
    luz.especularidade[2] = 0.8;
    luz.especularidade[3] = 1.0;

    statusLuz = 1;
    angulo_torso = 0;

    angulo_cabeca = 0;

    angulo_braco_esq = 0;
    angulo_braco_esq_w = 0;

    angulo_braco_dir = 0;
    angulo_braco_dir_w = 0;

    angulo_perna_x_esq = 0;
    angulo_perna_x_dir = 0;

    angulo_robo_x = 0;
    angulo_robo_y = 0;
    angulo_robo_z = 0;

    escala_obj1 = 1;
    escala_obj2 = 1;
    escala_obj3 = 1;


    angulo_x_cabeca_dog = 0.0f,
    angulo_y_cabeca_dog = 10.0f,
    angulo_x_rabo_dog = 0.0f,
    angulo_y_rabo_dog = -10.0f,
    angulo_movimento_rabo_dog = 0.0f,
    angulo_perna_dog = 0.0f;


    camX = 0, camY = 60, camZ = 400;
    alvoX = 0, alvoY = 0, alvoZ = 0;

    angulo_da_camera = 65;

    glEnable(GL_BLEND);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_DEPTH_TEST);


}


void AlteraTamanhoJanela(GLsizei largura, GLsizei altura) {

    if (altura == 0) altura = 1;

    glViewport(0, 0, largura, altura);

    aspecto = (GLfloat) largura / (GLfloat) altura;
    EspecificaParametrosVisualizacao();
}

void GerenciaMouse(GLint button, GLint state, GLint x, GLint y) {

    if (button == GLUT_LEFT_BUTTON)
        if (state == GLUT_DOWN) {
            x_ini = x;
            y_ini = y;
            obsX_ini = obsX;
            obsY_ini = obsY;
            obsZ_ini = obsZ;
            rotX_ini = rotaciona_x;
            rotY_ini = rotY;
            bot = button;
        }
    if (button == GLUT_RIGHT_BUTTON)

        EspecificaParametrosVisualizacao();

    glutPostRedisplay();
}

void GerenciaMovim(int x, int y) {

    GLfloat cal_sens_rota = 10.0;
    GLfloat cal_sens_obs = 20.0;
    GLfloat cal_sens_trans = 40.0;


    if (bot == GLUT_LEFT_BUTTON) {
        int deltax = x_ini - x;
        int deltay = y_ini - y;
        rotY = rotY_ini - deltax / cal_sens_rota;
        rotaciona_x = rotX_ini - deltay / cal_sens_rota;
    }

    if (bot == GLUT_MIDDLE_BUTTON) {
        int deltax = x_ini - x;
        int deltay = y_ini - y;
        obsX = obsX_ini + deltax / cal_sens_trans;
        obsY = obsY_ini - deltay / cal_sens_trans;
    }
    EspecificaParametrosVisualizacao();
    glutPostRedisplay();
}

void GerenciaTeclado(GLubyte key, GLint x, GLint y) {
    switch (key) {
        case 'H':
            angulo_robo_y += 5;
            glutPostRedisplay();
            break;

        case 'h':
            angulo_robo_y -= 5;
            glutPostRedisplay();
            break;
        case 'f':
            angulo_robo_x += 5;
            glutPostRedisplay();
            break;
        case 'r':
            angulo_robo_x -= 5;
            glutPostRedisplay();
            break;

        case 'd':
            angulo_robo_z += 5;
            glutPostRedisplay();
            break;
        case 't':
            angulo_robo_z -= 5;
            glutPostRedisplay();
            break;

        case '9':
            angulo_cabeca += 5;
            glutPostRedisplay();
            break;

        case '0':
            angulo_cabeca -= 5;
            glutPostRedisplay();
            break;

        case 'a':
            angulo_braco_esq += 5;
            glutPostRedisplay();
            break;

        case 's':
            angulo_braco_esq -= 5;
            glutPostRedisplay();
            break;

        case 'g':
            if (angulo_braco_esq_w != -175)
                angulo_braco_esq_w -= 5;
            glutPostRedisplay();
            break;

        case '.':
            if (angulo_braco_esq_w != 0)
                angulo_braco_esq_w += 5;
            glutPostRedisplay();
            break;

        case ',':
            if (angulo_braco_dir_w != 0)
                angulo_braco_dir_w -= 5;
            glutPostRedisplay();
            break;

        case 'c':
            if (angulo_braco_dir_w != 175)
                angulo_braco_dir_w += 5;
            glutPostRedisplay();
            break;

        case '2':
            angulo_braco_dir += 5;
            glutPostRedisplay();
            break;

        case '@':
            angulo_braco_dir -= 5;
            glutPostRedisplay();
            break;

        case '6':
            if (angulo_perna_x_esq != 45)
                angulo_perna_x_esq += 5;
            glutPostRedisplay();
            break;

        case '5':
            if (angulo_perna_x_esq != -45)
                angulo_perna_x_esq -= 5;
            glutPostRedisplay();
            break;

        case '3':
            if (angulo_perna_x_dir != 45)
                angulo_perna_x_dir += 5;
            glutPostRedisplay();
            break;
        case '#':
            if (angulo_perna_x_dir != -45)
                angulo_perna_x_dir -= 5;
            glutPostRedisplay();
            break;
        case '7':
            if (angulo_x_cabeca_dog <= 18.7) {
                angulo_x_cabeca_dog += 1.7f;
            }
            glutPostRedisplay();
            break;
        case '&':
            if (angulo_x_cabeca_dog >= -18.07) {
                angulo_x_cabeca_dog -= 1.7f;
            }
            glutPostRedisplay();
            break;
        case 'm':
            if (angulo_perna_dog <= 20) {
                angulo_perna_dog += 2.0f;
            } else {
                angulo_perna_dog = 0.0f;
            }
            glutPostRedisplay();
            break;
        case 'i':
            if (angulo_x_rabo_dog <= 30) {
                angulo_x_rabo_dog += 3.0f;
            }
            glutPostRedisplay();
            break;
        case 'u':
            if (angulo_x_rabo_dog >= -30) {
                angulo_x_rabo_dog -= 3.0f;
            }
            glutPostRedisplay();
            break;
        case 'l':
            statusLuz = 0;
            glutPostRedisplay();
            break;
        case 'L':
            statusLuz = 1;
            glutPostRedisplay();
            break;
        case 'X':
            camX += 2;
            glutPostRedisplay();
            break;
        case 'x':
            camX -= 2;
            glutPostRedisplay();
            break;
        case 'Y':
            camY += 2;
            glutPostRedisplay();
            break;
        case 'y':
            camY -= 2;
            glutPostRedisplay();
            break;
        case 'Z':
            camZ += 2;
            glutPostRedisplay();
            break;
        case 'z':
            camZ -= 2;
            glutPostRedisplay();
            break;
        case 'Q':
            alvoX += 2;
            glutPostRedisplay();
            break;
        case 'q':
            alvoX -= 2;
            glutPostRedisplay();
            break;
        case 'W':
            alvoY += 2;
            glutPostRedisplay();
            break;
        case 'w':
            alvoY -= 2;
            glutPostRedisplay();
            break;
        case 'E':
            alvoZ += 2;
            glutPostRedisplay();
            break;
        case 'e':
            alvoZ -= 2;
            glutPostRedisplay();
            break;
        case '1':
            if (escala_obj1 >= 0.05 && escala_obj1 < 1.0) {
                escala_obj1 += 0.1;
            }
            glutPostRedisplay();
            break;
        case '!':
            if (escala_obj1 >= 0.1) {
                escala_obj1 -= 0.1;
            }
            glutPostRedisplay();
            break;
        case '-':
            if (escala_obj2 >= 0.05 && escala_obj2 < 1.0) {
                escala_obj2 += 0.1;
            }
            glutPostRedisplay();
            break;
        case '_':
            if (escala_obj2 >= 0.1) {
                escala_obj2 -= 0.1;
            }
            glutPostRedisplay();
            break;
        case '+':
            if (escala_obj3 >= 0.05 && escala_obj3 < 1.0) {
                escala_obj3 += 0.1;
            }
            glutPostRedisplay();
            break;
        case '=':
            if (escala_obj3 >= 0.1) {
                escala_obj3 -= 0.1;
            }

            glutPostRedisplay();
            break;
        case '4':

            if (angulo_torso >= 0.0 && angulo_torso <= 30) {
                angulo_torso += 0.5;
            }
            glutPostRedisplay();
            break;
        case '$':
            if (angulo_torso >= 0.1) {
                angulo_torso -= 0.5;
            }
            glutPostRedisplay();
            break;
        case 'k':
            angulo_da_camera -= 0.5;
            glutPostRedisplay();
            break;
        case 'K':
            angulo_da_camera += 0.5;
            glutPostRedisplay();
            break;
        case 'J':
            upX += 0.1;
            glutPostRedisplay();
            break;
        case 'j':
            upX -= 0.1;
            glutPostRedisplay();
            break;
    }

    glutPostRedisplay();
}


void TeclasEspeciais(GLint key, GLint x, GLint y) {
    switch (key) {
        case GLUT_KEY_LEFT:
            posX--;
            glutPostRedisplay();
            break;
        case GLUT_KEY_RIGHT:
            posX++;
            glutPostRedisplay();
            break;
        case GLUT_KEY_UP:
            posY++;
            glutPostRedisplay();
            break;
        case GLUT_KEY_DOWN:
            posY--;
            glutPostRedisplay();
            break;
        case GLUT_KEY_PAGE_UP:
            posZ += 10;
            glutPostRedisplay();
            break;
        case GLUT_KEY_PAGE_DOWN:
            posZ -= 10;
            glutPostRedisplay();
            break;
        case GLUT_KEY_F1:
            luz.especular[0] = 1.0;
            luz.especular[1] = 0.0;
            luz.especular[2] = 0.0;
            glutPostRedisplay();
            break;
        case GLUT_KEY_F2:
            luz.especular[0] = 0.0;
            luz.especular[1] = 1.0;
            luz.especular[2] = 0.0;
            glutPostRedisplay();
            break;
        case GLUT_KEY_F3:
            luz.especular[0] = 0.0;
            luz.especular[1] = 0.0;
            luz.especular[2] = 1.0;
            glutPostRedisplay();
            break;
        case GLUT_KEY_F12:
            Inicializa();
            glutPostRedisplay();
            break;

    }
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(900, 600);

    glutInitWindowPosition(0, 0);

    glutCreateWindow("Trabalho de Computação Gráfica - Marcia e Viviane");

    glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
    glutMouseFunc(GerenciaMouse);
    glutMotionFunc(GerenciaMovim);
    glutKeyboardFunc(GerenciaTeclado);


    glutSpecialFunc(TeclasEspeciais);

    Inicializa();

    glutMainLoop();
}



