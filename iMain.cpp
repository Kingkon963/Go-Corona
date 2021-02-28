#define _CRT_SECURE_NO_WARNINGS //WARNING!!!! DO NOT CHANGE THIS. CHANGING THIS WILL DESTROY YOUR GAME.
//bypassing security warning of vs 2013
#include "iGraphics.h"
#include <iostream>
#include <array>
#include <string>
#include<windows.h>
using namespace std;
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

#define windowWidth 1020
#define windowHeight 720
#define GH 1 ///////// for high score////////////
bool skip = false;
bool newG = false;
bool gameOver = false;
bool inDis = true;
bool takeInput = true; //logic for input user name
//for high score
int  point = 0;
int flag = 0;
int movec = (windowWidth / 2) - 85;
char* hoverImg[5] = { "images//help1.bmp", "images//hover4.bmp", "images//hover3.bmp", "images//hover2.bmp", "images//hover1.bmp" };

int index0 = 0;
int in = 0;
char userName[1000];

char s[100];

int x;
int y;
int jmp = 0;
int r = 255;
int g = 255;
int b = 255;
int ix = 0, iy = 0;

int mpx, mpy, count = 0;

string currentPage = "homePage";

char* menuTitles2[5] = { "help", "credits", "highScores", "settings", "newGame" };
char* menuTitles[5] = { "images//help.bmp", "images//menu4.bmp", "images//menu3.bmp", "images//menu2.bmp", "images//menu1.bmp" };
int totalMenuItems = 5;

char person_run[2][20] = { "images//b14.bmp", "images//b17.bmp" };
int runningIndex = 0;

char roads[4][20] =
{
	"images//a.bmp",
	"images//b.bmp",
	"images//c.bmp",
	"images//d.bmp"
};
int roadIndex = 3;
bool musicOn = true;
//int vx = 442, vy = 0;
int charecterX = (windowWidth / 2) - 80;
int charecterY = 10;
bool jump = false;
int jumpY = 10;
int max_jumpY = 100;

void setHigh(char*, long int);
void showhigh();
void show(int);
int getPercentage(int, int);
void background();
void homepage();
void lifeIndicator(int);
void run();
void moveRoad();
char *convertInt(int);
int lineCount();
void rankScore();



struct MenuItem{
	char *title;
	char *backgroundImg;
	char *hover; //to store hover effect image 
	int x, y;
	int width = 400;
	int height = 50;
	bool onHoverState = false, firstEntry = true;

	MenuItem(){}
	MenuItem(int x, int y, char *title) : x(x), y(y), title(title), backgroundImg(backgroundImg){

	}

	bool isInsideThis(int mx, int my){ //true if cursor is inside of the MenuItem
		return (mx >= x && mx <= (x + width)) && (my >= y && my <= (y + height));
	}
	void display(){
		iShowBMP2(x + getPercentage(width, 0), y + getPercentage(height, 40), backgroundImg, 0);
		if (this->isInsideThis(mpx, mpy))
			onHoverState = true;
		else
			onHoverState = false;

		if (onHoverState){
			iSetColor(0, 0, 0);
			//	iFilledRectangle(x, y, width, height);
			iShowBMP2(x + getPercentage(width, -7), y + getPercentage(height, 40), "images//arr.bmp", 0);
			iShowBMP2(x + getPercentage(width, 0), y + getPercentage(height, 40), hover, 0);
			iSetColor(255, 255, 255);
			if (firstEntry){
				PlaySound("Sounds\\btn_hover.wav", NULL, SND_ASYNC);
				firstEntry = false;
			}
		}
		else{
			//iRectangle(x, y, width, height);
			firstEntry = true;
		}

		//iText(x + getPercentage(width, 40), y + getPercentage(height, 40), title, GLUT_BITMAP_HELVETICA_18);

	}

	void cliked(){
		currentPage = this->title;
	}
};

struct Menu{
	int x = 0, y = 0;
	int dy = 70, totalItems;
	int width, height;
	MenuItem *items;

	Menu(int x, int y, int width, int height, MenuItem items[], int totalItems) :x(x), y(y), width(width), height(height), totalItems(totalItems){
		this->items = items;
	}

	void display(){
		for (int i = 0; i < totalItems; i++){
			items[i].x = this->x;
			items[i].y = this->y;
			items[i].width = this->width;
			items[i].height = this->height;
			items[i].title = menuTitles2[i];
			items[i].hover = hoverImg[i];//hover state image (Muhaiminul kabir)
			items[i].backgroundImg = menuTitles[i];
			items[i].display();

			y += dy;
		}
		y -= dy*totalItems; // Resetting y
	}
};

struct LeftTrack{
	double x = 442;

	double getX(){
		return abs(x);
	}
	double getY(){
		return abs(((187 * x) / 101) - (30740 / 101));
	}

