#pragma once
#include <glut.h>
#include "Model_3DS.h"
#include <math.h>
#define PI 3.1415926535897932384626433832795

class Attacker {
public:
	Model_3DS attackermodel1,attackermodel2,attackermodel3;
	GLUquadricObj *quadratic;
	float radius;
	float x;
	float z;
	float rotAng;
	int health;
	int sign;
	int pose;
	float i;
	Attacker();
	void Load(int i) {
		switch (i) {
		case 1: attackermodel1.Draw();break;
		case 2: attackermodel2.Draw();break;
		case 3: attackermodel3.Draw();break;
		case 4: attackermodel2.Draw();break;
		}
	}
	void draw() {
		if (i >= 1) {
			if (pose == 4) {
				pose = 1;
			}
			else {
				pose++;
			}
			i = 0;
		}
		glPushMatrix();
		glTranslatef(x, -1.0f, z*sign);
		glScalef(0.3, 0.3, 0.3);
		glRotatef(rotAng, 0, 1, 0);
		glPushMatrix();
		glRotatef(90, 0, -1, 0);
		Load(pose);
		glPopMatrix();
		glPopMatrix();
//		x -= 0.001*d;
//		z -= 0.001;
		i += 0.01;
	}
};

Attacker::Attacker() {
	quadratic = gluNewQuadric();
	health = 2;
	pose = 1;
	i = 0;
	attackermodel1.Load("Models/bot/bot1.3ds");
	attackermodel2.Load("Models/bot/bot2.3ds");
	attackermodel3.Load("Models/bot/bot3.3ds");
}

void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius) {
	int i;
	int triangleAmount = 20; //# of triangles used to draw circle

							 //GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y); // center of circle
	for (i = 0; i <= triangleAmount;i++) {
		glVertex2f(
			x + (radius * cos(i *  twicePi / triangleAmount)),
			y + (radius * sin(i * twicePi / triangleAmount))
			);
	}
	glEnd();
}


