#define _CRT_SECURE_NO_WARNINGS //WARNING!!!! DO NOT CHANGE THIS. CHANGING THIS WILL DESTROY YOUR GAME.
//bypassing security warning of vs 2013
#include "iGraphics.h"
#include <iostream>
#include <array>
#include <string>
#include <list>
#include<windows.h>
#include <time.h>
#include <bass/bass.h>

using namespace std;
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

#define windowWidth 1020
#define windowHeight 720
#define Y1 264
#define Y2 416
#define GH 1 ///////// for high score////////////

HSTREAM runningSound, collisionSound,themeSong1,themeSong2,coughSound,glitchSound;
bool themeSong = true;
int jumpIndex = 0;
bool skip = false;
bool newG = false;
bool gameOver = false;
bool inDis = true;
bool takeInput = true; //logic for input user name
bool takeScore = true;
bool showPassiveMousePosition = true;
//for high score
long int  point = 0;
int flag = 0;
int movec = (windowWidth / 2) - 85;
int randomTrack, prevTrack = -1;
int index0 = 0;
int in = 0;
double getSpeedByDifficulty[3][3] = { { 1.5, 2, 2.5 }, { .3, .35, .4 }, { 1, 1.5, 2 } };

char userName[1000];
char s[100];
int pointTimer;
int heartTimer;
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
int roadTimer, charecterTimer,introTimer;

string currentPage = "introPage";

//char person_run[2][20] = { "images//b14.bmp", "images//b17.bmp" };
int runningIndex = 0;
//intro
int intro1, intro2,intro3;
int intro_i = 0;
int introIndex[60] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1};
char roads[5][20] =
{
	"images//a.bmp",
	"images//b.bmp",
	"images//c.bmp",
	"images//d.bmp",
	"images//e.bmp"
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
int maskImg;
int maskImg75;
int maskImg100;

int homeImg;

int life = 3;
int roadIndex = 3;
bool musicOn = true;
bool gameOverSound = false;
//int vx = 442, vy = 0;
int charecterX = (windowWidth / 2) - 80;
int charecterY = 10;
bool jump = false;
int jumpY = 0;
int max_jumpY = 200;
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
int helpIndex = 1;
bool isHelpPage = false;
int helpImg3;
int helpImg1;
int helpImg2;
bool optionMusicOff = false;
bool optionMusicOn = true;
bool optionDifficulityHigh = false;
bool optionDifficulityLow = true;
bool optionDifficulityMedium = false;
int musicStateIndex = 0;
int difficulityStateIndex = 0;
int stBG;
int randomTrackV = -1;
int randomTrackM = -1;
int prevTrackM;
int maskFactoryTimer;
bool mainSong = true;
bool pause = false;


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
void jumpdown();



struct playerData{
	char pl[1000];
	long int scr;
};

void IntroFunction(){
	iResumeTimer(introTimer);
	if (intro_i>20)
	BASS_ChannelPlay(glitchSound, false);
	if (introIndex[intro_i] == 0)
		iShowImage(0,0,1020,720,intro1);

	else if (introIndex[intro_i] == 1)
		iShowImage(0, 0, 1020, 720, intro2);
	else if (introIndex[intro_i] == 2)
		iShowImage(0, 0, 1020, 720, homeImg);

	if (intro_i > 59)
	{
		BASS_ChannelStop(glitchSound);
		intro_i = 0;
		iPauseTimer(introTimer);
		currentPage = "homePage";
	}



};
void intro_indexer()
{
	intro_i++;
};
void gameOverLogic(){
	if (gameOver){
		takeScore = true;
		gameOverSound = true;
	}
	if (takeScore){
		universalScoreVar = point;
		setHigh(userName, point);//now for testing this function is taking score after pressing 'l',, it will take score when game over
		takeScore = false;
	}
	if (gameOver == true && takeScore == false){
		currentPage = "gameOverPage";
	}
}

#include "Track.h";
#include "Virus.h";
#include "Mask.h";
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
	helpImg1 = iLoadImage("images/helpImg1.png");
	helpImg2 = iLoadImage("images/helpImg2.png");
	helpImg3 = iLoadImage("images/helpImg3.png");
     maskImg=iLoadImage("images/maskImg.png");
	 maskImg75 = iLoadImage("images/maskImg75.png");
	 maskImg100 = iLoadImage("images/maskImg100.png");
	 stBG = iLoadImage("images/standardBG.png");

	 intro1 = iLoadImage("images/intro1.png");

	 intro2 = iLoadImage("images/intro2.png");

	 homeImg = iLoadImage("images/home.png");
	
	 for (int i = 0; i < 21; i++){
		charecterImageAddress = "images/charecter/";
		charecterImageAddress += to_string(i+1);
		charecterImageAddress += ".png";

		charecterImg[i] = iLoadImage((char *)charecterImageAddress.c_str());
	}
}
void loadSounds() {
	coughSound = BASS_StreamCreateFile(false, "Sounds/Coughing.mp3", 0, 0, BASS_SAMPLE_MONO);
	runningSound = BASS_StreamCreateFile(false, "Sounds/runSound.wav", 0, 0, BASS_SAMPLE_LOOP);
	collisionSound = BASS_StreamCreateFile(false, "Sounds/collision.wav", 0, 0, BASS_SAMPLE_MONO);
	themeSong1 = BASS_StreamCreateFile(false, "Sounds/themeSong1.wav", 0, 0, BASS_SAMPLE_LOOP);
	themeSong2 = BASS_StreamCreateFile(false, "Sounds/themeSong2.wav", 0, 0, BASS_SAMPLE_LOOP);
	glitchSound = BASS_StreamCreateFile(false, "Sounds/glitchEffect.mp3", 0, 0, BASS_SAMPLE_MONO);
	BASS_ChannelSetAttribute(runningSound, BASS_ATTRIB_VOL, 1);
	BASS_ChannelSetAttribute(collisionSound, BASS_ATTRIB_VOL, .3);
	BASS_ChannelSetAttribute(themeSong1, BASS_ATTRIB_VOL, .3);
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
		iText(650, 500, "Score", GLUT_BITMAP_TIMES_ROMAN_24);
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
					iText(650, 450 - i, p, GLUT_BITMAP_TIMES_ROMAN_24);

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
	roadIndex++;
	if (roadIndex>4 ) roadIndex = 0;
}

