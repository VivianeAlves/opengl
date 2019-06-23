#include "simpsonsModels.h"
#include "math.h"
#include <iostream>

float margeHeadAngle = 0;
float krustyShoes = 0;
bool enlargeShoes = 1;
bool enlargeNose = 1;
float krustyNose = 0;
float homerEyes = 0;
bool deformHomerEyes = 1;
bool bartArmsUp = 0;
float lisaArms = 30;

float* bezier(float t, int* p0,int* p1,int* p2,int* p3){
    float res [2];
	res[0]=pow((1-t),3)*p0[0]+3*t*pow((1-t),2)*p1[0]+3*pow(t,2)*(1-t)*p2[0]+pow(t,3)*p3[0];
    res[1]=pow((1-t),3)*p0[1]+3*t*pow((1-t),2)*p1[1]+3*pow(t,2)*(1-t)*p2[1]+pow(t,3)*p3[1];
    return res;
}
void moveHomer(bool* direction , float* t, float* x, float* z,float* angle){
    if(deformHomerEyes) {
        homerEyes+= 0.1;
        if (homerEyes > 0.5)deformHomerEyes = 0;
    }else {
        homerEyes-= 0.1;
        if (homerEyes <= 0)deformHomerEyes = 1;
    }

    *angle += 5;
    if(*direction) {
        *t -= 0.007;
    } else {
        *t += 0.007;
    }
    
    int p0[2] = {5,-4};
    int p1[2] = {-4,6};
    int p2[2] = {-1,2};
    int p3[2] = {-6,4};
    
    float* homer = bezier(*t,p0,p1,p2,p3);
    *x = homer[0];
    *z = homer[1];

    if (*x >= 7 || *z <= -7) *direction = 0;
    if (*x <= -7 || *z >= 7) *direction = 1;
}
void moveHomer2(float* x, float* z,float* angle, float* rotation){
    
    if(deformHomerEyes) {
        homerEyes+= 0.1;
        if (homerEyes > 0.5)deformHomerEyes = 0;
    }else {
        homerEyes-= 0.1;
        if (homerEyes <= 0)deformHomerEyes = 1;
    }
    *angle += 0.1;
    *rotation -= 5;
    
    *x = 2.0 * cos(*angle);
    *z = 2.0 * sin(*angle);
}
void moveBart(bool* direction , float* t, float* x, float* z, float* anglex,float* anglez){
    if(*direction) {
        *t -= 0.007;
        bartArmsUp = 1;
        if(*t > 0.5){
            *anglex += 5;
            *anglez = 0;
        }else {
            *anglez -= 5;
            *anglex = 0;
        }
    } else {
        bartArmsUp = 0;
        *t += 0.007;
        if(*t > 0.5){
            *anglex -= 5;
            *anglez = 0;
        } else {
            *anglez += 5;
            *anglex = 0;
        }
    }
    
    int p0[2] = {6,3};
    int p1[2] = {3,3};
    int p2[2] = {2,3};
    int p3[2] = {3,0};
    
    float* bart = bezier(*t,p0,p1,p2,p3);
    *x = bart[0];
    *z = bart[1];

    if (*t<=0) *direction = 0;
    if (*t>=1) *direction = 1;
}
void moveBart2(bool* direction , float* t, float* x, float* y, float* angley){
    bartArmsUp = 1;
    *angley += 5;
    if(*direction) {
        *t -= 0.007;
    } else {
        *t += 0.007;
    }
    
    int p0[2] = {-5,0};
    int p1[2] = {-2,5};
    int p2[2] = {-1,1};
    int p3[2] = {3,0};
    
    float* bart = bezier(*t,p0,p1,p2,p3);
    *x = bart[0];
    *y = bart[1];

    if (*t<=0) *direction = 0;
    if (*t>=1) *direction = 1;
}
void moveMillhouse(bool* direction , float* t, float* x, float* z, float* y){
    if(*direction) {
        *t -= 0.007;
    } else {
        *t += 0.007;
    }
    
    int p0[2] = {4,-4};
    int p1[2] = {-3,-3};
    int p2[2] = {4,-4};
    int p3[2] = {3,0};
    
    float* millhouse = bezier(*t,p0,p1,p2,p3);
    *x = millhouse[0];
    *z = millhouse[1];
    int p1y[2] = {0,4};
    int p2y[2] = {2,1};
    float* millhousey = bezier(*t,p0,p1y,p2y,p3);
    *y = millhousey[1];
    if (*y <= 0) *y = 0;

    if (*t<=0) *direction = 0;
    if (*t>=1) *direction = 1;
}
void moveMarge(bool* direction , float* t, float* x, float* z){
    margeHeadAngle += 5;
    if(*direction) {
        if (*t < 0) {
            *z += 0.1;
        } 
        *t -= 0.005;
    } else {
        if (*t< 0) {
            *z -= 0.1;
        } 
        *t += 0.005;
        
    }

    if ( *t >= 0 && *t <= 1) {    
        int p0[2] = {-1,-2};
        int p1[2] = {-9,-2};
        int p2[2] = {1,-5};
        int p3[2] = {-4,1};
        
        float* marge = bezier(*t,p0,p1,p2,p3);
        *x = marge[0];
        *z = marge[1];
    }

    if (*t<=-0.1) *direction = 0;
    if (*t>=1) *direction = 1;
}
void moveLisa(bool* direction , float* t, float* x, float* z, float* y, bool* zigzag){

    if(*zigzag) {
        *y += 0.1;
        lisaArms -= 5;
        if ( *y >= 0.5) *zigzag = 0;
    }else {
        *y -= 0.1;
        lisaArms += 5;
        if ( *y <= 0) *zigzag = 1;
    }

    if(*direction) {
        *t -= 0.009;
    } else {
        *t += 0.009;
    }
    
    int p0[2] = {-1,-4};
    int p1[2] = {-4,0};
    int p2[2] = {0,-3};
    int p3[2] = {-2,2};
    
    float* lisa = bezier(*t,p0,p1,p2,p3);
    *x = lisa[0];
    *z = lisa[1];

    if (*t<=0) *direction = 0;
    if (*t>=1) *direction = 1;
}
void moveKrusty(bool* direction , float* t, float* x, float* z, float* angle){
    if(enlargeShoes) {
        krustyShoes += 0.01;
        if(krustyShoes >= 0.2) enlargeShoes = 0;
    } else {
        krustyShoes -= 0.01;
        if(krustyShoes <= 0) enlargeShoes = 1;
    }
    if(enlargeNose) {
        krustyNose += 0.01;
        if(krustyNose >= 0.2) enlargeNose = 0;
    } else {
        krustyNose -= 0.01;
        if(krustyNose <= 0) enlargeNose = 1;
    }
    *angle -= 10;
    if(*direction) {
        *t -= 0.01;
    } else {
        *t += 0.01;
    }
    
    int p0[2] = {-4,3};
    int p1[2] = {-4,1};
    int p2[2] = {-1,3};
    int p3[2] = {0,0};
    
    float* krusty = bezier(*t,p0,p1,p2,p3);
    *x = krusty[0];
    *z = krusty[1];

    if (*t<=0) *direction = 0;
    if (*t>=1) *direction = 1;
}
void modelHomer() {
    glPushMatrix();
    glTranslated(0,0.5,0);
    // Bottom
    glPushMatrix();
    glColor3d(0,0,1);
    glTranslated(0.0, -0.5, 0.0);
    glScaled(0.5,0.5,0.3);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();

    // body
    glPushMatrix();
    glColor3d(1,1,1);
    glTranslated(0.0, 0.0, 0.0);
    glScaled(0.5,0.7,0.3);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();
    
    // Left Sleeve
    glPushMatrix();
    glColor3d(1,1,1);
    glTranslated(1, 0.8, 0.0);
    glRotated(-90,0,1,0);
    glScaled(0.15,0.15,0.15);
    glutSolidCone(2, 2.5, 100,100);
    glPopMatrix();
    
    // left shoulder
    glPushMatrix();
    glColor3d(1,1,0);
    glTranslated(1, 0.8, 0.0);
    glScaled(0.15,0.15,0.15);
    glutSolidSphere(1.1, 100, 100);
    glPopMatrix();

    // Left Arm
    glPushMatrix();
    glColor3d(1,1,0);
    glTranslated(1.1, 0.1, 0.0);
    glScaled(0.08,0.5,0.1);
    glutSolidSphere(2.0,100,100);
    glPopMatrix(); 

    // Right Sleeve
    glPushMatrix();
    glColor3d(1,1,1);
    glTranslated(-1, 0.8, 0.0);
    glRotated(90,0,1,0);
    glScaled(0.15,0.15,0.15);
    glutSolidCone(2, 2.5, 100,100);
    glPopMatrix();

    // Right shoulder
    glPushMatrix();
    glColor3d(1,1,0);
    glTranslated(-1, 0.8, 0.0);
    glScaled(0.15,0.15,0.15);
    glutSolidSphere(1.1, 100, 100);
    glPopMatrix();

    // right Arm 
    glPushMatrix();
    glColor3d(1,1,0);
    glTranslated(-1.1, 0.1, 0.0);
    glScaled(0.08,0.5,0.1);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();

    // left leg 
    glPushMatrix();
    glColor3d(0,0.0,1.0);
    glTranslated(0.5, -1.3, 0.0);
    glScaled(0.15,0.7,0.2);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();

    // left foot 
    glPushMatrix();
    glColor3d(0.3,0.3,0.0);
    glTranslated(0.5, -2.5, 0.0);
    glScaled(0.15,0.1,0.15);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();

    // right leg 
    glPushMatrix();
    glColor3d(0,0.0,1.0);
    glTranslated(-0.5, -1.3, 0.0);
    glScaled(0.15,0.7,0.2);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();

    // right foot 
    glPushMatrix();
    glColor3d(0.3,0.3,0.0);
    glTranslated(-0.5, -2.5, 0.0);
    glScaled(0.15,0.1,0.15);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();

    // Head
    glPushMatrix();
    glColor3d(1.0, 1.0, 0.0);
    glTranslated(0.0, 1.5,0.3);
    glScaled(0.2,0.4,0.2);
    glutSolidSphere(2, 100, 100);
    glPopMatrix();

    // Scalp
    glPushMatrix();
    glColor3d(1.0, 1.0, 0.0);
    glTranslated(0.0,1.8,0.3);
    glScaled(0.2,0.3,0.2);
    glutSolidSphere(2, 100, 100);
    glPopMatrix();

    // Mouth
    glPushMatrix();
    glColor3d(0.5, 0.5, 0.0);
    glTranslated(0.0,1.2,0.4);
    glScaled(0.2,0.3,0.2);
    glutSolidSphere(2, 100, 100);
    glPopMatrix();

    // Nose
    glPushMatrix();
    glColor3d(1.0, 1.0, 0.0);
    glTranslated(0.05, 1.5, 0.6);
    glScaled(0.05,0.05,0.2);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();
    // Tip
    glPushMatrix();
    glColor3d(1.0, 1.0, 0.0);
    glTranslated(0.05, 1.5, 0.9);
    glScaled(0.03,0.03,0.05);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();

    //Right Eye
    glPushMatrix();
    glTranslated(-0.04, -1, homerEyes);
    glScaled(1,1.5,1);
       // Lashes
    glPushMatrix();
    glColor3d(1.0, 1.0, 0.0);
    glTranslated(0.2, 1.9, 0.65);
    glScaled(0.08,0.04,0.1);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();
        // white
    glPushMatrix();
    glColor3d(1.0, 1.0, 1.0);
    glTranslated(0.2, 1.8, 0.6);
    glScaled(0.08,0.08,0.08);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();
        // pupil
    glPushMatrix();
    glColor3d(0.0, 0.0, 0.0);
    glTranslated(0.2, 1.8, 0.6);
    glScaled(0.05,0.05,0.09);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();

    glPopMatrix();

    //Left Eye
    glPushMatrix();
    glTranslated(-0.04, -1, homerEyes);
    glScaled(1,1.5,1);
    // Lashes
    glPushMatrix();
    glColor3d(1.0, 1.0, 0.0);
    glTranslated(-0.1, 1.9, 0.65);
    glScaled(0.08,0.04,0.1);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();
    // white
    glPushMatrix();
    glColor3d(1.0, 1.0, 1.0);
    glTranslated(-0.1, 1.8, 0.65);
    glScaled(0.08,0.08,0.08);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();
    // pupil
    glPushMatrix();
    glColor3d(0.0, 0.0, 0.0);
    glTranslated(-0.1, 1.8, 0.65);
    glScaled(0.04,0.04,0.09);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();

     
}
void modelMarge() {
    
    // Torso
    glPushMatrix();
    glColor3d(1,1,0);
    glTranslated(0.0, 1.15, 0.0);
    glScaled(0.2,0.15,0.15);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();

    // dress
    // Top
    glPushMatrix();
    glColor3d(0,1,0);
    glTranslated(0.0, 1, 0.0);
    glRotated(90,1,0,0);
    glScaled(0.4,0.35,0.3);
    glutSolidCone(1, 8, 100,100);
    glPopMatrix();
    // Waist
    glPushMatrix();
    glTranslated(0.0, 0.3, 0.0);
    glScaled(0.18,0.5,0.15);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();
    // bottom
    glPushMatrix();
    glColor3d(0,1,0);
    glTranslated(0.0, -1.3, 0.0);
    glRotated(-90,1,0,0);
    glScaled(0.4,0.35,0.3);
    glutSolidCone(1, 8, 100,100);
    glPopMatrix();

    glPushMatrix();
    glRotated(margeHeadAngle, 0,1,0);
    // Neck
    glPushMatrix();
    glColor3d(1,1,0);
    glTranslated(0.0, 2.1, 0.0);
    glRotated(90,0,1,0);
    glRotated(90,1,0,0);
    glScaled(0.3,0.3,0.3);
    glutSolidCone(1, 5, 100,100);
    glPopMatrix();

    // head
    glPushMatrix();
    glColor3d(1,1,0);
    glTranslated(0.0, 2.1, 0.0);
    glScaled(0.15,0.3,0.15);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();
    // scalp
    glPushMatrix();
    glColor3d(1,1,0);
    glTranslated(0.0, 2.4, 0.0);
    glScaled(0.15,0.15,0.15);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();

    //Right Eye
    glPushMatrix();
    glTranslated(-0.04, 0.1, -0.3);
    glScaled(0.9,1.1,1);
    // white
    glPushMatrix();
    glColor3d(1.0, 1.0, 1.0);
    glTranslated(-0.1, 1.8, 0.65);
    glScaled(0.08,0.08,0.08);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();
    // pupil
    glPushMatrix();
    glColor3d(0.0, 0.0, 0.0);
    glTranslated(-0.1, 1.8, 0.65);
    glScaled(0.04,0.04,0.09);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();
    glPopMatrix();
    
    //Left Eye
    glPushMatrix();
    glTranslated(-0.04, 0.1, -0.3);
    glScaled(0.9,1.1,1);
    // white
    glPushMatrix();
    glColor3d(1.0, 1.0, 1.0);
    glTranslated(0.2, 1.8, 0.6);
    glScaled(0.08,0.08,0.08);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();
    // pupil
    glPushMatrix();
    glColor3d(0.0, 0.0, 0.0);
    glTranslated(0.2, 1.8, 0.6);
    glScaled(0.04,0.04,0.09);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();
    glPopMatrix();

    // Nose 
    glPushMatrix();
    glColor3d(1.0, 1.0, 0.0);
    glTranslated(0.0, 2, 0.4);
    glScaled(0.05,0.05,0.05);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();

    //  Hair
    glPushMatrix();
    glColor3d(0,0.5,1);
    glTranslated(0.0, 2.5, 0.0);
    glScaled(0.15,0.3,0.15);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();
    glPushMatrix();
    glColor3d(0,0.5,1);
    glTranslated(0.0, 2.5, 0.0);
    glScaled(0.18,0.2,0.18);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();
    glPushMatrix();
    glColor3d(0,0.5,1);
    glTranslated(0.0, 2.7, 0.0);
    glScaled(0.18,0.2,0.18);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();
    glPushMatrix();
    glColor3d(0,0.5,1);
    glTranslated(0.0, 2.9, 0.0);
    glScaled(0.18,0.2,0.18);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();
    glPushMatrix();
    glColor3d(0,0.5,1);
    glTranslated(0.0, 3, 0.0);
    glScaled(0.18,0.2,0.18);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();
    glPopMatrix();

    
    // Left Arm
    glPushMatrix();
    glColor3d(1,1,0);
    glTranslated(0.45, 0.5, 0.0);
    glScaled(0.04,0.4,0.1);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();

    // Right Arm
    glPushMatrix();
    glColor3d(1,1,0);
    glTranslated(-0.45, 0.5, 0.0);
    glScaled(0.04,0.4,0.1);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();

    // Left leg
    glPushMatrix();
    glColor3d(1,1,0);
    glTranslated(0.2, -1.2, 0.0);
    glScaled(0.05,0.4,0.06);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();

    // Left shoe
    glPushMatrix();
    glColor3d(1,0.5,0);
    glTranslated(0.2, -2, 0.0);
    glScaled(0.05,0.04,0.06);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();
     
    // Right leg
    glPushMatrix();
    glColor3d(1,1,0);
    glTranslated(-0.2, -1.2, 0.0);
    glScaled(0.05,0.4,0.06);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();

     // Right shoe
     glPushMatrix();
     glColor3d(1,0.5,0);
     glTranslated(-0.2, -2, 0.0);
     glScaled(0.05,0.04,0.06);
     glutSolidSphere(2.0,100,100);
     glPopMatrix();
     
}
void modelLisa() {
    
    // Torso
    glPushMatrix();
    glColor3d(1,1,0);
    glTranslated(0.0, 0, 0.0);
    glScaled(0.15,0.15,0.15);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();

    // Neck
    glPushMatrix();
    glColor3d(1,0,0);
    glTranslated(0.0, -1.2, 0.0);
    glRotated(90,0,1,0);
    glRotated(-90,1,0,0);
    glScaled(0.3,0.3,0.3);
    GLUquadric *quadric = gluNewQuadric();
    gluCylinder(quadric,2.3,1, 4, 100,100);
    glPopMatrix();

    // Neck
    glPushMatrix();
    glColor3d(1,1,0);
    glTranslated(0.0, 0.5, 0.0);
    glRotated(90,0,1,0);
    glRotated(90,1,0,0);
    glScaled(0.4,0.3,0.3);
    glutSolidCone(1, 5, 100,100);
    glPopMatrix();

    // head
    glPushMatrix();
    glColor3d(1,1,0);
    glTranslated(0.0, 0.5, 0.0);
    glScaled(0.15,0.2,0.2);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();
    // scalp
    glPushMatrix();
    glColor3d(1,1,0);
    glTranslated(0.0, 0.8, 0.0);
    glScaled(0.15,0.15,0.15);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();

    //Right Eye
    glPushMatrix();
    glTranslated(-0.04, -1.2, -0.3);
    glScaled(0.9,1.1,1);
    // white
    glPushMatrix();
    glColor3d(1.0, 1.0, 1.0);
    glTranslated(-0.1, 1.8, 0.65);
    glScaled(0.08,0.08,0.08);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();
    // pupil
    glPushMatrix();
    glColor3d(0.0, 0.0, 0.0);
    glTranslated(-0.1, 1.8, 0.65);
    glScaled(0.04,0.04,0.09);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();
    glPopMatrix();
    
    //Left Eye
    glPushMatrix();
    glTranslated(-0.04, -1.2, -0.3);
    glScaled(0.9,1.1,1);
    // white
    glPushMatrix();
    glColor3d(1.0, 1.0, 1.0);
    glTranslated(0.2, 1.8, 0.6);
    glScaled(0.08,0.08,0.08);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();
    // pupil
    glPushMatrix();
    glColor3d(0.0, 0.0, 0.0);
    glTranslated(0.2, 1.8, 0.6);
    glScaled(0.04,0.04,0.09);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();
    glPopMatrix();

    // Nose 
    glPushMatrix();
    glColor3d(1.0, 1.0, 0.0);
    glTranslated(0.0, 0.7, 0.4);
    glScaled(0.05,0.05,0.05);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();

    //  Hair
    glPushMatrix();
    glColor3d(1,1,0);
    glTranslated(0.0, 1, 0.0);
    glRotated(-90,1,0,0);
    glScaled(0.2,0.2,0.1);
    glutSolidCone(1, 5, 100,100);
    glPopMatrix();
    glPushMatrix();
    glTranslated(0.0, 1, 0.0);
    glRotated(-60,0,0,1);
    glRotated(-90,1,0,0);
    glScaled(0.2,0.2,0.1);
    glutSolidCone(1, 5, 100,100);
    glPopMatrix();
    glPushMatrix();
    glTranslated(-0.1, 1, 0.0);
    glRotated(60,0,0,1);
    glRotated(-90,1,0,0);
    glScaled(0.2,0.2,0.1);
    glutSolidCone(1, 5, 100,100);
    glPopMatrix();
    glPushMatrix();
    glTranslated(0.1, 0.9, 0.0);
    glRotated(110,0,0,1);
    glRotated(90,1,0,0);
    glScaled(0.2,0.2,0.1);
    glutSolidCone(1, 5, 100,100);
    glPopMatrix();
    glPushMatrix();
    glTranslated(-0.1, 0.9, 0.0);
    glRotated(-110,0,0,1);
    glRotated(90,1,0,0);
    glScaled(0.2,0.2,0.1);
    glutSolidCone(1, 5, 100,100);
    glPopMatrix();
    glPushMatrix();
    glTranslated(-0.1, 0.7, 0.0);
    glRotated(-120,0,0,1);
    glRotated(90,1,0,0);
    glScaled(0.2,0.2,0.1);
    glutSolidCone(1, 5, 100,100);
    glPopMatrix();
    glPushMatrix();
    glTranslated(0.1, 0.7, 0.0);
    glRotated(120,0,0,1);
    glRotated(90,1,0,0);
    glScaled(0.2,0.2,0.1);
    glutSolidCone(1, 5, 100,100);
    glPopMatrix();
    
    // Left Arm
    glPushMatrix();
    glColor3d(1,1,0);
    glTranslated(0.45, -0.25, 0.0);
    glRotated(lisaArms,0,0,1);
    glScaled(0.04,0.25,0.05);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();

    // Right Arm
    glPushMatrix();
    glColor3d(1,1,0);
    glTranslated(-0.45, -0.25, 0.0);
    glRotated(-lisaArms,0,0,1);
    glScaled(0.04,0.25,0.05);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();

    // Left leg
    glPushMatrix();
    glColor3d(1,1,0);
    glTranslated(0.2, -1.2, 0.0);
    glScaled(0.05,0.4,0.06);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();

    // Left shoe
    glPushMatrix();
    glColor3d(1,0.5,0);
    glTranslated(0.2, -2, 0.0);
    glScaled(0.05,0.04,0.06);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();
     
    // Right leg
    glPushMatrix();
    glColor3d(1,1,0);
    glTranslated(-0.2, -1.2, 0.0);
    glScaled(0.05,0.4,0.06);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();

     // Right shoe
     glPushMatrix();
     glColor3d(1,0.5,0);
     glTranslated(-0.2, -2, 0.0);
     glScaled(0.05,0.04,0.06);
     glutSolidSphere(2.0,100,100);
     glPopMatrix();
     
}
void modelBart() {
    glPushMatrix();
    glTranslated(0,0,0);
    glScaled(1.2,1.2,1.2);
    // Bottom
    glPushMatrix();
    glColor3d(0,0,1);
    glTranslated(0.0, -0.8, 0.0);
    glScaled(0.2,0.2,0.3);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();

    // body
    glPushMatrix();
    glColor3d(1,0.4,0);
    glTranslated(0.0, -0.6, 0.0);
    glScaled(0.2,0.3,0.3);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();
    
    
    // Left Sleeve
    glPushMatrix();
    glColor3d(1,0.4,0);
    glTranslated(0.4, -0.2 ,0.0);
    glRotated(-90,0,1,0);
    glScaled(0.1,0.1,0.1);
    glutSolidCone(2, 2.5, 100,100);
    glPopMatrix();
    
    // Right Sleeve
    glPushMatrix();
    glColor3d(1,0.4,0);
    glTranslated(-0.4, -0.2, 0.0);
    glRotated(90,0,1,0);
    glScaled(0.1,0.1,0.1);
    glutSolidCone(2, 2.5, 100,100);
    glPopMatrix();

    if ( bartArmsUp) {
        
        // Left Arm UP
        glPushMatrix();
        glColor3d(1,1,0);
        glTranslated(0.3, -0.2, 0.0);
        glScaled(0.1,0.1,0.1);
        glutSolidSphere(1.1, 100, 100);
        glPopMatrix();
        glPushMatrix();
        glColor3d(1,1,0);
        glTranslated(0.4, 0.2, 0.0);
        glScaled(0.04,0.25,0.05);
        glutSolidSphere(2.0,100,100);
        glPopMatrix();
        // Right Arm up
        glPushMatrix();
        glColor3d(1,1,0);
        glTranslated(-0.3, -0.2, 0.0);
        glScaled(0.1,0.1,0.1);
        glutSolidSphere(1.1, 100, 100);
        glPopMatrix();
        glPushMatrix();
        glColor3d(1,1,0);
        glTranslated(-0.4, 0.2, 0.0);
        // glRotated(30,0,0,1);
        glScaled(0.04,0.25,0.05);
        glutSolidSphere(2.0,100,100);
        glPopMatrix();
       
    } else {
        // Left Arm down
        glPushMatrix();
        glColor3d(1,1,0);
        glTranslated(0.3, -0.2, 0.0);
        glScaled(0.1,0.1,0.1);
        glutSolidSphere(1.1, 100, 100);
        glPopMatrix();
        glPushMatrix();
        glColor3d(1,1,0);
        glTranslated(0.4, -0.6, 0.0);
        glScaled(0.04,0.25,0.05);
        glutSolidSphere(2.0,100,100);
        glPopMatrix();
        // Right Arm down
        glPushMatrix();
        glColor3d(1,1,0);
        glTranslated(-0.3, -0.2, 0.0);
        glScaled(0.1,0.1,0.1);
        glutSolidSphere(1.1, 100, 100);
        glPopMatrix();
        glPushMatrix();
        glColor3d(1,1,0);
        glTranslated(-0.4, -0.6, 0.0);
        // glRotated(30,0,0,1);
        glScaled(0.04,0.25,0.05);
        glutSolidSphere(2.0,100,100);
        glPopMatrix();
        
    }
    // Left leg
    glPushMatrix();
    glColor3d(0,0,1);
    glTranslated(0.25, -1.0, 0.0);
    glScaled(0.05,0.25,0.06);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();
    glPushMatrix();
    glColor3d(1,1,0);
    glTranslated(0.25, -1.3, 0.0);
    glScaled(0.04,0.2,0.05);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();
    glPushMatrix();
    glColor3d(0,0.3,0.6);
    glTranslated(0.25, -1.7, 0.0);
    glScaled(0.05,0.05,0.06);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();

    // Right leg
    glPushMatrix();
    glColor3d(0,0,1);
    glTranslated(-0.25, -1.0, 0.0);
    glScaled(0.05,0.25,0.06);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();
    glPushMatrix();
    glColor3d(1,1,0);
    glTranslated(-0.25, -1.3, 0.0);
    glScaled(0.04,0.2,0.05);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();
    glPushMatrix();
    glColor3d(0,0.3,0.6);
    glTranslated(-0.25, -1.7, 0.0);
    glScaled(0.05,0.05,0.06);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();

    // hair
    float radius = 0.23;
    int angle = 0;
    for ( int i = 0 ; i < 180 ; i++){
        
        float x = radius * sin(angle);
        float z = radius * cos(angle);
        glPushMatrix();
        glColor3d(1,1,0);
        glTranslated(x, 0.5, z);
        glRotated(-90,1,0,0);
        glScaled(0.2,0.2,0.1);
        glutSolidCone(0.5, 5, 100,100);
        glPopMatrix();
        angle+=2;
    }
   
   
    // Head
    glPushMatrix();
    glColor3d(1.0, 1.0, 0.0);
    glTranslated(0.0, 0.3,0.0);
    glRotated(90,1,0,0);
    glScaled(0.15,0.2,0.2);
    glutSolidCone(2,5, 100, 100);
    glPopMatrix();

    // Scalp
    glPushMatrix();
    glColor3d(1.0, 1.0, 0.0);
    glTranslated(0.0,0.35,0.0);
    glScaled(0.15,0.2,0.2);
    glutSolidSphere(2, 100, 100);
    glPopMatrix();
    
    // Nose
    glPushMatrix();
    glColor3d(1.0, 1.0, 0.0);
    glTranslated(0, 0.3, 0.2);
    glScaled(0.05,0.05,0.2);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();
    

    //Right Eye
    glPushMatrix();
    glTranslated(-0.04, -1.2, 0.2);
    glScaled(0.8,1.1,0.8);   
    // white
    glPushMatrix();
    glColor3d(1.0, 1.0, 1.0);
    glTranslated(0.2, 1.5, 0.2);
    glScaled(0.08,0.08,0.08);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();
    // pupil
    glPushMatrix();
    glColor3d(0.0, 0.0, 0.0);
    glTranslated(0.2, 1.5, 0.2);
    glScaled(0.05,0.05,0.09);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();
    glPopMatrix();

    //Left Eye
    glPushMatrix();
    glTranslated(-0.04, -1.2, 0.2);
    glScaled(0.8,1.1,0.8); 
    // white
    glPushMatrix();
    glColor3d(1.0, 1.0, 1.0);
    glTranslated(-0.1, 1.5, 0.2);
    glScaled(0.08,0.08,0.08);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();
    // pupil
    glPushMatrix();
    glColor3d(0.0, 0.0, 0.0);
    glTranslated(-0.1, 1.5, 0.2);
    glScaled(0.04,0.04,0.09);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();

     
}
void modelKrusty() {
    glPushMatrix();
    glTranslated(0,0.5,0);
    // Bottom
    glPushMatrix();
    glColor3d(0,0.9,0.4);
    glTranslated(0.0, -0.5, 0.0);
    glScaled(0.5,0.5,0.3);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();

    // body
    glPushMatrix();
    glColor3d(1,0.8,0.8);
    glTranslated(0.0, 0.0, 0.0);
    glScaled(0.5,0.7,0.3);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();
    
    // bow tie
    glPushMatrix();
    glColor3d(0,0,1);
    glTranslated(0.0,0.5,0.7);
    glBegin(GL_TRIANGLES);
    glVertex3d(0.0,0.0,0.0);
    glVertex3d(0.2,0.2,0.0);
    glVertex3d(0.2,-0.2,0.0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glColor3d(0,0,1);
    glTranslated(0.0,0.5,0.7);
    glBegin(GL_TRIANGLES);
    glVertex3d(0.0,0.0,0.0);
    glVertex3d(-0.2,0.2,0.0);
    glVertex3d(-0.2,-0.2,0.0);
    glEnd();
    glPopMatrix();
   
    // Left Sleeve
    glPushMatrix();
    glColor3d(1,0.8,0.8);
    glTranslated(1, 0.8, 0.0);
    glRotated(-90,0,1,0);
    glScaled(0.15,0.15,0.15);
    glutSolidCone(2, 2.5, 100,100);
    glPopMatrix();
    
    // left shoulder
    glPushMatrix();
    glColor3d(1,1,0);
    glTranslated(1, 0.8, 0.0);
    glScaled(0.15,0.15,0.15);
    glutSolidSphere(1.1, 100, 100);
    glPopMatrix();

    // Left Arm 
    glPushMatrix();
    glColor3d(1,1,0);
    glTranslated(1.1, 0.1, 0.0);
    glScaled(0.08,0.5,0.1);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();

    // Right Sleeve

    glPushMatrix();
    glColor3d(1,0.8,0.8);
    glTranslated(-1, 0.8, 0.0);
    glRotated(90,0,1,0);
    glScaled(0.15,0.15,0.15);
    glutSolidCone(2, 2.5, 100,100);
    glPopMatrix();

    // Right shoulder
    glPushMatrix();
    glColor3d(1,1,0);
    glTranslated(-1, 0.8, 0.0);
    glScaled(0.15,0.15,0.15);
    glutSolidSphere(1.1, 100, 100);
    glPopMatrix();

    // right Arm 
    glPushMatrix();
    glColor3d(1,1,0);
    glTranslated(-1.1, 0.1, 0.0);
    glScaled(0.08,0.5,0.1);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();

    // left leg 
    glPushMatrix();
    glColor3d(0,0.9,0.4);
    glTranslated(0.5, -1.3, 0.0);
    glScaled(0.15,0.7,0.2);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();

    // left foot 
    glPushMatrix();
    glColor3d(1,0.0,0.0);
    glTranslated(0.5, -2.5, 0.1);
    glScaled(krustyShoes+0.15,krustyShoes+0.1,krustyShoes+0.3);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();
    

    // right leg 
    glPushMatrix();
    glColor3d(0,0.9,0.4);
    glTranslated(-0.5, -1.3, 0.0);
    glScaled(0.15,0.7,0.2);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();

    // right foot 
    glPushMatrix();
    glColor3d(1,0.0,0.0);
    glTranslated(-0.5, -2.5, 0.1);
    glScaled(krustyShoes+0.15,krustyShoes+0.1,krustyShoes+0.3);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();

    // Head
    glPushMatrix();
    glColor3d(1.0, 1.0, 0.7);
    glTranslated(0.0, 1.5,0.3);
    glScaled(0.2,0.4,0.2);
    glutSolidSphere(2, 100, 100);
    glPopMatrix();

    // Scalp
    glPushMatrix();
    glColor3d(1.0, 1.0, 0.7);
    glTranslated(0.0,1.8,0.3);
    glScaled(0.2,0.3,0.2);
    glutSolidSphere(2, 100, 100);
    glPopMatrix();

    // Mouth
    glPushMatrix();
    glColor3d(0.5, 0.5, 0.3);
    glTranslated(0.0,1.2,0.4);
    glScaled(0.2,0.3,0.2);
    glutSolidSphere(2, 100, 100);
    glPopMatrix();

    // Nose
    glPushMatrix();
    glColor3d(1.0, 0.0, 0.0);
    glTranslated(0.05, 1.5, 0.9);
    glScaled(krustyNose+0.08,krustyNose+0.08,krustyNose+0.08);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();

    // Hair
    glPushMatrix();
    glColor3d(0,0.9,0.4);
    glTranslated(0.0,2,0.3);
    glRotated(-90,1,0,0);
    GLUquadric *quadric = gluNewQuadric();
    gluCylinder(quadric,0.3,0.1, 0.6, 100,100);
    glPopMatrix();
    glPushMatrix();
    glColor3d(0,0.9,0.4);
    glTranslated(0.0,2,0.3);
    glRotated(-90,0,1,0);
    GLUquadric *quadric1 = gluNewQuadric();
    gluCylinder(quadric1,0.3,0.1, 1, 100,100);
    glPopMatrix();
    glPushMatrix();
    glColor3d(0,0.9,0.4);
    glTranslated(0.0,2,0.3);
    glRotated(90,0,1,0);
    GLUquadric *quadric2 = gluNewQuadric();
    gluCylinder(quadric2,0.3,0.1, 1, 100,100);
    glPopMatrix();
    
    
    //Right Eye
    glPushMatrix();
    glTranslated(-0.04, -1, 0);
    glScaled(1,1.5,1);
        // white
    glPushMatrix();
    glColor3d(1.0, 1.0, 1.0);
    glTranslated(0.2, 1.8, 0.6);
    glScaled(0.08,0.08,0.08);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();
        // pupil
    glPushMatrix();
    glColor3d(0.0, 0.0, 0.0);
    glTranslated(0.2, 1.8, 0.6);
    glScaled(0.05,0.05,0.09);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();

    glPopMatrix();

    //Left Eye
    glPushMatrix();
    glTranslated(-0.04, -1, 0);
    glScaled(1,1.5,1);  
    // white
    glPushMatrix();
    glColor3d(1.0, 1.0, 1.0);
    glTranslated(-0.1, 1.8, 0.65);
    glScaled(0.08,0.08,0.08);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();
    // pupil
    glPushMatrix();
    glColor3d(0.0, 0.0, 0.0);
    glTranslated(-0.1, 1.8, 0.65);
    glScaled(0.04,0.04,0.09);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();
}
void modelMillhouse() {
    glPushMatrix();
    glTranslated(0,0,0);
    glScaled(1.2,1.2,1.2);
    // Bottom
    glPushMatrix();
    glColor3d(1,0.4,0);
    glTranslated(0.0, -0.8, 0.0);
    glScaled(0.2,0.2,0.3);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();

    // body
    glPushMatrix();
    glColor3d(1,0.8,0.8);
    glTranslated(0.0, -0.6, 0.0);
    glScaled(0.2,0.3,0.3);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();
    
    
    // Left Sleeve
    glPushMatrix();
    glColor3d(1,0.8,0.8);
    glTranslated(0.4, -0.2 ,0.0);
    glRotated(-90,0,1,0);
    glScaled(0.1,0.1,0.1);
    glutSolidCone(2, 2.5, 100,100);
    glPopMatrix();
    

    // Left Arm
    glPushMatrix();
    glColor3d(1,1,0);
    glTranslated(0.3, -0.2, 0.0);
    glScaled(0.1,0.1,0.1);
    glutSolidSphere(1.1, 100, 100);
    glPopMatrix();
    glPushMatrix();
    glColor3d(1,1,0);
    glTranslated(0.4, -0.6, 0.0);
    glScaled(0.04,0.25,0.05);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();
    
    // Right Sleeve
    glPushMatrix();
    glColor3d(1,0.8,0.8);
    glTranslated(-0.4, -0.2, 0.0);
    glRotated(90,0,1,0);
    glScaled(0.1,0.1,0.1);
    glutSolidCone(2, 2.5, 100,100);
    glPopMatrix();

    // Right Arm
    glPushMatrix();
    glColor3d(1,1,0);
    glTranslated(-0.3, -0.2, 0.0);
    glScaled(0.1,0.1,0.1);
    glutSolidSphere(1.1, 100, 100);
    glPopMatrix();
    glPushMatrix();
    glColor3d(1,1,0);
    glTranslated(-0.4, -0.6, 0.0);
    // glRotated(30,0,0,1);
    glScaled(0.04,0.25,0.05);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();

    // Left leg
    glPushMatrix();
    glColor3d(1,0.4,0);
    glTranslated(0.25, -1.0, 0.0);
    glScaled(0.05,0.25,0.06);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();
    glPushMatrix();
    glColor3d(1,1,0);
    glTranslated(0.25, -1.3, 0.0);
    glScaled(0.04,0.2,0.05);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();
    glPushMatrix();
    glColor3d(1,0.4,0);
    glTranslated(0.25, -1.7, 0.0);
    glScaled(0.05,0.05,0.06);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();

    // Right leg
    glPushMatrix();
    glColor3d(1,0.4,0);
    glTranslated(-0.25, -1.0, 0.0);
    glScaled(0.05,0.25,0.06);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();
    glPushMatrix();
    glColor3d(1,1,0);
    glTranslated(-0.25, -1.3, 0.0);
    glScaled(0.04,0.2,0.05);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();
    glPushMatrix();
    glColor3d(1,0.4,0);
    glTranslated(-0.25, -1.7, 0.0);
    glScaled(0.05,0.05,0.06);
    glutSolidSphere(2.0,100,100);
    glPopMatrix();

    // hair
    glPushMatrix();
    glColor3d(0.0, 0.6, 1.0);
    glTranslated(0.0, 0.6,0.0);
    glScaled(0.12,0.12,0.2);
    glutSolidSphere(2, 100, 100);
    glPopMatrix();
    glPushMatrix();
    glColor3d(0.0, 0.6, 1.0);
    glTranslated(0.1, 0.5,0.0);
    glScaled(0.12,0.12,0.2);
    glutSolidSphere(2, 100, 100);
    glPopMatrix();
    glPushMatrix();
    glColor3d(0.0, 0.6, 1.0);
    glTranslated(-0.1, 0.5,0.0);
    glScaled(0.12,0.12,0.2);
    glutSolidSphere(2, 100, 100);
    glPopMatrix();
    
    // Head
    glPushMatrix();
    glColor3d(1.0, 1.0, 0.0);
    glTranslated(0.0, 0.3,0.0);
    glRotated(90,1,0,0);
    glScaled(0.15,0.2,0.2);
    glutSolidCone(2,5, 100, 100);
    glPopMatrix();

    // Scalp
    glPushMatrix();
    glColor3d(1.0, 1.0, 0.0);
    glTranslated(0.0,0.35,0.0);
    glScaled(0.15,0.2,0.2);
    glutSolidSphere(2, 100, 100);
    glPopMatrix();
    
    // Nose
    glPushMatrix();
    glColor3d(1.0, 1.0, 0.0);
    glTranslated(0, 0.3, 0.2);
    glScaled(0.1,0.1,0.2);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();
    

    //Right Eye
    glPushMatrix();
    glTranslated(-0.04, -1.2, 0.2);
    glScaled(0.8,1.1,0.8); 
    // Glasses
    glPushMatrix();
    glColor3d(1,0.4,0);
    glTranslated(0.2, 1.5, 0.15);
    glScaled(0.09,0.09,0.08);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();
    glPushMatrix();
    glTranslated(-0.3, 1.5, 0.01);
    glScaled(0.01,0.02,0.15);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();
    // white
    glPushMatrix();
    glColor3d(1.0, 1.0, 1.0);
    glTranslated(0.2, 1.5, 0.2);
    glScaled(0.08,0.08,0.08);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();
    // pupil
    glPushMatrix();
    glColor3d(0.0, 0.0, 0.0);
    glTranslated(0.2, 1.5, 0.2);
    glScaled(0.03,0.03,0.09);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();
    glPopMatrix();

    //Left Eye
    glPushMatrix();
    glTranslated(-0.04, -1.2, 0.2);
    glScaled(0.8,1.1,0.8); 
     // Glasses
     glPushMatrix();
     glColor3d(1,0.4,0);
     glTranslated(-0.1, 1.5, 0.15);
     glScaled(0.09,0.09,0.08);
     glutSolidSphere(2.0, 100, 100);
     glPopMatrix();
     glPushMatrix();
     glTranslated(0.4, 1.5, 0.01);
     glScaled(0.01,0.02,0.15);
     glutSolidSphere(2.0, 100, 100);
     glPopMatrix();
    // white
    glPushMatrix();
    glColor3d(1.0, 1.0, 1.0);
    glTranslated(-0.1, 1.5, 0.2);
    glScaled(0.08,0.08,0.08);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();
    // pupil
    glPushMatrix();
    glColor3d(0.0, 0.0, 0.0);
    glTranslated(-0.1, 1.5, 0.2);
    glScaled(0.03,0.03,0.09);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();

}