#pragma once
#include <glut.h>
#include <stdio.h>
#include "Model_3DS.h"

class Defender {
public:
	GLUquadricObj *quadratic;
	Model_3DS gun;
	Defender();
	int row;
	float posx;
	float posy;
	float bulletx;
	float bullety;
	void drawDefender();
	//void drawBullet();
	bool hit;
};

Defender::Defender() {
	gun.Load("Models/MP5K/M5K.3ds");
	quadratic = gluNewQuadric();
	posx = -100;
	bulletx = posx;
	bullety = posy;
	hit = false;
}


void Defender::drawDefender() {

		glPushMatrix();
		glTranslatef(0.0f,posy-5, 0.0f);
		glScalef(0.05,0.05,0.05);
		glRotatef(posx, 0, 1, 0);
		glRotatef(posy, 1, 0, 0);
		gun.Draw();

		glPopMatrix();
}
