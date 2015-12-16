#include <vector>
#include <time.h>
#include <math.h>
#include <Attacker.h>
#include <Defender.h>
#include "glm/glm.hpp"

Attacker a;
Defender b;
int life = 2;

GLTexture tex_ground;
GLTexture tex_sky;
std::vector<Attacker> at;

float lookup = 0;
float lookdown = 0;
float lookleft = 0;
float lookright = 0;

float xcenter = 0;
float ycenter = 30;
float zcenter = -40;

bool gameOver = false;

char string[50];



void shoot() {
	float x = lookleft;
	int y = lookup;
	int d;
	if (x < 0) {
		d = -1;
	}
	else if (x>0) {
		d = 1;
	}
	else {
		d = 0;
	}
	for (float i = 0;i < 40;i += 0.1) {
		for (int j = 0;j < at.size();j++) {
			if (at[j].radius >= i & at[j].x >= x) {
				at.erase(at.begin() + j);
				break;
			}
		}
		x += d*0.1;
	}
}


void mouseshoot(int xm,int ym) {
	float x = xm;
	int y = ym;
	int d;
	if (x < 0) {
		d = -1;
	}
	else if (x>0) {
		d = 1;
	}
	else {
		d = 0;
	}
	for (float i = 0;i < 40;i += 0.5) {
		for (int j = 0;j < at.size();j++) {
			if (at[j].radius >= i & at[j].x >= x) {
				at.erase(at.begin() + j);
				break;
			}
		}
		x += d*0.1;
	}
}

void Loadtextures() {
	tex_ground.Load("Textures/ground3.bmp");
	tex_sky.Load("Textures/ground3.bmp");
}

void turnleft() {
	glRotatef(3, 0, -1, 0);
}
void turnright() {
	glRotatef(3, 0, 1, 0);
}
void turnup() {
	glRotatef(3, 1, 0, 0);
}
void turndown() {
	glRotatef(3, 1,0, 0);
}

void Key(unsigned char key, int x, int y) {

	switch (key) {
	case 'w':lookup-=0.5;break;
	case 's':lookup+=0.5;break;
	case 'a':lookleft-=0.5;break;
	case 'd':lookleft+=0.5;break;
	case 'k':shoot();break;
	}
	glutPostRedisplay();
}

void Timer(int value) {
	Attacker a;
	a.radius = rand() % 11 + 10;
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
		if (at[i].radius < 10.0) {
			life--;
			at.erase(at.begin() + i);
		}
	}

	if (life == 0) {
		gameOver = true;
	}
}

void skybox(void) {

	glEnable(GL_TEXTURE_2D);	// Enable 2D texturing

	glPushMatrix();
	//-x,x,-y,y,-z,z
	glDisable(GL_DEPTH_TEST);
	float x = 0;
	float y = 0;
	float z = 0;
	float width = 200;
	float height = 200;
	float length = 200;
	// Bind the BACK texture of the sky map to the BACK side of the cube
	glBindTexture(GL_TEXTURE_2D, tex_sky.texture[0]);
	// Center the skybox
	x = x - width / 2;
	//y  = y - height /2;
	z = z - length / 2;
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, tex_sky.texture[0]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z + length);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, tex_ground.texture[0]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y, z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, tex_sky.texture[0]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y + height, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, tex_sky.texture[0]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, tex_sky.texture[0]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z);
	glEnd();

	glPopMatrix();

	glEnable(GL_DEPTH_TEST);
	glDisable(GL_TEXTURE_2D);
	//glRotatef( angle, 1.0f, 1.0f, 1.0f )
	//glutSolidSphere(2, 40, 40);
}

void camera() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, 1100 / 650, 0.1f, 1000.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0f, 5.0f, 0.0f, xcenter, ycenter, zcenter, 0.0f, 1.0f, 0.0f);  //gluLookAt(0.0f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

}

void drawBitmaptext(char *string, float x, float y) {
	unsigned int c;
	glRasterPos2f(x, y);
	for (c = 0; c < strlen(string); c++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[c]);
	}
}

void Display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (gameOver) {
		printf("Game Over");

		glDisable(GL_TEXTURE_2D);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0f, 1100 / 650, 0.1f, 1000.0f);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(0.0f, 5.0f, 7.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

		glPushMatrix();
		glColor3f(1.0f, 0.0f, 0.0f);
		drawBitmaptext("Game Over", 300, 600);
		glPopMatrix();
	}

	else {
		printf("%i", life);

		camera();
		glRotatef(lookup, 1, 0, 0);
		glRotatef(lookleft, 0, 1, 0);

		glPushMatrix();

		updateGame();

		skybox();

		sprintf_s(string, "Life left: %i\n s", life);
		drawBitmaptext(string, 300, 600);

		//Draw Defender
		glPushMatrix();
		glTranslatef(0.0f, 3.0f, 0.0f);
		//	glScalef(0.5f, 0.5f, 0.5f);*/
		b.posy = lookup;
		b.posx = lookleft;
		b.drawDefender();
		glPopMatrix();

		//Draw Attacker
		for (int i = 0; i < at.size(); i++) {

			at[i].draw();
		}
		glPopMatrix();
	}
	glFlush();
}

void Anim() {
	if (!gameOver) {
		float tmp;
		//Move Attacker
		for (int i = 0; i < at.size(); i++) {
			if (at[i].radius > 2.0) {
				at[i].radius = at[i].radius - 0.001;
				tmp = at[i].x * 0.000085;
				at[i].x = at[i].x - tmp;
				at[i].z = (pow((pow(at[i].radius, 2) - pow(at[i].x, 2)), 0.5));
			}
		}
	}

	glutPostRedisplay();
}

void mouse(int b, int s, int x , int y) {
	if (GLUT_DOWN == b) {
		mouseshoot(x,y);
	}
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

	
	glutKeyboardFunc(Key);
	glutMouseFunc(mouse);
	glutTimerFunc(0, Timer, 0);

	Loadtextures();
	srand(time(0));

	glutMainLoop();
}
