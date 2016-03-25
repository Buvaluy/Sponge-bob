#include <glut.h>
#include <windows.h>
#include <string>
#include <string.h>



void draw_bob(bool near_stone, float y_jump, int time_jump);
void keyboard_handler(unsigned char key, int x, int y);
void mouse_handler(int x, int y);
void display();
void anim(bool &damage_on_stone, bool &dont_paint, bool &manual_control, bool &near_stone, bool &testm, bool &stonem, bool &plusorminus, bool fly_dontstep, double &angel_food, float &z1_p, float &z2_p, float z3_stone[], float &y_jump, int &time_jump, int forse_speed,int &score);
void creat_stone(float z3_stone[]);
void resize_window(int width, int height);
DWORD WINAPI play_music(LPVOID lpParam);
DWORD WINAPI play_music2(LPVOID lpParam);
DWORD WINAPI play_damage(LPVOID lpParam);
void Timer(int value);
void autojump(bool &near_stone, bool &fly_dontstep, bool &stonem, int &time_jump, int &forse_speed, float z3_stone[]);
void changeangelfootsandhands(bool &testm, bool &plusormines, bool fly_dontstep, double &angel_food, int forse_speed);
void stoneandroad(bool &testm,bool &stonem, float &z1_p, float &z2_p, float z3_stone[], int forse_speed, GLUquadricObj *quadratic);
void rotatefoodandhands(bool testm, bool near_stone, int forse_speed, float &y_jump, int time_jump, double angel_food, GLUquadricObj *quadratic);
void search_pos_music(bool stonem, float z3_stone[], int forse_speed);

static char str[10];

static int alpha = 0;
static int beta = 0;
static int gama = 0;
static int lookat = 10;
static int looksize = 20;
static int updown = -30;
static int leftright = -60;

static int score = 50;


static double angel_food = 0;
static bool plusormines = false;

static bool testm = false;
static bool stonem = false;

static float z1_p = -1, z2_p = 4;

static float z3_stone[200];

static float y_jump = 0.1;//изменяеться положение фигуры вверх и вниз
static int time_jump = 0;//типо таймер для прыжка, прижок длиться 72
static bool near_stone = false; //камень перед нами? да\нет

static int forse_speed = 3;

static bool fly_dontstep = false;
static bool jump_theards = false;
static bool manual_control = false;
static bool damage_on_stone = false;
static bool dont_paint = false;