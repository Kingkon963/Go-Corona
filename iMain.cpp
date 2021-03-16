#define _CRT_SECURE_NO_WARNINGS //WARNING!!!! DO NOT CHANGE THIS. CHANGING THIS WILL DESTROY YOUR GAME.
//bypassing security warning of vs 2013
#include "iGraphics.h"
#include <iostream>
#include <array>
#include <string>
//#include <vector>
#include <list>
#include<windows.h>
#include <time.h>

using namespace std;
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

#define windowWidth 1020
#define windowHeight 720
#define Y1 264
#define Y2 416
#define GH 1 ///////// for high score////////////
bool skip = false;
bool newG = false;
bool gameOver = false;
bool inDis = true;
bool takeInput = true; //logic for input user name
bool takeScore = true;
bool showPassiveMousePosition = false;
//for high score
long int  point = 0;
int flag = 0;
int movec = (windowWidth / 2) - 85;
char* hoverImg[5] = { "images//help1.bmp", "images//hover4.bmp", "images//hover3.bmp", "images//hover2.bmp", "images//hover1.bmp" };
int randomTrack, prevTrack = -1;
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

// TIMER
int virusFactoryTimer;
int roadTimer;

string currentPage = "homePage";

//char person_run[2][20] = { "images//b14.bmp", "images//b17.bmp" };
int runningIndex = 0;

char roads[4][20] =
{
	"images//a.bmp",
	"images//b.bmp",
	"images//c.bmp",
	"images//d.bmp"
};

char *gameOverImg[3] = { "images//gameO5.bmp", "images//gameO2.bmp", "images//gameO1.bmp" };
char *musicState[2] = { "ON", "OFF" };
char *difficulityState[3] = { "LOW", "MEDIUM", "HIGH" };
char explosion[22][25] =
{
	"images//explosion1.png",
	"images//explosion1.png",
	"images//explosion2.png",
	"images//explosion2.png",
	"images//explosion3.png",
	"images//explosion3.png",
	"images//explosion4.png",
	"images//explosion4.png",
	"images//explosion5.png",
	"images//explosion5.png",
	"images//explosion6.png",
	"images//explosion6.png",
	"images//explosion7.png",
	"images//explosion7.png",
	"images//explosion8.png",
	"images//explosion8.png",
	"images//explosion9.png",
	"images//explosion9.png",
	"images//explosion10.png",
	"images//explosion10.png",
	"images//explosion11.png",
	"images//explosion11.png",
};


int life = 3;
int roadIndex = 3;
bool musicOn = true;
bool gameOverSound = false;
//int vx = 442, vy = 0;
int charecterX = (windowWidth / 2) - 80;
int charecterY = 10;
bool jump = false;
int jumpY = 10;
int max_jumpY = 100;
int scrollY = 0;
int universalScoreVar = 0;
double cloudY = 534;
int explosionIndex = 0;
bool isCollision = false;
double collisionX = 0;
double collisionY = 0;
int scrollSettingsY = 0;
int gameOverIndex = 0;
int virusImg, virusImg75, virusImg100;
int virusIndex = 0;

bool optionMusicOff = false;
bool optionMusicOn = true;
bool optionDifficulityHigh = false;
bool optionDifficulityLow = true;
bool optionDifficulityMedium = false;
int musicStateIndex = 0;
int difficulityStateIndex = 0;

//charecter images
int charecterImg[21];
string charecterImageAddress;


void setHigh(char*, long int);
void showHigh();

void show(long int ,int ,int );

int getPercentage(int, int);
void background();
void homePage();
void lifeIndicator(int);
void run();
void moveRoad();

void convertInt(char, long int);

int lineCount();
void rankScore();

void showExplosion();
void showCloud();
void collision();
void sun();
void loadImages();
void virusFactory();




struct playerData{
	char pl[1000];
	long int scr;
};



#include "Track.h";
#include "Virus.h";
#include "Menu.h";
#include "Navigation.h";

/***************************Function For SHowing Explosion********************/
void showExplosion()
{
	if (isCollision == true){
		int id = iLoadImage(explosion[explosionIndex++]);
		if (explosionIndex > 21)
		{
			explosionIndex = 0;
			isCollision = false;

		}
		iShowImage(collisionX, collisionY, 200, 200, id);
	}


}
/*******************Function For SHowing Clouds***************/
void showCloud()

