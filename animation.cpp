#include <D:/Program_Files/Projects/kurs2/semestr2/SP/openglhabra/openglhabra1/openglhabra1/for_all.h>

static int wait_damage;


void anim(bool &damage_on_stone,bool &dont_paint, bool &manual_control, bool &near_stone, bool &testm, bool &stonem, bool &plusormines, bool fly_dontstep, double &angel_food,
	float &z1_p, float &z2_p, float z3_stone[], float &y_jump, int &time_jump, int forse_speed, int &score){
	

	
	if (manual_control == false){//проверка на ручной контроль
		search_pos_music(stonem, z3_stone, forse_speed);
		autojump(near_stone, fly_dontstep, stonem, time_jump, forse_speed, z3_stone);
	}
	else{//если включен ручной контроль, то...
		if (damage_on_stone == false){
			for (int i = 0; i < 200; i++){
				if (z3_stone[i] < 0.3 && z3_stone[i] > 0.3 - 0.041*forse_speed){
					if (y_jump < 1.3){//если мы спотыкнулись об этот камень то
						score -= 5;
						damage_on_stone = true;
						testm = false;
					    wait_damage = 70;
						dont_paint = true;
						HANDLE th4;
						DWORD th_id4;
						th4 = CreateThread(NULL, 0, &play_damage, NULL, 0, &th_id4);
					}
				}
			}
		}
	}
	if (wait_damage > 0 && damage_on_stone==true && manual_control==true){//время простоя --...
		wait_damage--;
	}
	if (wait_damage == 1){//время простоя закончилось, пошли дальше
		testm = true;
		dont_paint = false;
		damage_on_stone = false;
	}
	if (wait_damage == 50){//в этот момент простоя переном=сим его вперед за камень
		z1_p -= 2.4;
		z2_p -= 2.4;
		for (int iii = 0; iii < 200; iii++){
			z3_stone[iii] -= 0.48;
		}
	}
	

	if (time_jump > 0){//это можно будет удалить, это для проверок было ****
		time_jump--;
		printf("%d", time_jump);
	}
	if (time_jump == 0){ //прыжок закончился, говорим что камней нету, стоим на земле
		near_stone = false;
		y_jump = 0.1; 
		fly_dontstep = false;
	}
	
	changeangelfootsandhands(testm, plusormines, fly_dontstep, angel_food, forse_speed);
	
	glPushMatrix();
	GLUquadricObj *quadratic;//нужен для цилиндра
	quadratic = gluNewQuadric();     // Создаем указатель на квадратичный объект ( НОВОЕ )
	gluQuadricNormals(quadratic, GLU_SMOOTH); // Создаем плавные нормали ( НОВОЕ )

	stoneandroad(testm, stonem, z1_p, z2_p, z3_stone, forse_speed, quadratic);
	if (dont_paint == false){
		rotatefoodandhands(testm, near_stone, forse_speed, y_jump, time_jump, angel_food, quadratic);
	}
	if (wait_damage == 60 || wait_damage == 40 || wait_damage == 20 || wait_damage == 10){//для изчезновения и появления
		dont_paint = false;
	}
	if (wait_damage == 50 || wait_damage == 30 || wait_damage == 10){
		dont_paint = true;
	}
	glPopMatrix();
}


void creat_stone(float z3_stone[]){
	int prevstone = 0;
	for (int i = 0,k=5; i < 200; i++,k+=15){
		z3_stone[i] = rand() % k + 20;
		if (prevstone > z3_stone[i] - 7){
			while (prevstone > z3_stone[i] - 7){
				z3_stone[i] = rand() % k + 25;
			}
		}
		prevstone = z3_stone[i];
	}
}


void autojump(bool &near_stone, bool &fly_dontstep, bool &stonem, int &time_jump, int &forse_speed, float z3_stone[]){
	for (int i = 0; i < 200; i++){//проверка есть ли камень перед нами
		if (z3_stone[i] < 1.2 && z3_stone[i] > -0.8 && stonem == true){
			near_stone = true;
			fly_dontstep = true;
			if (time_jump == 0){//проверка мы в полете илил нет, установим таймер прижка на 72
				time_jump = 72 / forse_speed;
				
			}
		}
	}
}


void changeangelfootsandhands(bool &testm, bool &plusormines, bool fly_dontstep, double &angel_food, int forse_speed){
	if (fly_dontstep == false){//пеняем угол для ног и рук...
		if (plusormines == false){
			if (angel_food < 11 && testm == true){
				angel_food += 0.6*forse_speed;
				printf("+");
			}
			if (angel_food >= 10.2){ plusormines = true; }
		}
		else{
			if (angel_food > -11 && testm == true){
				angel_food -= 0.6*forse_speed;
				printf("-");
			}
			if (angel_food <= -10.2){ plusormines = false; }
		}
		if (testm == false){ angel_food = 0; }//стом на месте, ноги не двигаем
	}
	else{
		if (angel_food<9 && angel_food>-9){//пеняем угол для ног и рук резко во время прижка...
			if (plusormines == false){
				if (angel_food < 10 && testm == true){
					angel_food += 1.2*forse_speed;
					printf("+");
				}
				if (angel_food >= 10.2){ plusormines = true; }
			}
			else{
				if (angel_food > -10 && testm == true){
					angel_food -= 1.2*forse_speed;
					printf("-");
				}
				if (angel_food <= -10.2){ plusormines = false; }
			}
		}
	}
}


