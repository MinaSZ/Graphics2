#pragma once
#include <glut.h>
#include <stdio.h>

class Defender {
public:
	GLUquadricObj *quadratic;
	Defender();
	int row;
	float posx;
	float posz;
	float bulletx;
	void drawDefender();
	//void drawBullet();
	bool hit;
};

Defender::Defender() {
	quadratic = gluNewQuadric();
	posx = -100;
	bulletx = posx;
	hit = false;
}

//void Defender::drawBullet() {
//	if (bulletx < 4.0 && !hit) {
//		if (alive) {
//			glPushMatrix();
//			glTranslatef(bulletx, 0.75f, posz);
//			glScalef(0.13f, 0.13f, 0.13f);
//			glColor3f(1.0f, 1.0f, 1.0f);
//			glutSolidSphere(0.9f, 10, 10);
//			glPopMatrix();
//		}
//	}
//	else {
//		hit = false;
//		bulletx = posx;
//		if (alive) {
//			glPushMatrix();
//			glTranslatef(bulletx, 0.75, posz);
//			glScalef(0.3, 0.3, 0.3);
//			glColor3f(1.0f, 1.0f, 1.0f);
//			glutSolidSphere(0.9f, 10, 10);
//			glPopMatrix();
//		}
//	}
//}

void Defender::drawDefender() {

		glPushMatrix();
		glTranslatef(0.0f, 0.0f, 0.0f);
		glScalef(0.7f, 0.7f, 0.7f);

		/*glPushMatrix();
		glTranslatef(0.0f, 0.0f, 0.0f);
		glRotatef(90.0, 1, 0, 0);
		glScalef(0.1f, 0.1f, 0.1f);
		glColor3f(1.0f, 0.0f, 0.0f);
		gluCylinder(quadratic, 2.0f, 2.0f, 10.0f, 32, 32);
		glPopMatrix();*/

		glPushMatrix();
		glTranslatef(0.0f, 0.0f, 0.0f);
		glRotatef(180.0, 0, 1, 0);
		glScalef(0.1f, 0.1f, 0.1f);
		glColor3f(1.0f, 0.0f, 0.0f);
		gluCylinder(quadratic, 2.0f, 2.0f, 7.0f, 32, 32);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, 0.0, 0);
		glScalef(0.3, 0.3, 0.3);
		glColor3f(0.0f, 0.0f, 0.0f);
		glutSolidSphere(1.0f, 10, 10);
		glPopMatrix();

		glPopMatrix();
}
