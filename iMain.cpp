#include "iGraphics.h"
#include <iostream>
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


int getPercentage(int num, int percent){
	return (int) ((num*percent) / 100);
}

struct MenuItem{
	char *title;
	int x, y;
	int width = 400;
	int height = 50;
	MenuItem(){}
	MenuItem(int x, int y, char *title) : x(x), y(y), title(title){
		
	}
	void display(){
		iRectangle(x, y, width, height);
		//cout << x + getPercentage(width, 50) << endl;
		iText(x + getPercentage(width, 40), y + getPercentage(height, 40), title, GLUT_BITMAP_HELVETICA_18);
	}
};

struct Menu{
	char **titles;
	int x = 0, y = 0;
	int dy = 70, totalItems;
	MenuItem **items;
	
	Menu(int x, int y, char titles[][15], int totalItems) :x(x), y(y), totalItems(totalItems){
		this->titles = (char**)malloc(sizeof(MenuItem)*totalItems);
		for (int i = 0; i < totalItems; i++) (this->titles)[i] = titles[i];
		//for (int i = 0; i < totalItems; i++){
		//	cout << (this->items)[i] << endl;
		//}
		items = (MenuItem**) malloc(sizeof(MenuItem)*totalItems);
	}
	
	void display(){
		for (int i = 0; i < totalItems; i++){
			//cout << "From Menu.display() " << i << " " << x << endl;
			/*MenuItem item(x, y, (this->titles)[i]);
			item.display();
			y += dy;*/
			//MenuItem items[i];
			items[i] = new MenuItem();

			items[i][0].x = this->x;
			items[i][0].y = this->y;
			items[i][0].title = this->titles[i];
			items[i][0].display();

			y += dy;
			delete items[i];
		}
		y -= dy*totalItems; // Resetting y
	}
};
void background()
{
	iFilledRectangle(0, 0, windowWidth, windowHeight);
	
}

char menuTitles[4][15] = { "Credits", "Settings", "High Scores", "New Game" };
Menu menu(300, 300, menuTitles, 4);

void iDraw()
{
	iClear();
	
	iSetColor(29, 67, 84);
	background();

	iSetColor(r, g, b);
	menu.display();
	
	//iShowBMP2(ix, iy, "images//person.bmp", -1);
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

}

void iMouse(int button, int state, int mx, int my)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		
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