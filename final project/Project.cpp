#include <iostream>
#include <GL/glut.h>

#include <cmath>
#define PI  3.14159265358979323846
using namespace std;

GLfloat cloud_position = 0.85f;
GLfloat cloud_speed = 0.0001f;
GLfloat character_position_x = 0.0f;
GLfloat character_position_y = -0.150f;
GLfloat Football_position_x = 0.0f;
GLfloat Football_position_y = 0.0f;
GLfloat character_speed = 0.0f;
GLfloat character_scale = 0.4f;
GLfloat DBuilding_position_x = -0.09f;
GLfloat DBuilding_position_y = 0.0f;
GLfloat DBuilding_scale_x = 1.4f;
GLfloat DBuilding_scale_y = 1.0f;
GLfloat character_rotation = 0.0f;  // Initial rotation angle
GLfloat Football_scale = 1.0;
GLfloat goalP_position_x = 0.0;
GLfloat goalP_position_y = 0.0;
GLfloat goalP_scale = 1.0f;
int triangleAmount = 500;
GLfloat twicePi = 2.0f * PI;
GLfloat footballX = 0.0f;
GLfloat footballY = -0.70f;
GLfloat targetX = 0.0f;
GLfloat targetY = -0.7f;
GLfloat speed = 0.09f;
GLfloat character_falling_speed = -0.025f;
int countdown = 3; // Initial countdown value

GLfloat scoreboard_position_x = -0.65f;
GLfloat scoreboard_position_y = -1.2f;
GLfloat scoreboard_scale = 1.3f;

bool player_1 = false;
float Short = 5;
int player_1_score = 0;
int player_2_score = 0;
bool newgame = false;

bool goalScored = false;
bool goalMissed = false;
bool mouseClicked = false;
bool character_movement = false;

int Count = 1;



void Circle(GLfloat cx, GLfloat cy, GLfloat radius, int r, int g, int b)
{
    glColor3ub(r, g, b);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= triangleAmount; i++) {
        glVertex2f(cx + (radius * cos(i * twicePi / triangleAmount)), cy + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
}

void drawString(const std::string& str, GLfloat x, GLfloat y) {
    glRasterPos2f(x, y);
    for (char c : str) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }
}
void sunComponent()
{
    Circle(0.8f, 0.8f, 0.08f, 255, 255, 0);
}

void cloudComponent() {
    Circle(0.58f, 0.75f, 0.060f, 255, 255, 255);
    Circle(0.5f, 0.82f, 0.068f, 255, 255, 255);
    Circle(0.42f, 0.75f, 0.068f, 255, 255, 255);
    Circle(0.5f, 0.72f, 0.07f, 255, 255, 255);
}


void cloudviewDAy() {

    glPushMatrix();

    glTranslatef(cloud_position - 0.4f, 0, 0);
    cloudComponent();

    glTranslatef(cloud_position - 0.4f, -0.1, 0);
    cloudComponent();

    glPopMatrix();
}