	void speed(double dx){
		x -= dx;
		if (x <= 240) x = 442;
	}
};

struct MiddleTrack{
	double x = 512;

	double getX(){
		return abs(x);
	}

	double getY(){
		return abs((191 * x) - 97268);
	}

	void speed(double dx){
		x -= dx;
		if (x <= 510) x = 512;
	}
};
struct RightTrack{
	double x = 581;

	double getX(){
		return abs(x);
	}

	double getY(){
		return abs(((373 * x) / (-181)) + (216713 / 181) + 515);
	}

	void speed(double dx){
		x += dx;
		if (x >= 762) x = 581;
	}
};

struct Virus{
	string type;
};

struct playerData{
	char pl[1000];
	int scr;
};


MenuItem menuItems[5];
Menu menu(300, 200, 400, 50, menuItems, totalMenuItems);
LeftTrack lt;
MiddleTrack mt;
RightTrack rt;

char *convertInt(int a){
	int h;
    int f = a;
    int c = 0;
    int *s;
    c = (a == 0) ? 1 : (log10(a) + 1);
    s = (int*)malloc(c);
    for (int i = 0; i<c; i++){
        h = f % 10;
        f = f / 10;
        s[i] = h;
    }
    int*t;
    t = (int*)malloc(c);
    for (int i = 0; i< c; i++){
        t[i] = s[(c - 1) - i];


    }
    char *p;
    p = (char*)malloc(c);
    for (int i = 0; i< c; i++){
        p[i] = (char)(t[i] + 48);
    }

    return p;

}

int lineCount(){
	FILE *f = fopen("HIGH_SCORE_DR_IMMUNITY.txt", "r");
	char us[1000];
	int g;
	int count = 0;
	for (; !feof(f);) {
		fscanf(f, "%s %d", us, &g);
		count++;
		if (feof(f)) {
			break;
		}
	}
	return count;
}
void rankScore(){
	int k = lineCount();
	struct playerData *x;
	x = (struct playerData *)malloc((k)* sizeof(struct playerData));
	FILE *a = fopen("HIGH_SCORE_DR_IMMUNITY.txt", "r+");

	for (int i = 0; i<k; i++) {
		fscanf(a, "%s %d", x[i].pl, &x[i].scr);
	}
	fclose(a);
	char z[1000];
	for (int i = 0; i<k; i++) {
		for (int j = i + 1; j < k; j++) {
			if (x[i].scr < x[j].scr) {
				int temp = x[i].scr;
				x[i].scr = x[j].scr;
				x[j].scr = temp;
				strcpy(z, x[i].pl);
				strcpy(x[i].pl, x[j].pl);
				strcpy(x[j].pl, z);
			}
		}
	}
	FILE *n = fopen("HIGH_SCORE_DR_IMMUNITY.txt", "w+");


	for (int i = 0; i < k - 1; i++) {
		fprintf(n, "%s\t", x[i].pl);
		fprintf(n, "%d\n", x[i].scr);
	}
	free(x);
	fclose(n);
}