void moveCharecter(){
	if (!jump){
		runningIndex++;
		if (runningIndex >= 20) runningIndex = 0;
	}

}

void pointFunction()
{
	point++;

}
void sun(){
	iSetColor(247, 127, 0);
	iFilledCircle(161, 625, 50, 100);

}
void virusFactory(){
	 randomTrackV = rand() % 3;
	while (randomTrackV == prevTrack || randomTrackV == randomTrackM) randomTrackV = rand() % 3;

	switch (randomTrackV){
	case 0:
		virus.track = lt;
		virus.speed = getSpeedByDifficulty[0][difficulityStateIndex];
		prevTrack = 0;
		break;
	case 1:
		virus.track = mt;
		virus.speed = getSpeedByDifficulty[1][difficulityStateIndex];
		prevTrack = 1;
		break;
	case 2:
		virus.track = rt;
		virus.speed = getSpeedByDifficulty[2][difficulityStateIndex];
		prevTrack = 2;
		break;
	default:
		cout << "Error in generating randomTrack for Virus" << endl;
	}

	cout << virus.hide << endl;
	activeViruses.push_back(virus);

	if (activeViruses.size() == 30) {
		activeViruses.pop_front();
	}


}
void maskFactory(){
	randomTrackM = rand() % 3;
	while (randomTrackM == prevTrackM || randomTrackM == randomTrackV) randomTrackM = rand() % 3;

	switch (randomTrackM){
	case 0:
		mask.trackM = lt;
		mask.speedM = getSpeedByDifficulty[0][difficulityStateIndex];
		prevTrackM = 0;
		break;
	case 1:
		mask.trackM = mt;
		mask.speedM = getSpeedByDifficulty[1][difficulityStateIndex];
		prevTrackM = 1;
		break;
	case 2:
		mask.trackM = rt;
		mask.speedM = getSpeedByDifficulty[2][difficulityStateIndex];
		prevTrackM = 2;
		break;
	default:
		cout << "Error in generating randomTrack for Mask" << endl;
	}


	activeMasks.push_back(mask);

	if (activeMasks.size() == 10) {
		activeMasks.pop_front();
	}


}