void stoneandroad(bool &testm, bool &stonem, float &z1_p, float &z2_p, float z3_stone[], int forse_speed, GLUquadricObj *quadratic){
	//дорого
	glColor3f(0.73, 0.73, 0.73);
	glPushMatrix();
	glRotatef(0.8, 1, 0, 0);
	glBegin(GL_QUADS);
	glVertex3f(-200, -7.8, -200);
	glVertex3f(-200, -7.8, 200);
	glVertex3f(200, -7.8, 200);
	glVertex3f(200, -7.8, -200);
	glEnd();
	//полосы на дороге
	glColor3f(0.93, 0.93, 0.93);
	for (int i = 1; i < 40; i++){
		glBegin(GL_QUADS);
		glVertex3f(-1, -7.75, z1_p - 7 * i);
		glVertex3f(-1, -7.75, z2_p - 7 * i);
		glVertex3f(1, -7.75, z2_p - 7 * i);
		glVertex3f(1, -7.75, z1_p - 7 * i);
		glEnd();
	}
	for (int i = 0; i < 500; i++){
		glBegin(GL_QUADS);
		glVertex3f(-1, -7.75, z1_p + 7 * i);
		glVertex3f(-1, -7.75, z2_p + 7 * i);
		glVertex3f(1, -7.75, z2_p + 7 * i);
		glVertex3f(1, -7.75, z1_p + 7 * i);
		glEnd();
	}
	glPopMatrix();
	//камни(препядствия)
	if (stonem == true){
		for (int i = 0; i < 200; i++){
			glColor3f(0.93, 0.13, 0.13);
			glPushMatrix();
			glRotatef(-89.2, 1, 0, 0);
			glTranslated(-2, z3_stone[i] * -5, -7.7);
			gluCylinder(quadratic, 0.3, 0.3, 1.3, 10, 10);
			glPopMatrix();

			glPushMatrix();
			glRotatef(-89.2, 1, 0, 0);
			glTranslated(2, z3_stone[i] * -5, -7.7);
			gluCylinder(quadratic, 0.3, 0.3, 1.3, 10, 10);
			glPopMatrix();

			glColor3f(0.83, 0.83, 0.83);
			glPushMatrix();
			glRotatef(0.8, 1, 0, 0);
			glRotatef(-90, 0, 1, 0);
			glTranslated(z3_stone[i] * 5, -6.5, -2);
			gluCylinder(quadratic, 0.3, 0.3, 4, 10, 10);
			glPopMatrix();
			if (testm == true){
				z3_stone[i] -= 0.04*forse_speed;
			}
		}
	}

	if (testm == true){
		z1_p -= 0.2*forse_speed;
		z2_p -= 0.2*forse_speed;
	}
}


void rotatefoodandhands(bool testm, bool near_stone, int forse_speed, float &y_jump, int time_jump, double angel_food,GLUquadricObj *quadratic ){
	glRotated(angel_food, 1, 0, 0);

	//прижок рук и ног
	if (near_stone == true){
		glTranslated(0, y_jump, 0);
		if (time_jump > 36 / forse_speed){ y_jump += 0.07*forse_speed; }
		else { y_jump -= 0.07*forse_speed; }
		printf("DA/////");
	}

	//(правая)рука
	glColor3f(0.8, 0.8, 0.01);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslated(2.65, 0, 1.55);
	gluCylinder(quadratic, 0.2, 0.2, 3.5, 20, 10);
	glPopMatrix();
	//Ноги (левая)
	glColor3f(0.8, 0.8, 0.01);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslated(-1.2, 0, 5.55);
	gluCylinder(quadratic, 0.2, 0.2, 2, 20, 10);
	glPopMatrix();
	//ботинки(левый)
	glColor3f(0, 0, 0);
	glPushMatrix();
	glScalef(1, 1, 1.6);
	glTranslated(-1.2, -7.5, 0.1);
	glutSolidCube(0.7);
	glPopMatrix();
	if (testm == true){
		glRotated(-angel_food * 2, 1, 0, 0);
	}
	//руки(левая)
	glColor3f(0.8, 0.8, 0.01);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslated(-2.5, 0, 1.55);
	gluCylinder(quadratic, 0.2, 0.2, 3.5, 20, 10);
	glPopMatrix();
	//(правая)nogaa?
	glColor3f(0.8, 0.8, 0.01);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslated(1.2, 0, 5.55);
	gluCylinder(quadratic, 0.2, 0.2, 2, 20, 10);
	glPopMatrix();
	//(праввый)botinok?
	glColor3f(0, 0, 0);
	glPushMatrix();
	glScalef(1, 1, 1.6);
	glTranslated(1.2, -7.5, 0.1);
	glutSolidCube(0.7);
	glPopMatrix();
}


void search_pos_music(bool stonem,float z3_stone[],int forse_speed){
	for (int i = 0; i < 200; i++){//проверка есть ли камень перед нами
		if (z3_stone[i] < 1.1 && z3_stone[i] > 1.1 - 0.04*forse_speed && stonem == true && forse_speed<7 && forse_speed>=3){
			HANDLE th1;
			DWORD th_id1;
			th1 = CreateThread(NULL, 0, &play_music, NULL, 0, &th_id1);
		}
	}
}