void setHigh(char* player, long int scr) {
	int u;
	long int y;
	char c[1000];
	int i;
	FILE *a;
	FILE *g;
	struct playerData plr;
	strcpy(plr.pl, player);
	plr.scr = scr;

	bool newFile = false;
	a = fopen("HIGH_SCORE_DR_IMMUNITY.txt", "r");
	if (a == NULL) {

		a = fopen("HIGH_SCORE_DR_IMMUNITY.txt", "w");
		newFile = true;
		fclose(a);
	}
	else {
		a = fopen("HIGH_SCORE_DR_IMMUNITY.txt", "a");
		fclose(a);
	}
	if (newFile == false && gameOver == true){
		g = fopen("HIGH_SCORE_DR_IMMUNITY.txt", "a+");
		fprintf(g, " %s %d \n", plr.pl, plr.scr);

		fclose(g);

	}
	else if (newFile == true && gameOver == true) {
		struct playerData f[10];
		g = fopen("HIGH_SCORE_DR_IMMUNITY.txt", "w+");
		fprintf(g, " %s %d \n", plr.pl, plr.scr);
		for (i = 0; i < 10; i++){
			fprintf(g, " %s %d \n", "Unknown", 0);
		}
		newFile = false;
		fclose(g);
	}
	rankScore();
}
void showHigh(){
	FILE *a;
	fopen_s(&a, "HIGH_SCORE_DR_IMMUNITY.txt", "r");
	if (a == NULL){
		iSetColor(255, 0, 0);
		iText(350, 500, "SHAME FOR HUMANS", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255, 255, 255);
		iText(220, 330, "Still no one has the courage to fight CORONA VIRUS", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else{
		iText(300, 500, "Player", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(600, 500, "Score", GLUT_BITMAP_TIMES_ROMAN_24);
		int count = 0;
		int i = 0;
		int scr;
		char pl[1000];
		char *p;
		char *v;
		if (a != NULL) {
			while (fscanf(a, "%s %d", pl, &scr) != EOF) {
				if (count < 10) {

					iText(300, 450 - i, pl, GLUT_BITMAP_TIMES_ROMAN_24);
					p = convertInt(scr);
					iText(600, 450 - i, p, GLUT_BITMAP_TIMES_ROMAN_24);

				}
				else{

					fclose(a);
					break;

				}
				count++;
				i += 40;
				v = convertInt(count);
				iText(250, 490 - i, v, GLUT_BITMAP_TIMES_ROMAN_24);


			}
			fclose(a);
			free(p);
			free(v);
		}
	}
}
void show(int a)
{
	int h;
	int f = a;
	int c = 0;
	int *s;
	c = (a == 0) ? 1 : (log10(a) + 1);
	s = (int*)malloc(c);
	for (int i = 0; i<c; i++){
		h = f % 10;
		f = f / 10;
		s[i] = h;

	}
	int*t;
	t = (int*)malloc(c);
	for (int i = 0; i< c; i++){
		t[i] = s[(c - 1) - i];
	}
	char p[100];
	for (int i = 0; i< c; i++){
		p[i] = (char)(t[i] + 48);
		if (p[i] == '0'){
			iShowBMP2((400 + (i * 25)), 670, "images//0.bmp", 0);
		}
		else if (p[i] == '1'){
			iShowBMP2((400 + (i * 25)), 670, "images//1.bmp", 0);
		}
		else if (p[i] == '2'){
			iShowBMP2((400 + (i * 25)), 670, "images//2.bmp", 0);
		}
		else if (p[i] == '3'){
			iShowBMP2((400 + (i * 25)), 670, "images//3.bmp", 0);
		}
		else if (p[i] == '4'){
			iShowBMP2((400 + (i * 25)), 670, "images//4.bmp", 0);
		}
		else if (p[i] == '5'){
			iShowBMP2((400 + (i * 25)), 670, "images//5.bmp", 0);
		}
		else if (p[i] == '6'){
			iShowBMP2((400 + (i * 25)), 670, "images//6.bmp", 0);
		}
		else if (p[i] == '7'){
			iShowBMP2((400 + (i * 25)), 670, "images//7.bmp", 0);
		}
		else if (p[i] == '8'){
			iShowBMP2((400 + (i * 25)), 670, "images//8.bmp", 0);
		}
		else if (p[i] == '9'){
			iShowBMP2((400 + (i * 25)), 670, "images//9.bmp", 0);
		}
	}
	iSetColor(0, 0, 0);
	//iText(510,700,p,GLUT_BITMAP_TIMES_ROMAN_24);
	//iText(700, 700, "m", GLUT_BITMAP_TIMES_ROMAN_24);
	iShowBMP2(350, 670, "images//pill_scr.bmp", 0);
}
int getPercentage(int num, int percent){
	return (int)((num*percent) / 100);
}
void background()
{
	iFilledRectangle(0, 0, windowWidth, windowHeight);

}
void homePage(){

	menu.display();

}
void lifeIndicator(int life){
	int dx = 50, i, j;
	if (life >= 0 && life <= 3){
		for (i = 0; i < life; i++){
			iShowBMP2(windowWidth - dx, windowHeight - 50, "images//heart_filled.bmp", 0);
			dx += 60;
		}
		for (j = 3 - i; j; j--){
			iShowBMP2(windowWidth - dx, windowHeight - 50, "images//heart.bmp", 0);
			dx += 60;
		}
	}
};

void run(){
	runningIndex++;
	if (runningIndex > 1) runningIndex = 0;
}

void moveRoad(){
	roadIndex--;
	if (roadIndex <= 0) roadIndex = 3;
}
void newGame(){
	int life = 3;

	iShowBMP2(0, 0, roads[roadIndex], -1);


	//if (musicOn){
	//	PlaySound("Sounds\\normal.wav", NULL, SND_LOOP);
	//	musicOn = false;
	//}
	iText(10, windowHeight - 30, userName, GLUT_BITMAP_TIMES_ROMAN_24);

	//iDelayMS(10);

	if (!jump)
	{
		iShowBMP2(charecterX, charecterY, person_run[runningIndex], 0);
	}


	if (jump)
	{

		iShowBMP2(charecterX, charecterY + jumpY, "images//b14.bmp", 0);
		jumpY += 20;
		//iDelayMS(60);
		if (jumpY > 80)
		{
			jump = false;
			jumpY = 0;
		}



	}

	//iLine(240, 140, 442, 514);
	point++;// SHOULD BE CHANGED
	show(point);// Showing int on screen

	//vy = ((187 * vx) / 101) - (30740 / 101);

	//cout << lt.getY() << endl;
	iShowBMP2(lt.getX(), lt.getY(), "images//virus.bmp", 255);
	lt.speed(1);

	iShowBMP2(mt.getX() - 10, mt.getY() - 7, "images//virus.bmp", 255);
	mt.speed(.012);

	cout << rt.getY() << endl;
	iShowBMP2(rt.getX() - 10, rt.getY() - 7, "images//virus.bmp", 255);
	rt.speed(1);

	iShowBMP2(windowWidth - 50, windowHeight - 50, "images//heart_filled.bmp", 0);
	iShowBMP2(windowWidth - 110, windowHeight - 50, "images//heart.bmp", 0);
	if (gameOver){
		setHigh(userName, point);//now for testing this function is taking score after pressing 'l',, it will take score when game over
		gameOver = false;
	}

}
void userPage(){


	iShowBMP2(200, 500, "images//12.bmp", 0);

	iText(180, 360, ">>", GLUT_BITMAP_TIMES_ROMAN_24);
	iShowBMP2(200, 100, "images//13.bmp", 0);
	iSetColor(255, 0, 0);
	iText(250, 360, userName, GLUT_BITMAP_TIMES_ROMAN_24);


}
void highScores(){
	iShowBMP2(350, 600, "images//high.bmp", 0);

	showHigh();// showing high score of all time
	iShowBMP2(10, 10, "images//home.bmp", 0);
}
void settings(){
	//iShowBMP2(370, 600, "images//22.bmp", 0);
	//iShowBMP2(10, 10, "images//home.bmp", 0);
}
void helpPage(){
	/*
	write insructions, rules here.
	*/
	iShowBMP2(10, 10, "images//home.bmp", 0);
}
void creditPage(){
	iShowBMP2(400, 600, "images//credits.bmp", 0);
	iShowBMP2(10, 10, "images//home.bmp", 0);
	//ImgButton home(10, windowHeight - 60, "images//home.bmp", "homePage");
	//home.display();
}
//bool user = true;
void iDraw()
{
	iClear();

	iSetColor(0, 48, 73);
	background();

	iSetColor(r, g, b);

	iText(0, 0, &currentPage[0]);

	if (currentPage == "homePage")
		homePage();
	else if (currentPage == "newGame"){

		iSetColor(255, 255, 255);

		if (takeInput){
			currentPage = "userPage";
		}
		else{
			if (newG || 1){
				newGame();
			}
		}
	}
	else if (currentPage == "userPage"){
		userPage();
	}
	else if (currentPage == "credit"){
		creditPage();
	}
	else if (currentPage == "highScores"){
		highScores();
	}
	else if (currentPage == "settings"){
		settings();
	}
	else if (currentPage == "help"){
		helpPage();
	}
}





/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{

}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
	mpx = mx;
	mpy = my;
	cout << mpx << ' ' << mpy << endl;
}

void iMouse(int button, int state, int mx, int my)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		PlaySound("Sounds\\click.wav", NULL, SND_ASYNC);

		if (currentPage == "homePage"){
			for (int i = 0; i < totalMenuItems; i++){
				if (menuItems[i].isInsideThis(mx, my)){
					menuItems[i].cliked();
					break;
				}
			}
		}
		else if (currentPage == "Credits"){

		}
	}



	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key){

	if (currentPage == "userPage"){
		if (key != '\b'){
			userName[index0] = key;
			index0++;
			userName[index0] = '\0';

		}

		else{
			if (index0 <= 0){
				index0 = 0;
			}
			else{
				index0--;
			}
			userName[index0] = '\0';
		}


	}
	else if (currentPage == "newGame"){
		if (key == ' ')
		{
			if (!jump)
			{
				jump = true;


			}
		}

		if (key == 'l')
		{
			gameOver = true;//testing showHigh()
		}
	}


}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
	if (currentPage == "homePage"){

	}
	else if (currentPage == "userPage"){
		if (key == GLUT_KEY_INSERT){
			takeInput = false;
			newG = true;
			currentPage = "newGame";
		}
	}
	else if (currentPage == "newGame"){
		if (key == GLUT_KEY_RIGHT)
		{
			charecterX += 40;
			if (charecterX > 895)
				charecterX = 895;

		}
		if (key == GLUT_KEY_LEFT)
		{
			charecterX -= 40;
			if (charecterX < 80)
				charecterX = 80;

		}
		if (key == GLUT_KEY_UP){
			if (!jump)
				jump = true;
		}
	}


}


int main()
{
	int runTimer = iSetTimer(100, run);
	int roadTimer = iSetTimer(100, moveRoad);
	///srand((unsigned)time(NULL));
	iInitialize(windowWidth, windowHeight, "My Game");
	///updated see the documentations
	iStart();
	return 0;
}