void iDraw()
{
	iClear();
	iSetColor(0, 48, 73);
	background();

	iSetColor(r, g, b);

	iText(0, 0, &currentPage[0]);
	if (currentPage == "introPage")
		IntroFunction();
	else if (currentPage == "homePage")
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
	else if (currentPage == "pauseMenu"){
		pauseMenu();
	}
	else if (currentPage == "resume"){
		currentPage = "newGame";
	}
	else if (currentPage == "exit"){
		gameOver = true;
		gameOverLogic();
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
			if (currentPage != "gameOverPage"){
				PlaySound("Sounds\\click.wav", NULL, SND_ASYNC);
			}

			if (currentPage == "homePage"){
				for (int i = 0; i < totalMenuItems; i++){
					if (menuItems[i].isInsideThis(mx, my)){
						menuItems[i].cliked();
						break;
					}
				}
			}

			if (currentPage == "pauseMenu"){
				for (int i = 0; i < totalMenuItems; i++){
					if (menuItems2[i].isInsideThis(mx, my)){
						menuItems2[i].cliked();
						break;
					}
				}
			}
			else if (currentPage != "newGame"){
				if (!pause){
					if (mx < 100 && my < 100){
						iShowBMP2(mpx, mpy, "images//home_black.bmp", 255);
						currentPage = "homePage";
						scrollY = 0;
						scrollSettingsY = 0;
					}
				}
				else{
					if (mx < 100 && my < 100){
						iShowBMP2(mpx, mpy, "images//home_black.bmp", 255);
						currentPage = "pauseMenu";
						scrollY = 0;
						scrollSettingsY = 0;
					}
				}
				
			}
			else if (currentPage == "newGame"){
				if (mx < 100 && my < 700 && my > 630){
					currentPage = "pauseMenu";

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

	if (key&&isHelpPage == true)
	{
		helpIndex++;
		if (helpIndex > 3)
			helpIndex = 1;
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
		if (key == GLUT_KEY_RIGHT&&jump == false)
		{
			charecterX += 285;
			if (charecterX > 720)
				charecterX = 720;

		}
		if (key == GLUT_KEY_LEFT&&jump == false)
		{
			charecterX -= 285;
			if (charecterX < 150)
				charecterX = 150;

		}
		if (key == GLUT_KEY_UP){
			if (!jump){
				jump = true;
				BASS_ChannelPause(runningSound);
				cout << "Sound Paused..." << jump << endl;
			}
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
			if (optionMusicOn == false)
				BASS_ChannelPause(themeSong1);
			
		
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
			if (optionMusicOn == true)
				BASS_ChannelPlay(themeSong1, true);
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
	charecterTimer = iSetTimer(10, moveCharecter);

	pointTimer = iSetTimer(500,pointFunction);

	virusFactoryTimer = iSetTimer(1600, virusFactory);
	maskFactoryTimer = iSetTimer(30000,maskFactory);
	introTimer = iSetTimer(100,intro_indexer);

	srand((unsigned)time(NULL));

	iInitialize(windowWidth, windowHeight, "My Game");
	///updated see the documentations
	
	loadImages();

	if (!BASS_Init(-1, 44100, 0, NULL, NULL))
		cout << "Failed in BASS_Init" << endl;
		
	loadSounds();

	iStart();
	return 0;
}
