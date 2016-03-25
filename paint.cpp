#include <D:/Program_Files/Projects/kurs2/semestr2/SP/openglhabra/openglhabra1/openglhabra1/for_all.h>

void draw_bob(bool near_stone,float y_jump,int time_jump) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	if (near_stone == true){
		glTranslated(0, y_jump, 0);
		if (time_jump > 36){ y_jump += 0.05; }
		else { y_jump -= 0.05; }
		printf("DA/////");
	}
	//∆елтое тело
	glColor3d(0.8, 0.8, 0);
	glPushMatrix();
	glScaled(1, 1.3, 0.6);
	glTranslated(0, 0, 0);
	glutSolidCube(5);
	glPopMatrix();
	//рубаха
	glColor3d(1, 1, 1);
	glPushMatrix();
	glScaled(2.75, 0.8, 1.8);
	glTranslated(0, -4.9, 0);
	glutSolidCube(1.8);
	glPopMatrix();
	//шорты
	glColor3d(0.58, 0.29, 0);
	glPushMatrix();
	glScaled(2.75, 0.8, 1.8);
	glTranslated(0.0, -6.5, 0.0);
	glutSolidCube(1.8);
	glPopMatrix();



	//века лева¤
	//left
	glColor3d(0, 0, 0);
	glPushMatrix();
	glRotated(20, 0, 0, 1);
	glScaled(0.1, 0.4, 0.1);
	glTranslated(-6, 5, 15);
	glutSolidCube(2);
	glPopMatrix();
	//center
	glColor3d(0, 0, 0);
	glPushMatrix();
	glScaled(0.1, 0.4, 0.1);
	glTranslated(-9, 4.5, 15);
	glutSolidCube(2);
	glPopMatrix();
	//rigth
	glColor3d(0, 0, 0);
	glPushMatrix();
	glRotated(-20, 0, 0, 1);
	glScaled(0.1, 0.4, 0.1);
	glTranslated(-11, 3.5, 15);
	glutSolidCube(2);
	glPopMatrix();


	//глаз левый
	glColor3d(1, 1, 1);
	glPushMatrix();
	glTranslated(-0.9, 1, 1.1);
	glutSolidSphere(0.9, 20, 20);
	glPopMatrix();
	//сини¤ фигн¤ левый глаз
	glColor3d(0, 0.74, 1);
	glPushMatrix();
	glTranslated(-0.9, 1, 1.75);
	glutSolidSphere(0.4, 30, 30);
	glPopMatrix();
	//зрачек левый
	glColor3d(0, 0, 0);
	glPushMatrix();
	glTranslated(-0.9, 1, 2.0);
	glutSolidSphere(0.2, 30, 30);
	glPopMatrix();



	//правй глаз
	glColor3d(1, 1, 1);
	glPushMatrix();
	glTranslated(0.9, 1, 1.1);
	glutSolidSphere(0.9, 20, 20);
	glPopMatrix();
	//сини¤ фигн¤ ѕ–ј¬џ… глаз
	glColor3d(0, 0.74, 1);
	glPushMatrix();
	glTranslated(0.9, 1, 1.75);
	glutSolidSphere(0.4, 30, 30);
	glPopMatrix();
	//зрачек ѕ–ј¬џ…
	glColor3d(0, 0, 0);
	glPushMatrix();
	glTranslated(0.9, 1, 2.0);
	glutSolidSphere(0.2, 30, 30);
	glPopMatrix();

	// века права¤
	//left
	glColor3d(0, 0, 0);
	glPushMatrix();
	glRotated(20, 0, 0, 1);
	glScaled(0.1, 0.4, 0.1);
	glTranslated(10.5, 3.5, 15);
	glutSolidCube(2);
	glPopMatrix();
	//center
	glColor3d(0, 0, 0);
	glPushMatrix();
	glScaled(0.1, 0.4, 0.1);
	glTranslated(9, 4.5, 15);
	glutSolidCube(2);
	glPopMatrix();
	//rigth
	glColor3d(0, 0, 0);
	glPushMatrix();
	glRotated(-20, 0, 0, 1);
	glScaled(0.1, 0.4, 0.1);
	glTranslated(5, 5, 15);
	glutSolidCube(2);
	glPopMatrix();


	//Ќос
	glColor3d(0.8, 0.8, 0);
	glPushMatrix();
	glScaled(0.15, 0.15, 0.6);
	glTranslated(0, 0, 2);
	glutSolidSphere(2, 20, 20);
	glPopMatrix();


	//рот
	glColor3d(0.85, 0, 0);
	glPushMatrix();
	glScaled(0.5, 0.1, 0.1);
	glTranslated(0, -11, 15);
	glutSolidSphere(2, 20, 20);
	glPopMatrix();


	//зубы
	//левый
	glColor3d(0.85, 0.85, 0.85);
	glPushMatrix();
	glScaled(0.2, 0.3, 0.1);
	glTranslated(-2, -4.5, 15);
	glutSolidCube(2);
	glPopMatrix();
	//правый
	glColor3d(0.85, 0.85, 0.85);
	glPushMatrix();
	glScaled(0.2, 0.3, 0.1);
	glTranslated(2, -4.5, 15);
	glutSolidCube(2);
	glPopMatrix();

	//галстух
	glColor3f(0.8, 0, 0);
	glPushMatrix();
	glBegin(GL_TRIANGLES);
	glVertex3f(0.0, -3.6, 1.7);
	glVertex3f(-0.4, -3.2, 1.7);
	glVertex3f(0.4, -3.2, 1.7);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(0, -3.6, 1.7);
	glVertex3f(-0.3, -3.8, 1.7);
	glVertex3f(0, -4.4, 1.7);
	glVertex3f(0.3, -3.8, 1.7);
	glEnd();
	glPopMatrix();

	//ремень
	//1
	glColor3f(0, 0, 0);
	glPushMatrix();
	glBegin(GL_QUADS);
	glVertex3f(-2, -5, 1.65);
	glVertex3f(-2, -5.2, 1.65);
	glVertex3f(-1.3, -5.2, 1.65);
	glVertex3f(-1.3, -5, 1.65);
	glEnd();
	//2
	glBegin(GL_QUADS);
	glVertex3f(-0.9, -5, 1.65);
	glVertex3f(-0.9, -5.2, 1.65);
	glVertex3f(-0.2, -5.2, 1.65);
	glVertex3f(-0.2, -5, 1.65);
	glEnd();

	//3
	glBegin(GL_QUADS);
	glVertex3f(0.2, -5, 1.65);
	glVertex3f(0.2, -5.2, 1.65);
	glVertex3f(0.9, -5.2, 1.65);
	glVertex3f(0.9, -5, 1.65);
	glEnd();

	//4
	glBegin(GL_QUADS);
	glVertex3f(1.3, -5, 1.65);
	glVertex3f(1.3, -5.2, 1.65);
	glVertex3f(2, -5.2, 1.65);
	glVertex3f(2, -5, 1.65);
	glEnd();

	//1.1
	glColor3f(0, 0, 0);

	glBegin(GL_QUADS);
	glVertex3f(-2, -5, -1.65);
	glVertex3f(-2, -5.2, -1.65);
	glVertex3f(-1.3, -5.2, -1.65);
	glVertex3f(-1.3, -5, -1.65);
	glEnd();
	//1.2
	glBegin(GL_QUADS);
	glVertex3f(-0.9, -5, -1.65);
	glVertex3f(-0.9, -5.2, -1.65);
	glVertex3f(-0.2, -5.2, -1.65);
	glVertex3f(-0.2, -5, -1.65);
	glEnd();

	//1.3
	glBegin(GL_QUADS);
	glVertex3f(0.2, -5, -1.65);
	glVertex3f(0.2, -5.2, -1.65);
	glVertex3f(0.9, -5.2, -1.65);
	glVertex3f(0.9, -5, -1.65);
	glEnd();

	//1.4
	glBegin(GL_QUADS);
	glVertex3f(1.3, -5, -1.65);
	glVertex3f(1.3, -5.2, -1.65);
	glVertex3f(2, -5.2, -1.65);
	glVertex3f(2, -5, -1.65);
	glEnd();

	//5

	glBegin(GL_QUADS);
	glVertex3f(2.5, -5, -1.2);
	glVertex3f(2.5, -5.2, -1.2);
	glVertex3f(2.5, -5.2, -0.5);
	glVertex3f(2.5, -5, -0.5);
	glEnd();
	//6
	glBegin(GL_QUADS);
	glVertex3f(2.5, -5, 0.3);
	glVertex3f(2.5, -5.2, 0.3);
	glVertex3f(2.5, -5.2, 1);
	glVertex3f(2.5, -5, 1);
	glEnd();

	//5.1
	glBegin(GL_QUADS);
	glVertex3f(-2.5, -5, -1.2);
	glVertex3f(-2.5, -5.2, -1.2);
	glVertex3f(-2.5, -5.2, -0.5);
	glVertex3f(-2.5, -5, -0.5);
	glEnd();

	//6.1
	glBegin(GL_QUADS);
	glVertex3f(-2.5, -5, 0.3);
	glVertex3f(-2.5, -5.2, 0.3);
	glVertex3f(-2.5, -5.2, 1);
	glVertex3f(-2.5, -5, 1);
	glEnd();
	glPopMatrix();

	//дырки(цылиндры)
	glColor3f(0.72, 0.52, 0.04);
	glPushMatrix();
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();     // —оздаем указатель на квадратичный объект ( Ќќ¬ќ≈ )
	gluQuadricNormals(quadratic, GLU_SMOOTH); // —оздаем плавные нормали ( Ќќ¬ќ≈ )
	glTranslated(1.6, -2, 1.55);
	gluDisk(quadratic, 0, 0.3, 40, 5);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0.4, -2.5, 1.55);
	gluDisk(quadratic, 0, 0.3, 40, 5);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-1.5, -2.3, 1.55);
	gluDisk(quadratic, 0, 0.3, 40, 5);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-1.8, 0, 1.55);
	gluDisk(quadratic, 0, 0.3, 40, 5);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-1.2, 2.4, 1.55);
	gluDisk(quadratic, 0, 0.3, 40, 5);
	glPopMatrix();
	glPushMatrix();
	glTranslated(1.6, 2.8, 1.55);
	gluDisk(quadratic, 0, 0.3, 40, 5);
	glPopMatrix();
	glPushMatrix();
	glTranslated(1.6, 0, 1.55);
	gluDisk(quadratic, 0, 0.3, 40, 5);
	glPopMatrix();

	glColor3f(0.72, 0.52, 0.04);
	glPushMatrix();
	glTranslated(1.6, -2, -1.55);
	gluDisk(quadratic, 0, 0.3, 40, 5);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0.4, -2.5, -1.55);
	gluDisk(quadratic, 0, 0.3, 40, 5);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-1.5, -2.3, -1.55);
	gluDisk(quadratic, 0, 0.3, 40, 5);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-1.8, 0, -1.55);
	gluDisk(quadratic, 0, 0.3, 40, 5);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-1.2, 2.4, -1.55);
	gluDisk(quadratic, 0, 0.3, 40, 5);
	glPopMatrix();
	glPushMatrix();
	glTranslated(1.6, 2.8, -1.55);
	gluDisk(quadratic, 0, 0.3, 40, 5);
	glPopMatrix();
	glPushMatrix();
	glTranslated(1.6, 0, -1.55);
	gluDisk(quadratic, 0, 0.3, 40, 5);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 0, -1.55);
	gluDisk(quadratic, 0, 0.3, 40, 5);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0.5, 1.4, -1.55);
	gluDisk(quadratic, 0, 0.3, 40, 5);
	glPopMatrix();


	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glTranslated(-1, 1.4, -2.55);
	gluDisk(quadratic, 0, 0.3, 40, 5);
	glPopMatrix();
	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glTranslated(1.1, 0, -2.55);
	gluDisk(quadratic, 0, 0.3, 40, 5);
	glPopMatrix();
	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glTranslated(0, -1.5, -2.55);
	gluDisk(quadratic, 0, 0.3, 40, 5);
	glPopMatrix();
	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glTranslated(0.4, 2.2, -2.55);
	gluDisk(quadratic, 0, 0.3, 40, 5);
	glPopMatrix();


	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glTranslated(-1, 1.4, 2.55);
	gluDisk(quadratic, 0, 0.3, 40, 5);
	glPopMatrix();
	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glTranslated(1.1, 0, 2.55);
	gluDisk(quadratic, 0, 0.3, 40, 5);
	glPopMatrix();
	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glTranslated(0, -1.5, 2.55);
	gluDisk(quadratic, 0, 0.3, 40, 5);
	glPopMatrix();
	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glTranslated(0.4, 2.2, 2.55);
	gluDisk(quadratic, 0, 0.3, 40, 5);
	glPopMatrix();


	glPushMatrix();
	glRotated(90, 1, 0, 0);
	glTranslated(0, 1, -3.3);
	gluDisk(quadratic, 0, 0.3, 40, 5);
	glPopMatrix();
	glPushMatrix();
	glRotated(90, 1, 0, 0);
	glTranslated(-2, 0, -3.3);
	gluDisk(quadratic, 0, 0.3, 40, 5);
	glPopMatrix();
	glPushMatrix();
	glRotated(90, 1, 0, 0);
	glTranslated(1.5, -1, -3.3);
	gluDisk(quadratic, 0, 0.3, 40, 5);
	glPopMatrix();
	glPushMatrix();
	glRotated(90, 1, 0, 0);
	glTranslated(-0.4, -0.4, -3.3);
	gluDisk(quadratic, 0, 0.3, 40, 5);
	glPopMatrix();
	glPushMatrix();
	glRotated(90, 1, 0, 0);
	glTranslated(1.2, 0.4, -3.3);
	gluDisk(quadratic, 0, 0.3, 40, 5);
	glPopMatrix();


	glPopMatrix();


}
