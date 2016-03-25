#include <D:/Program_Files/Projects/kurs2/semestr2/SP/openglhabra/openglhabra1/openglhabra1/for_all.h>


void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.1, 0.19, 0.1);
	glPushMatrix();
	glOrtho(-looksize, looksize, -looksize, looksize, -80, 80);
	gluLookAt(-4, 4, lookat, 0, 0, 0, 0, 1, 0); 
	glViewport(leftright, updown, 500, 500);
	glRotated(alpha, 0, 1, 0);
	glRotated(beta, -1, 0, 0);
	glRotated(gama, 0, 0, 1);
	if (dont_paint == false){
		draw_bob(near_stone, y_jump, time_jump);
	}
	if (score == 0){
		stonem = false;
		testm = false;
		manual_control = false;
	}
		anim(damage_on_stone,dont_paint,manual_control,near_stone,testm,stonem,plusormines,fly_dontstep,angel_food,z1_p,z2_p,z3_stone,y_jump,time_jump,forse_speed,score);
		if (score == 0){
			std::string s = "Game Over";
			char const *pchar = s.c_str();
			glutSetWindowTitle(pchar);
		}
		else{
			std::string s = "Speed: ";
			forse_speed -= 2;
			s += std::to_string(forse_speed);
			forse_speed += 2;
			s += "     Score: ";
			s += std::to_string(score);
			char const *pchar = s.c_str();
			glutSetWindowTitle(pchar);
		}
	glPopMatrix();
	glFlush();
}

int main(int argc, char **argv){
    HWND hwnd;
	float pos[4] = { 56, 113, 30, -10 };
	float dir[3] = { -1, -1, -1 };
	float ras[4] = { 0, 0, 0, 0};
	GLfloat mat_specular[] = { 1, 1, 0.2, 1 };
	glutInitWindowSize(400, 300);
	glutInit(&argc, argv);
	glutCreateWindow("");
    hwnd = FindWindow("GLUT", ""); //get its handle "GLUT" = class name "GLUT Test" = window caption
	SetWindowPos(hwnd, HWND_TOPMOST, 1000, NULL, NULL, NULL, SWP_NOREPOSITION | SWP_NOSIZE); //set the window always-on-top
	
	glutKeyboardFunc(&keyboard_handler);
	glutMotionFunc(&mouse_handler);
	glutReshapeFunc(&resize_window);
	glutDisplayFunc(&display);
	glutTimerFunc(20, &Timer, 0);

	glShadeModel(GL_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, pos);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dir);
	glMaterialf(GL_FRONT, GL_SHININESS, 50.0);
	glEnable(GL_LIGHTING); // здесь включается расчет освещения 
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE); // делаем так, чтобы освещались обе стороны полигона
	glEnable(GL_NORMALIZE); //делам нормали одинаковой величины во избежание артефактов

	glutMainLoop();
	return 1;
}

void Timer(int value){
	glutPostRedisplay(); 
	glutTimerFunc(50, Timer, 0);
}


void resize_window(int width, int height) {

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void mouse_handler(int x, int y){
	static int x0 = 0;
	static int y0 = -12345;

	if (y0 != -12345) {
		alpha += x - x0;
		beta += y - y0;
	}
	x0 = x;
	y0 = y;
	
}

void keyboard_handler(unsigned char key, int x, int y) {

	do {
		if (key == 'a'){
			if (beta < -10)break;
			alpha -= 4;
			break;
		}
		if (key == 'd'){
			if (beta < -10)break;
			alpha += 4;
			break;
		}
		if (key == 'w'){
			if (beta >= 12)break;
			beta += 4;
			break;
		}
		if (key == 's'){
			if (beta == -76)break;
			beta -= 4;
			break;
		}
		if (key == 'q'){
			if (gama == -60)break;
			gama -= 4;
			break;
		}
		if (key == 'e'){
			if (gama == 80)break;
			gama += 4;
			break;
		}
		/////////////////
		if (key == 'r'){
			looksize -= 1;
			break;
		}
		if (key == 'f'){
			looksize += 1;
			break;
		}
		//////////////
		if (key == 'g'){
			leftright += 2;
			break;
		}
		if (key == 'y'){
			updown -= 2;
			break;
		}
		if (key == 'h'){
			updown += 2;
			break;
		}
		if (key == 'j'){
			leftright -= 2;
			break;
		}
		////////////////
		if (key == '1'){
			if (stonem == false){
				stonem = true;
				testm = true;
				forse_speed = 4;
				creat_stone(z3_stone);
				manual_control = false;
				printf("true/n");
			}
			else{
				forse_speed = 3;
				testm = false;
				stonem = false;
				manual_control = false;
				printf("false/n");
			}
			break;
		}
		if (key == '2'){
			if (testm == false && stonem!=true){
				testm = true;
				forse_speed = 3;
				printf("true/n");
				stonem = false;
				manual_control = false;
			}
			else{
				testm = false;
				printf("false/n");
				stonem = false;
				manual_control = false;
			}
			break;
		}
		if (key == '3'){
			if (manual_control==false){
				score = 50;
				stonem = true;
				testm = true;
				manual_control = true;
				forse_speed = 5;
				creat_stone(z3_stone);
				printf("true/n");
			}
			else{
				forse_speed = 3;
				testm = false;
				stonem = false;
				manual_control = false;
				printf("false/n");
			}
			break;
		}
		if (key == '+'){
			if (forse_speed == 7)break;
			forse_speed += 1;
			break;
		}
		if (key == '-'){
			if (forse_speed == 3)break;
			forse_speed -= 1;
			break;
		}
		if (key == ' '){
			if (stonem == true && testm == true && manual_control == false)break;
			if (time_jump == 0 && damage_on_stone == false){
				fly_dontstep = true;
				near_stone = true;
				time_jump = 72 / forse_speed;
					if (jump_theards == false){
						jump_theards = true;
						HANDLE th1;
						DWORD th_id1;
						th1 = CreateThread(NULL, 0, &play_music, NULL, 0, &th_id1); 
						
					}
					else{
						HANDLE th3;
						DWORD th_id3;
						th3 = CreateThread(NULL, 0, &play_music2, NULL, 0, &th_id3);
					}
			}
			break;
		}

	} while (0);
}

char nyTb[] = "D:\\Program_Files\Projects\kurs2\semestr2\SP\openglhabra\openglhabra1\damage1.wav";// TAM, rDE "*.exe"
char nyTb1[] = "D:\\Program_Files\Projects\kurs2\semestr2\SP\openglhabra\openglhabra1\jump11.wav";// TAM, rDE "*.exe"

DWORD WINAPI play_music(LPVOID lpParam){
	PlaySound(nyTb, NULL, SND_FILENAME);
	return 0;
}

DWORD WINAPI play_music2(LPVOID lpParam){
	PlaySound(nyTb, NULL, SND_FILENAME);
	jump_theards = false;
	return 0;
}

DWORD WINAPI play_damage(LPVOID lpParam){
	PlaySound(nyTb1, NULL, SND_FILENAME);
	return 0;
}


