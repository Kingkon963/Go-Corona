#include "iGraphics.h"
#include <iostream>
#include <array>
using namespace std;
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

#define windowWidth 1020
#define windowHeight 720

int x;
int y;

int r = 255;
int g = 255;
int b = 255;

int ix=0, iy=0;

int mpx, mpy, count=0;

string currentPage = "homePage";


int getPercentage(int num, int percent){
	return (int) ((num*percent) / 100);
}

typedef struct MenuItem{
	char *title;
	int x, y;
	int width = 400;
	int height = 50;
	bool onHoverState = false, firstEntry = true;
	
	MenuItem(){}
	MenuItem(int x, int y, char *title) : x(x), y(y), title(title){

	}

	bool isInsideThis(int mx, int my){ //true if cursor is inside of the MenuItem
		return (mx >= x && mx <= (x + width)) && (my >= y && my <= (y + height));
	}
	void display(){
		if (this->isInsideThis( mpx, mpy )) 
			onHoverState = true;
		else 
			onHoverState = false;

		if (onHoverState){
			iSetColor(0, 0, 0);
			iFilledRectangle(x, y, width, height);
			iSetColor(255, 255, 255);
			if (firstEntry){
				PlaySound("Sounds\\btn_hover.wav", NULL, SND_ASYNC);
				firstEntry = false;
			}
		}
		else{
			iRectangle(x, y, width, height);
			firstEntry = true;
		}

		//cout << mpx << " " << mpy << endl;
		iText(x + getPercentage(width, 40), y + getPercentage(height, 40), title, GLUT_BITMAP_HELVETICA_18);
	}

	void cliked(){
		currentPage = this->title;
	}
} MenuItem;


char* menuTitles[4] = { "Credits", "Settings", "High Scores", "New Game" };
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
			items[i].title = menuTitles[i];
			items[i].display();

			y += dy;
		}
		y -= dy*totalItems; // Resetting y
	}
};


void background()
{
	iFilledRectangle(0, 0, windowWidth, windowHeight);
	
}


int totalMenuItems = 4;
MenuItem menuItems[4];
Menu menu(300, 200, 400, 50, menuItems, totalMenuItems);


void homePage(){
	menu.display();
}


char person_run[2][20] = { "images//b14.bmp", "images//b17.bmp" };
int runnngIndex = 0;

void lifeIndicator(int life){
	int dx = 50, i,j;
	if (life >= 0 && life <= 3){
		for (i = 0; i < life; i++){
			iShowBMP2(windowWidth - dx, windowHeight - 50, "images//heart_filled.bmp", 0);
			dx += 60;
		}
		for (j = 3-i; j ; j--){
			iShowBMP2(windowWidth - dx, windowHeight - 50, "images//heart.bmp", 0);
			dx += 60;
		}
	}
};

char scene[53][30] =
{ "scene00001.bmp",
"scene00031.bmp",
"scene00041.bmp",
"scene00051.bmp",
"scene00061.bmp",
"scene00071.bmp",
"scene00081.bmp",
"scene00091.bmp",
"scene00101.bmp",
"scene00111.bmp",
"scene00121.bmp",
"scene00131.bmp",
"scene00141.bmp",
"scene00151.bmp",
"scene00161.bmp",
"scene00171.bmp",
"scene00181.bmp",
"scene00191.bmp",
"scene00201.bmp",
"scene00211.bmp",
"scene00221.bmp",
"scene00231.bmp",
"scene00241.bmp",
"scene00251.bmp",
"scene00261.bmp",
"scene00271.bmp",
"scene00281.bmp",
"scene00291.bmp",
"scene00301.bmp",
"scene00311.bmp",
"scene00321.bmp",
"scene00331.bmp",
"scene00341.bmp",
"scene00351.bmp",
"scene00361.bmp",
"scene00371.bmp",
"scene00381.bmp",
"scene00391.bmp",
"scene00401.bmp",
"scene00411.bmp",
"scene00421.bmp",
"scene00431.bmp",
"scene00441.bmp",
"scene00451.bmp",
"scene00461.bmp",
"scene00471.bmp",
"scene00481.bmp",
"scene00491.bmp",
"scene00501.bmp",
"scene00511.bmp",
"scene00521.bmp",
"scene00531.bmp",
"scene00541.bmp",
};

int sceneIndex = 0;
void newGame(){
	int life = 2;
	

	iShowBMP2(0, 0, "images//road.bmp", -1);
	if (sceneIndex >= 20) sceneIndex = 0;

	lifeIndicator(life);

	iShowBMP2((windowWidth / 2) - 85, 0, person_run[runnngIndex++], 0);
	if (runnngIndex > 1) runnngIndex = 0;
	iDelayMS(100);

	cout << sceneIndex << endl;
}


void creditPage(){

	//ImgButton home(10, windowHeight - 60, "images//home.bmp", "homePage");
	//home.display();
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
	else if (currentPage == "New Game")
		newGame();
	else if (currentPage == "Credits")
		creditPage();
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


void iKeyboard(unsigned char key)
{
	if (key == '\r')
	{
		
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

	
	if (key == GLUT_KEY_RIGHT)
	{
				
	}
	if (key == GLUT_KEY_LEFT)
	{
		
	}
	
	if (key == GLUT_KEY_HOME)
	{
		
	}
	
}


int main()
{
	///srand((unsigned)time(NULL));
	iInitialize(windowWidth, windowHeight, "My Game");
	///updated see the documentations
	iStart();
	return 0;
}