{ 
	cloudY=cloudY+ 0.3;
	iShowBMP2(0, cloudY, "images//cloud1.bmp", 0);
	iShowBMP2(400, cloudY - 2, "images//cloud1.bmp", 0);
	iShowBMP2(800, cloudY + 10, "images//cloud1.bmp", 0);
	if (cloudY > 670)
		cloudY = 534;
  
  
}
/******************Function to detecet collision***************/
void collision()
{



/*	if ((lt.getX() + 60 > charecterX)&&(lt.getY() < charecterY + 180))
	{
		collisionX = lt.getX();
		collisionY = lt.getY();
		isCollision = true;

	}


	else if ((mt.getX() + 60 > charecterX) && (mt.getY() < charecterY + 180))
	{

		collisionX = mt.getX();
		collisionY = mt.getY();
		isCollision = true;
	}


	else if ((rt.getX() + 60) > charecterX&&(rt.getY() < charecterY + 180))
	{
		collisionX = rt.getX();
		collisionY = rt.getY();
		isCollision = true;

	}

	*/


}
void convertInt(char str[], long int a) {
	long int i, rem, count = 0, f;
	f = a;
	while (f != 0) {
		count++;
		f /= 10;
	}
	for (i = 0; i < count; i++) {
		rem = a % 10;
		a = a / 10;
		str[count - (i + 1)] = rem + '0';
	}
	str[count] = '\0';
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
		fprintf(n, "%ld\n", x[i].scr);
	}
	free(x);
	fclose(n);
}
void loadImages(){
	virusImg = iLoadImage("images/virus.png");
	virusImg75 = iLoadImage("images/virus75.png");
	virusImg100 = iLoadImage("images/virus100.png");

	for (int i = 0; i < 21; i++){
		charecterImageAddress = "images/charecter/";
		charecterImageAddress += to_string(i+1);
		charecterImageAddress += ".png";
		//cout << charecterImageAddress << endl;
		charecterImg[i] = iLoadImage((char *)charecterImageAddress.c_str());
	}
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
	if (newFile == false && takeScore == true){
		g = fopen("HIGH_SCORE_DR_IMMUNITY.txt", "a+");
		fprintf(g, " %s %ld \n", plr.pl, plr.scr);

		fclose(g);

	}
	else if (newFile == true && takeScore == true) {
		struct playerData f[10];
		g = fopen("HIGH_SCORE_DR_IMMUNITY.txt", "w+");
		fprintf(g, " %s %ld \n", plr.pl, plr.scr);
		for (i = 0; i < 10; i++){
			fprintf(g, " %s %ld \n", "Unknown", 0);
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
		char p[1000];
		char v[20];
		if (a != NULL) {
			while (fscanf(a, "%s %ld", pl, &scr) != EOF) {
				if (count < 10) {

					iText(300, 450 - i, pl, GLUT_BITMAP_TIMES_ROMAN_24);
					convertInt(p, scr);
					iText(600, 450 - i, p, GLUT_BITMAP_TIMES_ROMAN_24);

				}
				else{

					fclose(a);
					break;

				}
				count++;
				i += 40;
				convertInt(v, count);
				iText(250, 490 - i, v, GLUT_BITMAP_TIMES_ROMAN_24);


			}
			fclose(a);

		}
	}
}
void show(long int a, int x, int y)
{
	char p[1000];
	long int i, rem, count = 0, f;
	f = a;
	while (f != 0) {
		count++;
		f /= 10;
	}
	for (i = 0; i < count; i++) {
		rem = a % 10;
		a = a / 10;
		p[count - (i + 1)] = rem + '0';
	}
	p[count] = '\0';
	for (int i = 0; i< count; i++){
		if (p[i] == '0'){
			iShowBMP2((x + (i * 25)), y, "images//0.bmp", 0);
		}
		else if (p[i] == '1'){
			iShowBMP2((x + (i * 25)), y, "images//1.bmp", 0);
		}
		else if (p[i] == '2'){
			iShowBMP2((x + (i * 25)), y, "images//2.bmp", 0);
		}
		else if (p[i] == '3'){
			iShowBMP2((x + (i * 25)), y, "images//3.bmp", 0);
		}
		else if (p[i] == '4'){
			iShowBMP2((x + (i * 25)), y, "images//4.bmp", 0);
		}
		else if (p[i] == '5'){
			iShowBMP2((x + (i * 25)), y, "images//5.bmp", 0);
		}
		else if (p[i] == '6'){
			iShowBMP2((x + (i * 25)), y, "images//6.bmp", 0);
		}
		else if (p[i] == '7'){
			iShowBMP2((x + (i * 25)), y, "images//7.bmp", 0);
		}
		else if (p[i] == '8'){
			iShowBMP2((x + (i * 25)), y, "images//8.bmp", 0);
		}
		else if (p[i] == '9'){
			iShowBMP2((x + (i * 25)), y, "images//9.bmp", 0);
		}
	}

}

int getPercentage(int num, int percent){
	return (int)((num*percent) / 100);
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
}

void run(){
	runningIndex++;
	if (runningIndex >= 20) runningIndex = 0;
}

void moveRoad(){
	roadIndex--;
	if (roadIndex <= 0) roadIndex = 3;

}


void sun(){
	iSetColor(247, 127, 0);
	iFilledCircle(161, 527, 50, 100);

}
void virusFactory(){
	int randomTrack = rand() % 3;
	while (randomTrack == prevTrack) randomTrack = rand() % 3;

	switch (randomTrack){
	case 0:
		virus.track = lt;
		virus.speed = 1.5;
		prevTrack = 0;
		break;
	case 1:
		virus.track = mt;
		virus.speed = .3;
		prevTrack = 1;
		break;
	case 2:
		virus.track = rt;
		virus.speed = 1;
		prevTrack = 2;
		break;
	default:
		cout << "Error in generating randomTrack" << endl;
	}

	cout << virus.hide << endl;
	activeViruses.push_back(virus);

	if (activeViruses.size() == 10) {
		activeViruses.pop_front();
	}


}



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
			if (newG){
				newGame();
			}
		}
	}
	else if (currentPage == "userPage"){
		userPage();
	}
	else if (currentPage == "credits"){
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
	else if (currentPage == "gameOverPage"){
		gameOverPage();
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
	if (showPassiveMousePosition)
		cout << mpx << ' ' << mpy << endl;
}

void iMouse(int button, int state, int mx, int my)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
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
			else if (currentPage != "newGame" || currentPage != "homePage"){
				if (mx < 100 && my < 100){
					iShowBMP2(mpx, mpy, "images//home_black.bmp", 255);
					currentPage = "homePage";
					scrollY = 0;
					scrollSettingsY = 0;
				}
			}
		}



		if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		{
		}
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

		else if (key == '\b'){
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
			gameOver = true;

		}
	}
	else if (currentPage == "gameOverPage"){
		if (key){
			currentPage = "homePage";
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
			charecterX += 285;
			if (charecterX > 720)
				charecterX = 720;

		}
		if (key == GLUT_KEY_LEFT)
		{
			charecterX -= 285;
			if (charecterX < 150)
				charecterX = 150;

		}
		if (key == GLUT_KEY_UP){
			if (!jump)
				jump = true;
		}
	}

	else if (currentPage == "help"){
		if (key == GLUT_KEY_UP){
			scrollY -= 25;
		}
		if (key == GLUT_KEY_DOWN){
			scrollY += 25;
		}
	}
	if (currentPage == "settings"){
		if (key == GLUT_KEY_UP){
			scrollSettingsY -= 100;
			if (scrollSettingsY < 0){
				scrollSettingsY = 100;
			}

		}
		else if (key == GLUT_KEY_DOWN){
			scrollSettingsY += 100;
			if (scrollSettingsY > 100){
				scrollSettingsY = 0;
			}
		}
		else if (key == GLUT_KEY_RIGHT && scrollSettingsY == 0){
			if (optionMusicOn){
				optionMusicOff = true;
				optionMusicOn = false;
			}
			else if (optionMusicOff){
				optionMusicOff = false;
				optionMusicOn = true;
			}
		}
		else if (key == GLUT_KEY_LEFT && scrollSettingsY == 0){
			if (optionMusicOn){
				optionMusicOff = true;
				optionMusicOn = false;
			}
			else if (optionMusicOff){
				optionMusicOff = false;
				optionMusicOn = true;
			}
		}
		if (key == GLUT_KEY_RIGHT && scrollSettingsY == 100){

			if (optionDifficulityLow){
				optionDifficulityLow = false;
				optionDifficulityMedium = true;
				optionDifficulityHigh = false;
			}
			else if (optionDifficulityMedium){
				optionDifficulityLow = false;
				optionDifficulityMedium = false;
				optionDifficulityHigh = true;
			}
			else if (optionDifficulityHigh){
				optionDifficulityLow = true;
				optionDifficulityMedium = false;
				optionDifficulityHigh = false;
			}
		}
		if (key == GLUT_KEY_LEFT && scrollSettingsY == 100){
			if (optionDifficulityMedium){
				optionDifficulityLow = true;
				optionDifficulityMedium = false;
				optionDifficulityHigh = false;
			}
			else if (optionDifficulityLow){
				optionDifficulityLow = false;
				optionDifficulityMedium = false;
				optionDifficulityHigh = true;
			}
			else if (optionDifficulityHigh){
				optionDifficulityLow = false;
				optionDifficulityMedium = true;
				optionDifficulityHigh = false;
			}
		}

	}

	if (currentPage != "homePage"){
		if (key == GLUT_KEY_END){
			currentPage = "homePage";
		}
	}


}


int main()
{
	//int runTimer = iSetTimer(0, run);
	roadTimer = iSetTimer(100, moveRoad);
	virusFactoryTimer = iSetTimer(1500, virusFactory);

	srand((unsigned)time(NULL));
	iInitialize(windowWidth, windowHeight, "My Game");
	///updated see the documentations
	loadImages();
	iStart();
	return 0;
}
