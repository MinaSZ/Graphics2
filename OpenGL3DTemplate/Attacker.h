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
		glTranslatef(x,0.0f, z*sign);
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
	int triangleAmount = 20; //# of triangles used to draw circlem

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