void SkyComponent() {
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(-1.0, -0.15f);
    glVertex2f(1.0f, -0.15f);
    glColor3ub(77, 184, 255);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();
    sunComponent();
    cloudviewDAy();
}
void groundview() {
    glBegin(GL_POLYGON);
    glColor3ub(0, 255, 0);
    glVertex2f(-0.74, -0.2);
    glVertex2f(0.86, -0.2);
    glVertex2f(1, -0.5);
    glVertex2f(1, -1);

    glVertex2f(-1, -1);
    glVertex2f(-1, -0.618);
    glEnd();


    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);

    glVertex2f(-0.705, -0.30);
    glVertex2f(0.805, -0.30);

    glVertex2f(-0.70, -0.30);
    glVertex2f(-1, -0.8);

    glVertex2f(0.8, -0.30);
    glVertex2f(1, -0.8);
    glEnd();
    //2nd goal line
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);

    glVertex2f(-0.5, -0.7);
    glVertex2f(0.5, -0.7);

    glVertex2f(0.5, -0.71);
    glVertex2f(0.5, -0.3);

    glVertex2f(-0.5, -0.3);
    glVertex2f(-0.5, -0.71);


    glEnd();
    //1st goal line
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);

    glVertex2f(-0.35, -0.5);
    glVertex2f(0.35, -0.5);

    glVertex2f(0.35, -0.51);
    glVertex2f(0.35, -0.3);

    glVertex2f(0.35, -0.3);
    glVertex2f(-0.35, -0.3);

    glVertex2f(-0.35, -0.3);
    glVertex2f(-0.35, -0.51);
    glEnd();

    //goal post
    glLineWidth(9);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);

    glVertex2f(-0.35, -0.30);
    glVertex2f(-0.35, 0.11);

    glVertex2f(0.35, -0.30);
    glVertex2f(0.35, 0.11);

    glVertex2f(-0.35, 0.10);
    glVertex2f(0.35, 0.10);
    glEnd();
    /*
    glBegin(GL_QUADS);
                glColor3ub(192, 192, 192);
                glVertex2f(-0.35,-0.30);
                glVertex2f(0.35, -0.30);
                glVertex2f(0.35, 0.10);
                glVertex2f(-0.35, 0.10);
                glEnd();
     */
}
void annex() {
    // glLineWidth(5);
    glBegin(GL_QUADS);
    glColor3ub(192, 192, 192);
    glVertex2f(-0.75, -0.2);
    glVertex2f(-0.9, -0.2);
    glVertex2f(-1, -0.3);
    glVertex2f(-1, -0.6);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(150, 151, 155);
    glVertex2f(-0.74, -0.2);
    glVertex2f(0.86, -0.2);

    glVertex2f(0.88, -0.12);
    glVertex2f(-0.8, -0.12);

    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(150, 80, 150);
    glVertex2f(-0.8, -0.12);
    glVertex2f(0.88, -0.12);

    glVertex2f(0.9, -0.09);
    glVertex2f(-0.83, -0.09);

    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(150, 80, 150);
    glVertex2f(0.88, -0.12);
    glVertex2f(0.9, -0.09);
    glVertex2f(1, -0.25);
    glVertex2f(1, -0.35);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(150, 151, 155);
    glVertex2f(-1, -0.61);
    glVertex2f(-0.741, -0.2);
    glVertex2f(-0.78, -0.12);
    glVertex2f(-1, -0.45);

    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(150, 105, 150);
    glVertex2f(-0.78, -0.12);
    glVertex2f(-1, -0.45);

    glVertex2f(-1, -0.3);
    glVertex2f(-0.83, -0.09);

    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(150, 80, 150);
    glVertex2f(-0.83, -0.09);
    glVertex2f(-1, -0.3);

    glVertex2f(-1, -0.25);
    glVertex2f(-0.9, -0.13);

    glEnd();


    /*
     glBegin(GL_POLYGON);
     glColor3ub(0, 255, 0);
     glVertex2f(-0.74, -0.2);
     glVertex2f(0.86, -0.2);
     glVertex2f(1, -0.5);
     glVertex2f(1, -1);

     glVertex2f(-1, -1);
     glVertex2f(-1, -0.618);
     glEnd();


   */

    glLineWidth(3.5);
    glBegin(GL_LINES);
    glColor3ub(0, 82, 33);

    glVertex2f(-1, -0.7);
    glVertex2f(-1, -0.4);

    glVertex2f(-1, -0.4);
    glVertex2f(-0.755, -0.1);

    glVertex2f(-0.755, -0.1);
    glVertex2f(0.85, -0.1);

    glVertex2f(0.85, -0.1);
    glVertex2f(1, -0.4);

    glVertex2f(-0.99, -0.385);
    glVertex2f(-0.99, -0.64);

    glVertex2f(-0.98, -0.365);
    glVertex2f(-0.98, -0.63);

    glVertex2f(-0.96, -0.345);
    glVertex2f(-0.96, -0.62);

    glVertex2f(-0.94, -0.32);
    glVertex2f(-0.94, -0.6);

    glVertex2f(-0.92, -0.30);
    glVertex2f(-0.92, -0.57);

    glVertex2f(-0.9, -0.28);
    glVertex2f(-0.9, -0.55);

    glVertex2f(-0.88, -0.25);
    glVertex2f(-0.88, -0.5);

    glVertex2f(-0.86, -0.23);
    glVertex2f(-0.86, -0.48);

    glVertex2f(-0.84, -0.20);
    glVertex2f(-0.84, -0.46);

    glVertex2f(-0.82, -0.18);
    glVertex2f(-0.82, -0.44);

    glVertex2f(-0.8, -0.15);
    glVertex2f(-0.8, -0.4);

    glVertex2f(-0.78, -0.13);
    glVertex2f(-0.78, -0.38);

    glVertex2f(-0.76, -0.098);
    glVertex2f(-0.76, -0.34);

    glVertex2f(-0.74, -0.095);
    glVertex2f(-0.74, -0.3);

    glVertex2f(-0.72, -0.095);
    glVertex2f(-0.72, -0.28);

    glVertex2f(-0.7, -0.095);
    glVertex2f(-0.7, -0.26);

    glVertex2f(-0.68, -0.095);
    glVertex2f(-0.68, -0.26);

    glVertex2f(-0.66, -0.1);
    glVertex2f(-0.66, -0.26);

    glVertex2f(-0.64, -0.1);
    glVertex2f(-0.64, -0.26);

    glVertex2f(-0.62, -0.1);
    glVertex2f(-0.62, -0.26);

    glVertex2f(-0.6, -0.1);
    glVertex2f(-0.6, -0.26);

    glVertex2f(-0.58, -0.1);
    glVertex2f(-0.58, -0.26);

    glVertex2f(-0.56, -0.1);
    glVertex2f(-0.56, -0.26);

    glVertex2f(-0.54, -0.1);
    glVertex2f(-0.54, -0.26);

    glVertex2f(-0.52, -0.1);
    glVertex2f(-0.52, -0.26);

    glVertex2f(-0.5, -0.1);
    glVertex2f(-0.5, -0.26);

    glVertex2f(-0.48, -0.1);
    glVertex2f(-0.48, -0.26);

    glVertex2f(-0.46, -0.1);
    glVertex2f(-0.46, -0.26);

    glVertex2f(-0.44, -0.1);
    glVertex2f(-0.44, -0.26);

    glVertex2f(-0.42, -0.1);
    glVertex2f(-0.42, -0.26);

    glVertex2f(-0.4, -0.1);
    glVertex2f(-0.4, -0.26);

    glVertex2f(-0.38, -0.1);
    glVertex2f(-0.38, -0.26);

    glVertex2f(-0.36, -0.1);
    glVertex2f(-0.36, -0.26);

    glVertex2f(-0.34, -0.1);
    glVertex2f(-0.34, -0.26);

    glVertex2f(-0.32, -0.1);
    glVertex2f(-0.32, -0.26);

    glVertex2f(-0.3, -0.1);
    glVertex2f(-0.3, -0.26);

    glVertex2f(-0.28, -0.1);
    glVertex2f(-0.28, -0.26);

    glVertex2f(-0.26, -0.1);
    glVertex2f(-0.26, -0.26);

    glVertex2f(-0.24, -0.1);
    glVertex2f(-0.24, -0.26);

    glVertex2f(-0.22, -0.1);
    glVertex2f(-0.22, -0.26);

    glVertex2f(-0.2, -0.1);
    glVertex2f(-0.2, -0.26);

    glVertex2f(-0.18, -0.1);
    glVertex2f(-0.18, -0.26);

    glVertex2f(-0.16, -0.1);
    glVertex2f(-0.16, -0.26);

    glVertex2f(-0.14, -0.1);
    glVertex2f(-0.14, -0.26);

    glVertex2f(-0.12, -0.1);
    glVertex2f(-0.12, -0.26);

    glVertex2f(-0.1, -0.1);
    glVertex2f(-0.1, -0.26);

    glVertex2f(-0.08, -0.1);
    glVertex2f(-0.08, -0.26);

    glVertex2f(-0.06, -0.1);
    glVertex2f(-0.06, -0.26);

    glVertex2f(-0.04, -0.1);
    glVertex2f(-0.04, -0.26);

    glVertex2f(-0.02, -0.1);
    glVertex2f(-0.02, -0.26);

    glVertex2f(0.0, -0.1);
    glVertex2f(0.0, -0.26);

    glVertex2f(0.02, -0.1);
    glVertex2f(0.02, -0.26);

    glVertex2f(0.04, -0.1);
    glVertex2f(0.04, -0.26);

    glVertex2f(0.06, -0.1);
    glVertex2f(0.06, -0.26);

    glVertex2f(0.08, -0.1);
    glVertex2f(0.08, -0.26);

    glVertex2f(0.1, -0.1);
    glVertex2f(0.1, -0.26);

    glVertex2f(0.12, -0.1);
    glVertex2f(0.12, -0.26);

    glVertex2f(0.14, -0.1);
    glVertex2f(0.14, -0.26);

    glVertex2f(0.14, -0.1);
    glVertex2f(0.14, -0.26);

    glVertex2f(0.16, -0.1);
    glVertex2f(0.16, -0.26);

    glVertex2f(0.18, -0.1);
    glVertex2f(0.18, -0.26);

    glVertex2f(0.18, -0.1);
    glVertex2f(0.18, -0.26);

    glVertex2f(0.20, -0.1);
    glVertex2f(0.20, -0.26);

    glVertex2f(0.22, -0.1);
    glVertex2f(0.22, -0.26);

    glVertex2f(0.24, -0.1);
    glVertex2f(0.24, -0.26);

    glVertex2f(0.26, -0.1);
    glVertex2f(0.26, -0.26);

    glVertex2f(0.28, -0.1);
    glVertex2f(0.28, -0.26);

    glVertex2f(0.30, -0.1);
    glVertex2f(0.30, -0.26);

    glVertex2f(0.32, -0.1);
    glVertex2f(0.32, -0.26);

    glVertex2f(0.34, -0.1);
    glVertex2f(0.34, -0.26);

    glVertex2f(0.36, -0.1);
    glVertex2f(0.36, -0.26);

    glVertex2f(0.38, -0.1);
    glVertex2f(0.38, -0.26);

    glVertex2f(0.40, -0.1);
    glVertex2f(0.40, -0.26);

    glVertex2f(0.42, -0.1);
    glVertex2f(0.42, -0.26);

    glVertex2f(0.44, -0.1);
    glVertex2f(0.44, -0.26);

    glVertex2f(0.46, -0.1);
    glVertex2f(0.46, -0.26);

    glVertex2f(0.48, -0.1);
    glVertex2f(0.48, -0.26);

    glVertex2f(0.5, -0.1);
    glVertex2f(0.5, -0.26);

    glVertex2f(0.52, -0.1);
    glVertex2f(0.52, -0.26);

    glVertex2f(0.54, -0.1);
    glVertex2f(0.54, -0.26);

    glVertex2f(0.54, -0.1);
    glVertex2f(0.54, -0.26);

    glVertex2f(0.54, -0.1);
    glVertex2f(0.54, -0.26);

    glVertex2f(0.56, -0.1);
    glVertex2f(0.56, -0.26);

    glVertex2f(0.58, -0.1);
    glVertex2f(0.58, -0.26);

    glVertex2f(0.6, -0.1);
    glVertex2f(0.6, -0.26);

    glVertex2f(0.62, -0.1);
    glVertex2f(0.62, -0.26);

    glVertex2f(0.64, -0.1);
    glVertex2f(0.64, -0.26);

    glVertex2f(0.66, -0.1);
    glVertex2f(0.66, -0.26);

    glVertex2f(0.68, -0.1);
    glVertex2f(0.68, -0.26);

    glVertex2f(0.7, -0.1);
    glVertex2f(0.7, -0.26);

    glVertex2f(0.72, -0.1);
    glVertex2f(0.72, -0.26);

    glVertex2f(0.74, -0.1);
    glVertex2f(0.74, -0.26);

    glVertex2f(0.76, -0.1);
    glVertex2f(0.76, -0.26);

    glVertex2f(0.78, -0.1);
    glVertex2f(0.78, -0.26);

    glVertex2f(0.8, -0.1);
    glVertex2f(0.8, -0.26);

    glVertex2f(0.82, -0.1);
    glVertex2f(0.82, -0.26);

    glVertex2f(0.84, -0.1);
    glVertex2f(0.84, -0.26);

    glVertex2f(0.86, -0.12);
    glVertex2f(0.86, -0.28);

    glVertex2f(0.87, -0.14);
    glVertex2f(0.87, -0.3);

    glVertex2f(0.88, -0.16);
    glVertex2f(0.88, -0.32);

    glVertex2f(0.9, -0.2);
    glVertex2f(0.9, -0.35);

    glVertex2f(0.92, -0.24);
    glVertex2f(0.92, -0.38);

    glVertex2f(0.94, -0.28);
    glVertex2f(0.94, -0.41);

    glVertex2f(0.96, -0.32);
    glVertex2f(0.96, -0.44);

    glVertex2f(0.98, -0.36);
    glVertex2f(0.98, -0.47);

    glVertex2f(1, -0.4);
    glVertex2f(1, -0.51);



    glEnd();


}
void building() {

    glScalef(DBuilding_scale_x, DBuilding_scale_y, 1.0);
    glTranslatef(DBuilding_position_x, DBuilding_position_y, 0.0f);

    glTranslatef(+0.3f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);


    glVertex2f(-1.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);

    glVertex2f(0.0f, 0.8f);
    glVertex2f(0.0f, -0.8f);


    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(192, 192, 192); // Building rgb(4, 138, 193)
    glVertex2f(-1.0, -0.2);
    glVertex2f(-0.8, -0.2);
    glVertex2f(-0.8, 0.9);
    glVertex2f(-1.0, 0.9);



    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(38, 58, 81); // Building rgb(4, 138, 193)
    glVertex2f(-0.04, -0.2);
    glVertex2f(0.08, -0.2);
    glVertex2f(0.08, 0.94);
    glVertex2f(-0.04, 0.94);



    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(38, 58, 81); // Building rgb(4, 138, 193)
    glVertex2f(0.06, -0.2);
    glVertex2f(0.26, -0.2);
    glVertex2f(0.26, 0.135);
    glVertex2f(0.06, 0.135);



    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(192, 192, 192); // Building rgb(4, 138, 193)
    glVertex2f(-0.8, -0.2);
    glVertex2f(0.0, -0.2);
    glVertex2f(0.0, 0.84);
    glVertex2f(-0.8, 0.9);



    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 90, 150); // Building rgb(4, 138, 193)
    glVertex2f(-1.0, -0.2);
    glVertex2f(-0.78, -0.2);
    glVertex2f(-0.78, 0.83);
    glVertex2f(-1.0, 0.85);



    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 90, 150); // Building rgb(4, 138, 193)
    glVertex2f(-0.7, 0.78);
    glVertex2f(0.0, 0.75);
    glVertex2f(0.0, 0.82);
    glVertex2f(-0.7, 0.85);



    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(60, 90, 150); // Building rgb(4, 138, 193)
    glVertex2f(-0.7, 0.7);
    glVertex2f(0.0, 0.67);
    glVertex2f(0.0, 0.73);
    glVertex2f(-0.7, 0.76);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 90, 150); // Building rgb(4, 138, 193)
    glVertex2f(-0.7, 0.62);
    glVertex2f(0.0, 0.59);
    glVertex2f(0.0, 0.65);
    glVertex2f(-0.7, 0.68);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 90, 150); // Building rgb(4, 138, 193)
    glVertex2f(-0.73, 0.49);
    glVertex2f(0.0, 0.47);
    glVertex2f(0.0, 0.53);
    glVertex2f(-0.73, 0.56);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 90, 150); // Building rgb(4, 138, 193)
    glVertex2f(-0.73, 0.41);
    glVertex2f(0.0, 0.4);
    glVertex2f(0.0, 0.45);
    glVertex2f(-0.73, 0.47);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(060, 90, 150); // Building rgb(4, 138, 193)
    glVertex2f(-0.73, 0.33);
    glVertex2f(0.0, 0.32);
    glVertex2f(0.0, 0.38);
    glVertex2f(-0.73, 0.39);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 90, 150); // Building rgb(4, 138, 193)
    glVertex2f(-0.73, 0.17);
    glVertex2f(0.0, 0.18);
    glVertex2f(0.0, 0.25);
    glVertex2f(-0.73, 0.25);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 90, 150); // Building rgb(4, 138, 193)
    glVertex2f(-0.73, 0.07);
    glVertex2f(0.0, 0.07);
    glVertex2f(0.0, 0.15);
    glVertex2f(-0.73, 0.15);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 90, 150); // Building rgb(4, 138, 193)
    glVertex2f(-0.73, -0.03);
    glVertex2f(0.0, -0.03);
    glVertex2f(0.0, 0.05);
    glVertex2f(-0.73, 0.05);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 90, 150); // Building rgb(4, 138, 193)
    glVertex2f(-0.73, -0.13);
    glVertex2f(0.0, -0.13);
    glVertex2f(0.0, -0.05);
    glVertex2f(-0.73, -0.05);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(192, 192, 192); // Building rgb(4, 138, 193)
    glVertex2f(-0.84, 0.54);
    glVertex2f(-0.74, 0.56);
    glVertex2f(-0.74, 0.9);
    glVertex2f(-0.84, 0.9);

    glEnd();


    //ralling
    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glColor3ub(255, 255, 255); // Building rgb(4, 138, 193)
    glVertex2f(-0.83, 0.54);
    glVertex2f(-0.83, 0.62);
    glVertex2f(-0.01, 0.58);
    glVertex2f(-0.01, 0.53);

    glEnd();
    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glColor3ub(255, 255, 255); // Building rgb(4, 138, 193)
    glVertex2f(-0.72, 0.56);
    glVertex2f(-0.72, 0.62);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glColor3ub(255, 255, 255); // Building rgb(4, 138, 193)
    glVertex2f(-0.6, 0.56);
    glVertex2f(-0.6, 0.6);
    glEnd();


    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glColor3ub(255, 255, 255); // Building rgb(4, 138, 193)
    glVertex2f(-0.48, 0.55);
    glVertex2f(-0.48, 0.6);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glColor3ub(255, 255, 255); // Building rgb(4, 138, 193)
    glVertex2f(-0.36, 0.545);
    glVertex2f(-0.36, 0.6);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glColor3ub(255, 255, 255); // Building rgb(4, 138, 193)
    glVertex2f(-0.24, 0.54);
    glVertex2f(-0.24, 0.6);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glColor3ub(255, 255, 255); // Building rgb(4, 138, 193)
    glVertex2f(-0.12, 0.535);
    glVertex2f(-0.12, 0.58);
    glEnd();

    //ralling2
    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glColor3ub(255, 255, 255); // Building rgb(4, 138, 193)
    glVertex2f(-0.73, 0.25);
    glVertex2f(-0.73, 0.32);
    glVertex2f(-0.01, 0.31);
    glVertex2f(-0.01, 0.25);

    glEnd();

    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glColor3ub(255, 255, 255); // Building rgb(4, 138, 193)
    glVertex2f(-0.61, 0.25);
    glVertex2f(-0.61, 0.32);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glColor3ub(255, 255, 255); // Building rgb(4, 138, 193)
    glVertex2f(-0.49, 0.25);
    glVertex2f(-0.49, 0.32);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glColor3ub(255, 255, 255); // Building rgb(4, 138, 193)
    glVertex2f(-0.37, 0.25);
    glVertex2f(-0.37, 0.32);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glColor3ub(255, 255, 255); // Building rgb(4, 138, 193)
    glVertex2f(-0.25, 0.25);
    glVertex2f(-0.25, 0.32);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glColor3ub(255, 255, 255); // Building rgb(4, 138, 193)
    glVertex2f(-0.13, 0.25);
    glVertex2f(-0.13, 0.32);
    glEnd();  // Render now

    //tree1
    glBegin(GL_TRIANGLES);
    glColor3ub(26, 102, 46); // Building rgb(4, 138, 193)
    glVertex2f(-0.68, 0.558);
    glVertex2f(-0.64, 0.558);
    glVertex2f(-0.66, 0.65);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(26, 102, 46); // Building rgb(4, 138, 193)
    glVertex2f(-0.56, 0.55);
    glVertex2f(-0.52, 0.55);
    glVertex2f(-0.54, 0.64);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(26, 102, 46); // Building rgb(4, 138, 193)
    glVertex2f(-0.44, 0.545);
    glVertex2f(-0.4, 0.545);
    glVertex2f(-0.42, 0.635);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(26, 102, 46); // Building rgb(4, 138, 193)
    glVertex2f(-0.32, 0.54);
    glVertex2f(-0.28, 0.54);
    glVertex2f(-0.3, 0.63);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(26, 102, 46); // Building rgb(4, 138, 193)
    glVertex2f(-0.2, 0.535);
    glVertex2f(-0.16, 0.535);
    glVertex2f(-0.18, 0.625);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(26, 102, 46); // Building rgb(4, 138, 193)
    glVertex2f(-0.08, 0.53);
    glVertex2f(-0.04, 0.53);
    glVertex2f(-0.06, 0.62);

    glEnd();

    //tree2
    glBegin(GL_TRIANGLES);
    glColor3ub(26, 102, 46); // Building rgb(4, 138, 193)
    glVertex2f(-0.69, 0.25);
    glVertex2f(-0.65, 0.25);
    glVertex2f(-0.67, 0.34);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(26, 102, 46); // Building rgb(4, 138, 193)
    glVertex2f(-0.57, 0.25);
    glVertex2f(-0.53, 0.25);
    glVertex2f(-0.55, 0.34);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(26, 102, 46); // Building rgb(4, 138, 193)
    glVertex2f(-0.45, 0.25);
    glVertex2f(-0.41, 0.25);
    glVertex2f(-0.43, 0.34);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(26, 102, 46); // Building rgb(4, 138, 193)
    glVertex2f(-0.33, 0.25);
    glVertex2f(-0.29, 0.25);
    glVertex2f(-0.31, 0.34);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(26, 102, 46); // Building rgb(4, 138, 193)
    glVertex2f(-0.21, 0.25);
    glVertex2f(-0.17, 0.25);
    glVertex2f(-0.19, 0.34);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(26, 102, 46); // Building rgb(4, 138, 193)
    glVertex2f(-0.09, 0.25);
    glVertex2f(-0.05, 0.25);
    glVertex2f(-0.07, 0.34);

    glEnd();
}
void plasticBox() {
    glLineWidth(2);
    // Draw a Red 1x1 Square centered at origin
    glBegin(GL_LINES);              // Each set of 4 vertices form a quad
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex2f(-0.5, -0.25);    // x, y
    glVertex2f(0.5, -0.25);
    glEnd();// x, y

}
void goalP() {
    glPushMatrix();
    glTranslatef(goalP_position_x, goalP_position_y, 0.0f);

    glScalef(goalP_scale, character_scale, 1.0);

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.25, 0.0);
    glVertex2f(-0.25, 0.305);
    glVertex2f(0.25, 0.305);
    glVertex2f(0.25, 0.0);
    glVertex2f(-0.25, 0.3);
    glVertex2f(0.25, 0.3);
    glEnd();
    glPopMatrix();
}
void drawHumanCharacter() {
    glPushMatrix();

    glTranslatef(character_position_x, character_position_y, 0.0f);
    glRotatef(character_rotation, 0.0f, 0.0f, 1.0f);  // Rotate around z-axis
    glScalef(character_scale, character_scale, 1.0);



    // glColor3f(1.0, 1.0, 0.0);
   // glRectf(-0.06, 0.4, 0.06, 0.5);
  //   glRectf(-0.2, 0.4, 0.2, -0.4);
    glColor3f(0.0, 0.0, 0.0);
    glRectf(-0.03, 0.4, 0.03, 0.3);
    Circle(0.0, 0.45, 0.06, 255, 255, 255);
    if (!player_1) {
        glColor3f(0.8, 0.05, 0.0);

    }
    else {
        glColor3f(0, 1, 1);
    }
    glRectf(-0.1, 0.3, 0.1, 0.0);
    glRectf(-0.18, 0.35, 0.18, 0.3);
    glRectf(-0.1, 0.0, -0.02, -0.2);
    glRectf(0.02, 0.0, 0.1, -0.2);
    glColor3f(0.0, 0.0, 0.0);
    glRectf(-0.09, -0.2, -0.03, -0.4);
    glRectf(0.03, -0.2, 0.09, -0.4);
    glRectf(-0.11, 0.2, -0.17, 0.05);
    glRectf(0.17, 0.3, 0.11, 0.05);
    if (!player_1) {
        glColor3f(0.8, 0.05, 0.0);

    }
    else {
        glColor3f(0, 1, 1);
    }
    glRectf(-0.105, 0.3, -0.18, 0.2);
    glRectf(0.18, 0.3, 0.105, 0.2);

    glPopMatrix();
}
void moveFootballTowardsTarget() {
    // Check if the football tracker rectangle is inside the far rectangle
  //  if(footballX == targetX && footballY == targetX ){
    if ((footballX + 0.025 > character_position_x - 0.068 && footballY + 0.025 > character_position_y - 0.12) &&
        (footballX - 0.025 < character_position_x + 0.068 && footballY + 0.025 > character_position_y - 0.12) &&
        (footballX + 0.025 > character_position_x - 0.068 && footballY - 0.025 < character_position_y + 0.2) &&
        (footballX - 0.025 < character_position_x + 0.068 && footballY - 0.025 < character_position_y + 0.2)) {
        character_movement = true;
        goalMissed = true;
        return; // Stop movement if goal missed
    }
    if (footballX + 0.003 > targetX && footballY + 0.003 > targetY && targetY != -0.7f) {
        if (footballX - 0.025 >= -0.35 && footballX - 0.025 <= 0.35 &&
            footballY - 0.025 >= -0.30 && footballY - 0.025 <= 0.10) {
            character_movement = true;
            goalScored = true;
            return; // Stop movement if goal scored
        }
        else {
            character_movement = true;
            goalMissed = true;
            return;
        }
        /*
         glVertex2f(-0.35,-0.30);
         glVertex2f(0.35, -0.30);
         glVertex2f(0.35, 0.10);
         glVertex2f(-0.35, 0.10);
         */
    }
    // Check if the football tracker rectangle touches or is inside the new rectangle


    /*
     glVertex2f(character_position_x - 0.072, character_position_y - 0.16);
     glVertex2f(character_position_x + 0.072, character_position_y - 0.16);
     glVertex2f(character_position_x + 0.072, character_position_y + 0.2);
     glVertex2f(character_position_x - 0.072, character_position_y + 0.2);
     */
     // Move the football towards the target position only if mouse has been clicked
    if (mouseClicked) {

        footballX += (targetX - footballX) * speed;
        footballY += (targetY - footballY) * speed;

    }
}

