#include "iGraphics.h"
#include <iostream>
#include <array>
#include <string>
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


char roads[4][20] =
{
	"images//a.bmp",
	"images//b.bmp",
	"images//c.bmp",
	"images//d.bmp"
};
int roadIndex=3, musicOn = true;
int vx = 442, vy = 0;

void newGame(){
	int life = 3;

	if (musicOn){
		PlaySound("Sounds\\corona2.wav", NULL, SND_LOOP);
		musicOn = false;
	}

	lifeIndicator(life);

	iShowBMP2(0, 0, roads[roadIndex--], -1);
	if (roadIndex <= 0) roadIndex = 3;
	if (runnngIndex > 1) runnngIndex = 0;
	iDelayMS(10);


	iShowBMP2((windowWidth / 2) - 85, 0, person_run[runnngIndex++], 0);
	if (runnngIndex > 1) runnngIndex = 0;
	iDelayMS(100);

	//iLine(240, 140, 442, 514);
	vy = ((187 * vx) / 101) - (30740 / 101);
	iShowBMP2(vx, vy, "images//virus.bmp", 255);
	vx -= 10;
	if (vx <= 240) vx = 442;
}


void creditPage(){

	//ImgButton home(10, windowHeight - 60, "images//home.bmp", "homePage");
	//home.display();
}

void iDraw()
{
	iClear();
	//cout << mpx << " " << mpy << endl;
	
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