//void Attacker::drawAttacker() {

	
	
	
	//glPushMatrix();
		//glTranslatef(x, -1.0f, z*sign);
		//glScalef(0.5f, 0.5f, 0.5f);
		//glRotatef(rotAng, 0, 1, 0);

		////rectangle
		//glPushMatrix();
		//glTranslatef(0.0f, -0.35f, 0.0f);
		//glScalef(1.5f, 0.7f, 1.0f);
		//if (health > 1)
		//	glColor3f(1.0f, 0.0f, 0.0f);
		//else
		//	glColor3f(0.5f, 0.5f, 0.0f);
		//glutSolidCube(1);
		//glPopMatrix();

		//if (health > 1) {
		//	//Dodecahedron
		//	glPushMatrix();
		//	glScalef(0.2, 0.2, 0.2);
		//	glColor3f(0.0f, 0.0f, 0.0f);
		//	glutSolidDodecahedron();
		//	glPopMatrix();
		//}

		////CenterCone
		//glPushMatrix();
		//glTranslatef(-0.7, -0.3, 0.0);
		//glRotatef(270.0, 0, 1, 0);
		//glScalef(0.45, 0.45, 0.45);
		//glColor3f(0.0f, 0.0f, 1.0f);
		//glutSolidCone(0.3f, 0.8f, 10.0, 10.0);
		//glPopMatrix();

		//if (health > 1) {
		//	//RightCone
		//	glPushMatrix();
		//	glTranslatef(-0.7, -0.3, 0.3);
		//	glRotatef(270.0, 0, 1, 0);
		//	glScalef(0.45, 0.45, 0.45);
		//	glColor3f(0.0f, 0.0f, 1.0f);
		//	glutSolidCone(0.3f, 0.8f, 10.0, 10.0);
		//	glPopMatrix();
		//}

		//if (health > 1) {
		//	//LeftCone
		//	glPushMatrix();
		//	glTranslatef(-0.7, -0.3, -0.3);
		//	glRotatef(270.0, 0, 1, 0);
		//	glScalef(0.45, 0.45, 0.45);
		//	glColor3f(0.0f, 0.0f, 1.0f);
		//	glutSolidCone(0.3f, 0.8f, 10.0, 10.0);
		//	glPopMatrix();
		//}

		////Wheel 1
		//glPushMatrix();
		//glTranslatef(0.4f, -0.7f, 0.5f);

		//glPushMatrix();
		//glTranslatef(0.0f, 0.0f, 0.0f);
		//glScalef(0.05f, 0.05f, 0.05f);
		//glColor3f(1.0f, 1.0f, 0.0f);
		//gluCylinder(quadratic, 3.0f, 3.0f, 3.0f, 32, 32);
		//glPopMatrix();

		//glPushMatrix();
		//glTranslatef(0.0, -0.27, 0.0);
		//glScalef(0.05, 0.05, 0.05);
		//glColor3f(1.0, 1.0, 0.0);
		//drawFilledCircle(0.0, 5.5, 3.02);
		//glPopMatrix();

		//glPushMatrix();
		//glTranslatef(0.0, -0.27, 0.15);
		//glScalef(0.05, 0.05, 0.05);
		//glColor3f(1.0, 1.0, 0.0);
		//drawFilledCircle(0.0, 5.5, 3.02);
		//glPopMatrix();

		//glPopMatrix();

		////Wheel 2
		//glPushMatrix();
		//glTranslatef(-0.4f, -0.7f, 0.5f);

		//glPushMatrix();
		//glTranslatef(0.0f, 0.0f, 0.0f);
		//glScalef(0.05f, 0.05f, 0.05f);
		//glColor3f(1.0f, 1.0f, 0.0f);
		//gluCylinder(quadratic, 3.0f, 3.0f, 3.0f, 32, 32);
		//glPopMatrix();

		//glPushMatrix();
		//glTranslatef(0.0, -0.27, 0.0);
		//glScalef(0.05, 0.05, 0.05);
		//glColor3f(1.0, 1.0, 0.0);
		//drawFilledCircle(0.0, 5.5, 3.02);
		//glPopMatrix();

		//glPushMatrix();
		//glTranslatef(0.0, -0.27, 0.15);
		//glScalef(0.05, 0.05, 0.05);
		//glColor3f(1.0, 1.0, 0.0);
		//drawFilledCircle(0.0, 5.5, 3.02);
		//glPopMatrix();

		//glPopMatrix();

		////Wheel 3
		//glPushMatrix();
		//glTranslatef(0.4f, -0.7f, -0.65f);

		//glPushMatrix();
		//glTranslatef(0.0f, 0.0f, 0.0f);
		//glScalef(0.05f, 0.05f, 0.05f);
		//glColor3f(1.0f, 1.0f, 0.0f);
		//gluCylinder(quadratic, 3.0f, 3.0f, 3.0f, 32, 32);
		//glPopMatrix();

		//glPushMatrix();
		//glTranslatef(0.0, -0.27, 0.0);
		//glScalef(0.05, 0.05, 0.05);
		//glColor3f(1.0, 1.0, 0.0);
		//drawFilledCircle(0.0, 5.5, 3.02);
		//glPopMatrix();

		//glPushMatrix();
		//glTranslatef(0.0, -0.27, 0.15);
		//glScalef(0.05, 0.05, 0.05);
		//glColor3f(1.0, 1.0, 0.0);
		//drawFilledCircle(0.0, 5.5, 3.02);
		//glPopMatrix();

		//glPopMatrix();

		////Wheel 4
		//glPushMatrix();
		//glTranslatef(-0.4f, -0.7f, -0.65f);

		//glPushMatrix();
		//glTranslatef(0.0f, 0.0f, 0.0f);
		//glScalef(0.05f, 0.05f, 0.05f);
		//glColor3f(1.0f, 1.0f, 0.0f);
		//gluCylinder(quadratic, 3.0f, 3.0f, 3.0f, 32, 32);
		//glPopMatrix();

		//glPushMatrix();
		//glTranslatef(0.0, -0.27, 0.0);
		//glScalef(0.05, 0.05, 0.05);
		//glColor3f(1.0, 1.0, 0.0);
		//drawFilledCircle(0.0, 5.5, 3.02);
		//glPopMatrix();

		//glPushMatrix();
		//glTranslatef(0.0, -0.27, 0.15);
		//glScalef(0.05, 0.05, 0.05);
		//glColor3f(1.0, 1.0, 0.0);
		//drawFilledCircle(0.0, 5.5, 3.02);
		//glPopMatrix();

		//glPopMatrix();

		//glPopMatrix();
//}