void gallery() {

    //Sky
    glBegin(GL_QUADS);
    glColor3ub(135, 206, 250); // Sky Blue

    glVertex2f(-1, 0);
    glVertex2f(1, 0);
    glVertex2f(1, 1);
    glVertex2f(-1, 1);
    glEnd();
    sunComponent();
    cloudviewDAy();
    //Field
    glBegin(GL_QUADS);
    glColor3ub(15, 240, 30); // Green

    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glVertex2f(1, 0);
    glVertex2f(-1, 0);
    glEnd();

    //Field White line Polygon
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255); // White
    glVertex2f(-1, -0.4);
    glVertex2f(1, -0.4);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255); // White
    glVertex2f(0, -0.4);
    glVertex2f(0, -1);
    glEnd();

    //Fench Left
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128); // Gray color

    glVertex2f(-1, 0);
    glVertex2f(-0.8, 0);
    glVertex2f(0.73, 0.2);
    glVertex2f(-1, 0.2);
    glEnd();

    //Fench Right
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128); // Gray color

    glVertex2f(0.8, 0);
    glVertex2f(1, 0);
    glVertex2f(1, 0.2);
    glVertex2f(0.73, 0.2);
    glEnd();


    //Lower Portion
    glBegin(GL_QUADS);
    glColor3ub(226, 220, 205); // Dark Lavender

    glVertex2f(-0.8, -0.15);
    glVertex2f(0.8, -0.15);
    glVertex2f(0.8, 0);
    glVertex2f(-0.8, 0);
    glEnd();

    //Roof
    glBegin(GL_QUADS);
    glColor3ub(226, 220, 205); // Dark Lavender

    glVertex2f(-0.8, 0.6);
    glVertex2f(0.8, 0.6);
    glVertex2f(0.8, 0.7);
    glVertex2f(-0.8, 0.7);
    glEnd();

    //Roof Polygon
    glBegin(GL_POLYGON);
    glColor3ub(226, 220, 205); // Light Lavender

    glVertex2f(-0.8, 0.7);
    glVertex2f(-0.6, 0.8);
    glVertex2f(-0.4, 0.7);
    glVertex2f(-0.2, 0.8);
    glVertex2f(0, 0.7);
    glVertex2f(0.2, 0.8);
    glVertex2f(0.4, 0.7);
    glVertex2f(0.6, 0.8);
    glVertex2f(0.8, 0.7);
    glVertex2f(-0.8, 0.7);
    glEnd();

    //Gallery Lower Portion
    glBegin(GL_QUADS);
    glColor3ub(8, 96, 255); // Orange color

    glVertex2f(-0.8, 0);
    glVertex2f(0.8, 0);
    glVertex2f(0.73, 0.2);
    glVertex2f(-0.73, 0.2);
    glEnd();


    //Gallery Middle Portion
    glBegin(GL_QUADS);
    glColor3ub(223, 230, 205); // Blue color

    glVertex2f(-0.73, 0.2);
    glVertex2f(0.73, 0.2);
    glVertex2f(0.67, 0.4);
    glVertex2f(-0.67, 0.4);
    glEnd();

    //Gallery Upper Portion
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 255); // Orange color

    glVertex2f(-0.67, 0.4);
    glVertex2f(0.67, 0.4);
    glVertex2f(0.6, 0.6);
    glVertex2f(-0.6, 0.6);
    glEnd();


    //Gallery Door
    glBegin(GL_QUADS);
    glColor3ub(194, 24, 7); // Yellow

    glVertex2f(-0.13, 0.2);
    glVertex2f(0.13, 0.2);
    glVertex2f(0.13, 0);
    glVertex2f(-0.13, 0);
    glEnd();

    //Gallery Door Upper Portion
    glBegin(GL_QUADS);
    glColor3ub(194, 24, 7); // Sky Blue

    glVertex2f(-0.06, 0.35);
    glVertex2f(0.06, 0.35);
    glVertex2f(0.06, 0.2);
    glVertex2f(-0.06, 0.2);
    glEnd();
    //gate
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255); // Sky Blue

    glVertex2f(-0.03, 0.21);
    glVertex2f(0.03, 0.21);
    glVertex2f(0.03, 0);
    glVertex2f(-0.03, 0);
    glEnd();

    //chair
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255); // Black

    glVertex2f(-0.7, 0);
    glVertex2f(-0.7, 0.6);
    glEnd();


    //Piller Left 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255); // White

    glVertex2f(-0.72, 0.6);
    glVertex2f(-0.68, 0.6);
    glVertex2f(-0.68, 0);
    glVertex2f(-0.72, 0);
    glEnd();

    //Piller Left 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255); // White

    glVertex2f(-0.32, 0.6);
    glVertex2f(-0.28, 0.6);
    glVertex2f(-0.28, 0);
    glVertex2f(-0.32, 0);
    glEnd();

    //Piller Right 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255); // White

    glVertex2f(0.28, 0.6);
    glVertex2f(0.32, 0.6);
    glVertex2f(0.32, 0);
    glVertex2f(0.28, 0);
    glEnd();

    //Piller Right 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255); // White

    glVertex2f(0.68, 0.6);
    glVertex2f(0.72, 0.6);
    glVertex2f(0.72, 0);
    glVertex2f(0.68, 0);
    glEnd();




}
void scoreboard() {

    glPushMatrix();
    glTranslatef(scoreboard_position_x, scoreboard_position_y, 0.0f);
    // glRotatef(character_rotation, 0.0f, 0.0f, 1.0f);  // Rotate around z-axis
    glScalef(scoreboard_scale, scoreboard_scale, 1.0);
    //Score Board
    glBegin(GL_QUADS);//Score Board
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0); // Black

    glVertex2f(0.16, 0.84);
    glVertex2f(0.84, 0.84);
    glVertex2f(0.84, 0.16);
    glVertex2f(0.16, 0.16);
    glEnd();

    //Score Board
    glBegin(GL_QUADS);
    glColor3ub(0, 204, 255); // Yellow

    glVertex2f(0.2, 0.8);
    glVertex2f(0.8, 0.8);
    glVertex2f(0.8, 0.2);
    glVertex2f(0.2, 0.2);
    glEnd();

    //Horizontal Line
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0); // Black

    glVertex2f(0.2, 0.6);
    glVertex2f(0.8, 0.6);
    glEnd();

    //Vertical Line
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0); // Black

    glVertex2f(0.5, 0.8);
    glVertex2f(0.5, 0.6);
    glEnd();

    // Colon Upper
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0); // Black

    glVertex2f(0.49, 0.45);
    glVertex2f(0.51, 0.45);
    glVertex2f(0.51, 0.43);
    glVertex2f(0.49, 0.43);
    glEnd();

    // Colon Below
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0); // Black

    glVertex2f(0.49, 0.37);
    glVertex2f(0.51, 0.37);
    glVertex2f(0.51, 0.35);
    glVertex2f(0.49, 0.35);
    glEnd();
    glColor3f(1.0, 0.0, 0.0);  // Set color to red for the goal message
    drawString("player-1 :", 0.28, 0.7);

    glColor3f(1.0, 0.0, 0.0);  // Set color to red for the goal message
    drawString(to_string(player_1_score), 0.28, 0.39);

    glColor3f(1.0, 0.0, 0.0);  // Set color to red for the goal message
    drawString("player-2 :", 0.58, 0.7);

    glColor3f(1.0, 0.0, 0.0);  // Set color to red for the goal message
    drawString(to_string(player_2_score), 0.6, 0.39);

    if (Short <= 0.5) {
        if (player_1_score > player_2_score) {
            glColor3f(1.0, 0.0, 0.0);  // Set color to red for the goal miss message
            drawString("Player-1 is The Winnern !", 0.38, 0.25);
        }
        if (player_1_score < player_2_score) {
            glColor3f(1.0, 0.0, 0.0);  // Set color to red for the goal miss message
            drawString("Player-2 is The Winnern !", 0.38, 0.25);
        }
        if (player_1_score == player_2_score) {
            glColor3f(1.0, 0.0, 0.0);  // Set color to red for the goal miss message
            drawString("This Match Was Draw !", 0.38, 0.25);
        }
    }
    if (goalScored) {

        glColor3f(1.0, 0.0, 0.0);  // Set color to red for the goal message
        drawString("Goal!", 0.45, 0.5);
    }
    if (goalMissed) {
        glColor3f(1.0, 0.0, 0.0);  // Set color to red for the goal miss message
        drawString("Goal Miss", 0.45, 0.5);
    }
    glPopMatrix();
}
void drawFootball(GLfloat cx, GLfloat cy, GLfloat radius) {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < 360; ++i) {
        float theta = i * (3.14159265359 / 180.0);
        float x = cx + radius * cos(theta);
        float y = cy + radius * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();
}
void drawRectangle(GLfloat x, GLfloat y, GLfloat width, GLfloat height) {
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

void mouseClick(int button, int state, int x, int y) {
    if (!goalScored && !goalMissed && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && !mouseClicked) {
        // Convert mouse coordinates to normalized device coordinates
        targetX = (x / static_cast<GLfloat>(glutGet(GLUT_WINDOW_WIDTH))) * 2 - 1;
        targetY = ((glutGet(GLUT_WINDOW_HEIGHT) - y) / static_cast<GLfloat>(glutGet(GLUT_WINDOW_HEIGHT))) * 2 - 1;
        mouseClicked = true;
    }
}


void update(int value) {

    if (cloud_position < -1.2)
        cloud_position = 1.2f;
    cloud_position -= cloud_speed;
    if (!character_movement)
        character_position_x += character_speed;
    if (character_position_x > 0.35)
        character_position_x = 0.35;
    if (character_position_x < -0.35)
        character_position_x = -0.35;


    moveFootballTowardsTarget();
    glutPostRedisplay();
    glutTimerFunc(20, update, 0);


}



bool tTime = false;
void timer(int value) {
    if (countdown > -1) {
        std::cout << countdown << std::endl;
        countdown--;
        glutPostRedisplay(); // Trigger a redraw
        glutTimerFunc(1000, timer, 0); // Set the timer for the next second

    }

}

void CircleP(GLfloat cx, GLfloat cy, GLfloat radius)
{

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= triangleAmount; i++) {
        glVertex2f(cx + (radius * cos(i * twicePi / triangleAmount)), cy + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
}

void score() {
    glColor3f(1.0, 0.0, 0.0);  // Set color to red for the goal message
    drawString("player-1 :", -0.85, -0.85);
    if (!player_1) {
        glColor3f(1.0f, 0.0f, 1.0f); // Set color to white (RGB: 255, 255, 255)
        CircleP(-0.90, -0.835, 0.03);
    }

    glColor3f(0.0, 0.0, 1.0);  // Set color to red for the goal message
    drawString(to_string(player_1_score), -0.6, -0.855);

    glColor3f(1.0, 0.0, 0.0);  // Set color to red for the goal message
    drawString("player-2 :", -0.85, -0.95);

    if (player_1) {
        glColor3f(1.0f, 0.0f, 1.0f); // Set color to white (RGB: 255, 255, 255)
        CircleP(-0.90, -0.935, 0.03);
    }
    glColor3f(0.0, 0.0, 1.0);  // Set color to red for the goal message
    drawString(to_string(player_2_score), -0.6, -0.955);

    glColor3f(1.0, 0.0, 0.0);  // Set color to red for the goal message
    drawString("Number Of Shorts :", -0.3, -0.925);

    //short

    glColor3f(1.0f, 1.0f, 1.0f); // Set color to white (RGB: 255, 255, 255)
    if (Short <= 5.0) {
        CircleP(0.05, -0.91, 0.03);
    }
    if (Short <= 4.0) {
        CircleP(0.05, -0.91, 0.03);
        CircleP(0.15, -0.91, 0.03);
    }
    if (Short <= 3.0) {
        CircleP(0.05, -0.91, 0.03);
        CircleP(0.15, -0.91, 0.03);
        CircleP(0.25, -0.91, 0.03);
    }
    if (Short <= 2.0) {
        CircleP(0.05, -0.91, 0.03);
        CircleP(0.15, -0.91, 0.03);
        CircleP(0.25, -0.91, 0.03);
        CircleP(0.35, -0.91, 0.03);
    }
    if (Short <= 1.0) {
        CircleP(0.45, -0.91, 0.03);
    }

    /*
     if(Short==5.0){
         CircleP(0.05, -0.91, 0.03);}
     if(Short==4.0){
         CircleP(0.05, -0.91, 0.03);
         CircleP(0.15, -0.91, 0.03);}
     if(Short==3.0){
         CircleP(0.05, -0.91, 0.03);
         CircleP(0.15, -0.91, 0.03);
         CircleP(0.25, -0.91, 0.03);}
     if(Short==2.0){
         CircleP(0.05, -0.91, 0.03);
         CircleP(0.15, -0.91, 0.03);
         CircleP(0.25, -0.91, 0.03);
         CircleP(0.35, -0.91, 0.03);}
     if(Short==1.0){
         CircleP(0.05, -0.91, 0.03);
         CircleP(0.15, -0.91, 0.03);
         CircleP(0.25, -0.91, 0.03);
         CircleP(0.35, -0.91, 0.03);
         CircleP(0.45, -0.91, 0.03);}
            glColor3f(1.0f, 1.0f, 1.0f); // Set color to white (RGB: 255, 255, 255)
            CircleP(-0.63, -0.835, 0.03);

             //short 1

            //glColor3f(1.0f, 1.0f, 1.0f); // Set color to white (RGB: 255, 255, 255)
            CircleP(-0.63, -0.935, 0.03);


            //short 2

          //  glColor3f(1.0f, 1.0f, 1.0f); // Set color to white (RGB: 255, 255, 255)
            CircleP(-0.56, -0.835, 0.03);

            //short 2

           // glColor3f(1.0f, 1.0f, 1.0f); // Set color to white (RGB: 255, 255, 255)
            CircleP(-0.56, -0.935, 0.03);


            //short 3

           // glColor3f(1.0f, 1.0f, 1.0f); // Set color to white (RGB: 255, 255, 255)
            CircleP(-0.49, -0.835, 0.03);


            //short 3

           // glColor3f(1.0f, 1.0f, 1.0f); // Set color to white (RGB: 255, 255, 255)
            CircleP(-0.49, -0.935, 0.03);



            //short 4

           // glColor3f(1.0f, 1.0f, 1.0f); // Set color to white (RGB: 255, 255, 255)
            CircleP(-0.42, -0.835, 0.03);



            //short 4

          //  glColor3f(1.0f, 1.0f, 1.0f); // Set color to white (RGB: 255, 255, 255)
            CircleP(-0.42, -0.935, 0.03);

            //short 5

           // glColor3f(1.0f, 1.0f, 1.0f); // Set color to white (RGB: 255, 255, 255)
            CircleP(-0.35, -0.835, 0.03);

            //short 5

           // glColor3f(1.0f, 1.0f, 1.0f); // Set color to white (RGB: 255, 255, 255)
            CircleP(-0.35, -0.935, 0.03);

            //Short = 5;
         //  player_1_score=0;
         //   player_1_score=0;
           newgame=true;
            return;
       }
      //  else{
        //short 1


      //  }
        return;
         */

}
void drawText(float x, float y, const std::string& text) {
    glRasterPos2f(x, y);
    for (char c : text) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}
bool Intro = false;
void intro() {
    glClearColor(0.529f, 0.808f, 0.922f, 0.0f);

    // Set text color to white
    glColor3f(1.0, 0.0, 1.0);

    glBegin(GL_QUADS);
    glColor3ub(204, 255, 255); // Black

    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glVertex2f(1, 1);
    glVertex2f(-1, 1);
    glEnd();



    glColor3ub(0, 0, 0);
    drawString("American International University Bangladesh(AIUB)", -0.3, 0.6);
    drawString("Course : Computer Graphics", -0.18, 0.5);
    drawString("Section : G ,Semester : Fall 23-24", -0.22, 0.4);
    drawString("Project Title: Penalty Shootout in Cartoon Graphics using OpenGL (GLUT)", -0.4, 0.3);
    drawString("Team Members :", -0.22, 0.2);
    drawString("1. JONAYAT HOSSAIN ,ID : 21-45037-2", -0.22, 0.1);
    drawString("2. AROBI AMIN ,ID : 21-45068-2", -0.22, 0);
    drawString("3. MD. TANVIR ISLAM ,ID :  21-45087-2", -0.22, -0.1);
    drawString("4. MD. JISAN ,ID : 21-45146-2, -0.18", -0.22, -0.2);
    drawString("5. MD. AMINUR RAHMAN ASIF ,ID :  21-45380-2", -0.22, -0.3);
    drawString(" Course Moderator : MAHFUJUR RAHMAN", -0.25, -0.4);

}

void pauseMainLoopForTwoSeconds() {
    int startTime = glutGet(GLUT_ELAPSED_TIME);

    while ((glutGet(GLUT_ELAPSED_TIME) - startTime) < 1000) {
        // Wait for 2 seconds
    }
}
bool delay = false;
void display()
{
    if (!Intro) {
        intro();
    }
    else {
        glClear(GL_COLOR_BUFFER_BIT);
        SkyComponent();

        glTranslatef(+0.2f, 0.0f, 0.0f);
        building();
        glLoadIdentity();
        annex();
        groundview();
        glTranslatef(+0.2f, 0.0f, 0.0f);
        // goalP();
        glLoadIdentity();
        // plasticBox();


        drawHumanCharacter();


        score();
        glColor3f(0.5, 0.5, 0.5);  // Set color to gray for the rectangle
        drawRectangle(footballX - 0.025, footballY - 0.025, 0.05, 0.05);
        glColor3f(0.0, 0.0, 0.0);
        drawFootball(footballX, footballY, 0.03);

        if (!tTime) {
            if (countdown > 0) {
                glColor3f(1.0, 0.0, 0.0);
                drawString(std::to_string(countdown), -0.01, -0.45);
                character_movement = true;
                mouseClicked = true;


            }
            else if (countdown == 0) {
                glColor3f(1.0, 0.0, 0.0);
                drawString("Go!", -0.01, -0.45);
                character_movement = false;
                mouseClicked = false;

            }
            else {
                drawString(" ", -0.20, -0.80);

            }
        }
        if (goalScored) {

            glColor3f(1.0, 0.0, 0.0);  // Set color to red for the goal message
            drawString("Goal!", -0.5, -0.80);

            if (Count < 2) {
                if (!player_1 && Short == 5.0) {
                    player_1_score++;
                    // player_1=true;
                    // Short=Short-0.5;
                    Count++;
                }


                if (player_1 && Short == 4.5) {
                    player_2_score++;
                    // player_1=false;
                  //   Short=Short-0.5;
                    Count++;
                }
                if (!player_1 && Short == 4.0) {
                    player_1_score++;
                    //  player_1=true;
                   //   Short=Short-0.5;
                    Count++;
                }



                if (player_1 && Short == 3.5) {
                    player_2_score++;
                    //  player_1=false;
                   //   Short=Short-0.5;
                    Count++;
                }
                if (!player_1 && Short == 3.0) {
                    player_1_score++;
                    //  player_1=true;
                    //  Short=Short-0.5;
                    Count++;
                }



                if (player_1 && Short == 2.5) {
                    player_2_score++;
                    //  player_1=false;
                   //   Short=Short-0.5;
                    Count++;
                }
                if (!player_1 && Short == 2.0) {
                    player_1_score++;
                    //   player_1=true;
                    //   Short=Short-0.5;
                    Count++;
                }



                if (player_1 && Short == 1.5) {
                    player_2_score++;
                    //  player_1=false;
                   //   Short=Short-0.5;
                    Count++;
                }
                if (!player_1 && Short == 1.0) {
                    player_1_score++;
                    //  player_1=true;
                   //   Short=Short-0.5;
                    Count++;
                }

                if (player_1 && Short == 0.5) {
                    player_2_score++;
                    //  player_1=false;
                   //   Short=Short-0.5;
                    Count++;
                }
                pauseMainLoopForTwoSeconds();

            }



            gallery();
            scoreboard();

        }

        if (goalMissed) {
            glColor3f(1.0, 0.0, 0.0);  // Set color to red for the goal miss message
            drawString("Goal Miss", -0.5, -0.80);
            if (Count < 2) {
                if (!player_1 && Short == 5.0) {
                    //player_1_score++;
                  //  player_1=true;
                 //  Short=Short-0.5;
                    Count++;
                }



                if (player_1 && Short == 4.5) {
                    // player_2_score++;
                    // player_1=false;
                   //  Short=Short-0.5;
                    Count++;
                }
                if (!player_1 && Short == 4.0) {
                    //  player_1_score++;
                    //  player_1=true;
                    //  Short=Short-0.5;
                    Count++;
                }



                if (player_1 && Short == 3.5) {
                    //  player_2_score++;
                   //   player_1=false;
                   //   Short=Short-0.5;
                    Count++;
                }
                if (!player_1 && Short == 3.0) {
                    //  player_1_score++;
                    //  player_1=true;
                    //  Short=Short-0.5;
                    Count++;
                }


                if (player_1 && Short == 2.5) {
                    //    player_2_score++;
                    //    player_1=false;
                    //    Short=Short-0.5;
                    Count++;
                }
                if (!player_1 && Short == 2.0) {
                    //     player_1_score++;
                    //     player_1=true;
                    //     Short=Short-0.5;
                    Count++;
                }



                if (player_1 && Short == 1.5) {
                    //    player_2_score++;
                    //    player_1=false;
                    //    Short=Short-0.5;
                    Count++;
                }
                if (!player_1 && Short == 1.0) {
                    //    player_1_score++;
                     //   player_1=true;
                    //    Short=Short-0.5;
                    Count++;
                }

                if (player_1 && Short == 0.50) {
                    //     player_2_score++;
                     //    player_1=false;
                    //     Short=Short-0.5;
                    Count++;
                }
                pauseMainLoopForTwoSeconds();
            }
            gallery();
            scoreboard();

        }
    }
    //score();
    glFlush();
}
void falling() {

    //   for(character_position_y ;character_position_y != -0.150;character_position_y += character_falling_speed){}//



}
void jump() {
    if (!character_movement) {
        if (character_position_y <= -0.150) {
            character_position_y += 0.1;
            //falling();
            return;
        }

    }
    return;
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'a':
        if (!character_movement && Short >= 1) {
            character_rotation = 0.0f;
            character_speed = -0.01;

            character_position_y = -0.150;
        }
        break;
    case 'd':
        if (!character_movement && Short >= 1) {
            character_rotation = 0.0f;
            character_speed = 0.01;

            character_position_y = -0.150;
        }
        break;
    case 's':
        if (!character_movement && Short >= 1) {
            character_rotation = 0.0f;
            character_speed = 0.0;

            character_position_x = 0.0f;
            character_position_y = -0.150f;
        }
        break;
    case 'w':
        if (!character_movement && Short >= 1) {
            character_rotation = 0.0f;
            jump();
        }
        break;
    case 'z':
        if (!character_movement && Short >= 1) {
            character_rotation = 0.0f;
            character_position_y = -0.150;

        }
        break;
    case 'b':
        // character_scale *= 1.1;
        break;
    case 'v':
        // character_scale *= 0.9;
        break;
    case 'e':
        if (!character_movement && Short >= 1) {
            character_position_y = -0.150;
            if (character_rotation > -90.0) {
                character_rotation -= 45.0;
                if (character_rotation == -45.0) { character_position_y = -0.18; }
                if (character_rotation == -90.0) { character_position_y = -0.25; }
                character_speed = 0.0;
            }
        } // Rotate 45 degrees clockwise
        break;
    case 'q':
        if (!character_movement && Short >= 1) {
            if (character_rotation < 90.0) {
                character_position_y = -0.150;
                character_rotation += 45.0;
                if (character_rotation == +45.0) { character_position_y = -0.18; }
                if (character_rotation == +90.0) { character_position_y = -0.25; }
                character_speed = 0.0;
            }
        } // Rotate 135 degrees counterclockwise
        break;
    case 'r':
        if (Short >= 1) {
            mouseClicked = false;
            goalScored = false;
            goalMissed = false;
            character_movement = false;
            footballX = 0.0f;
            footballY = -0.70f;
            targetX = 0.0f;
            targetY = -0.7f;
            character_speed = 0.0;
            character_rotation = 0.0f;
            character_position_x = 0.0f;
            character_position_y = -0.150f;
            countdown = 3;
            tTime = false;
            glutTimerFunc(1000, timer, 0);
            if (!player_1) {
                player_1 = true;
            }
            else {
                player_1 = false;
            }
            Short = Short - 0.5;
            Count = 1;
        }
        break;
    case 'n':

        mouseClicked = false;
        goalScored = false;
        goalMissed = false;
        character_movement = false;
        footballX = 0.0f;
        footballY = -0.70f;
        targetX = 0.0f;
        targetY = -0.7f;
        character_speed = 0.0;
        character_rotation = 0.0f;
        character_position_x = 0.0f;
        character_position_y = -0.150f;
        countdown = 3;
        tTime = false;
        glutTimerFunc(1000, timer, 0);
        Short = 5;
        player_1_score = 0;
        player_2_score = 0;
        Count = 1;
        break;
    case ' ':
        Intro = true;
        break;



    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Grass");
    // Set up the timer
    glutTimerFunc(1000, timer, 0);
    glutDisplayFunc(display);

    glutMouseFunc(mouseClick);
    glutKeyboardFunc(keyboard);

    glutTimerFunc(100, update, 0);
    glClearColor(1.0, 1.0, 1.0, 1.0);  // Set background color to white

    // Set up the view matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    glutMainLoop();
    return 0;
}
