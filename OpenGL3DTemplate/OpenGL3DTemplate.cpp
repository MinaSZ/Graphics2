#include <vector>
#include <time.h>
#include <math.h>
#include <Attacker.h>
#include <Defender.h>
#include "glm/glm.hpp"

Attacker a;
Defender b;
int life = 2;

std::vector<Attacker> at;

void Key(unsigned char key, int x, int y) {

}


void Timer(int value) {
	Attacker a;
	a.radius = rand() % 11 + 10;
	/*int tmp = a.radius;
	a.x = (rand() % (tmp + 1)) + (-(tmp/2));*/
	a.x = rand() % 31 + (-15);
	a.z =  (pow((pow(a.radius, 2) - pow(a.x, 2)), 0.5));
	int num[] = {-1,1};
	a.sign = num[rand() % 2];

	if (a.x >= 0 && a.z >= 0) {
		a.rotAng = -(atanf((a.z*a.sign) / a.x) / PI) * 180;
	}
	else {
		if (a.x >= 0 && a.z < 0) {
			a.rotAng = -(atanf((a.z*a.sign) / a.x) / PI) * 180;
		}
		else {
			if (a.x < 0 && a.z < 0) {
				a.rotAng = -((atanf((a.z*a.sign) / a.x) / PI) * 180) - 180;
			}
			else {
				a.rotAng = 180 - ((atanf((a.z*a.sign) / a.x) / PI) * 180);
			}
		}
	}

	at.push_back(a);

	// ask OpenGL to recall the display function to reflect the changes on the window
	glutPostRedisplay();

	// recall the Timer function after 1 seconds (1,000 milliseconds)
	glutTimerFunc(5 * 1000, Timer, 0);
}

void updateGame() {
	for (int i = 0; i < at.size(); i++) {
		if (at[i].radius < 6.0) {
			life--;
			at.erase(at.begin() + i);
		}
	}
}

void Display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	printf("%i", life);

	updateGame();

	//Draw Land
	glPushMatrix();
	glTranslatef(0.0f, -1.5f, 0.0f);
	glScalef(30.0f, 0.1f, 30.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glutSolidCube(1.0f);
	glPopMatrix();

	//Draw Defender
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.0f);
	glScalef(0.5f, 0.5f, 0.5f);
	b.drawDefender();
	glPopMatrix();

	//Draw Attacker
	for (int i = 0; i < at.size(); i++) {
		at[i].drawAttacker();
	}

	glFlush();
}

void Anim() {
	float tmp;
	//Move Attacker
	for (int i = 0; i < at.size(); i++) {
		if (at[i].radius > 6.0) {
			at[i].radius = at[i].radius - 0.001;
			tmp = at[i].x * 0.000085;
			at[i].x = at[i].x - tmp;
			at[i].z = (pow((pow(at[i].radius, 2) - pow(at[i].x, 2)), 0.5));
		}
	}

	glutPostRedisplay();
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitWindowSize(1100, 650);
	glutInitWindowPosition(100, 50);

	glutCreateWindow("OpenGL - 3D Template");
	glutDisplayFunc(Display);
	glutIdleFunc(Anim);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, 300 / 300, 0.1f, 300.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0f, 40.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);  //gluLookAt(0.0f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	glutKeyboardFunc(Key);
	glutTimerFunc(0, Timer, 0);

	//srand(time(0));

	glutMainLoop();
}
