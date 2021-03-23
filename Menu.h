char* menuTitlesText[5] = { "help", "credits", "highScores", "settings", "newGame" };
char* menuTitlesImg[5] = { "images//help.bmp", "images//menu4.bmp", "images//menu3.bmp", "images//menu2.bmp", "images//menu1.bmp" };
char* hoverImg[5] = { "images//help1.bmp", "images//hover4.bmp", "images//hover3.bmp", "images//hover2.bmp", "images//hover1.bmp" };
int totalMenuItems = 5;

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
		iShowBMP2(x + getPercentage(width, 15), y + getPercentage(height, 50), backgroundImg, 0);
		if (this->isInsideThis(mpx, mpy))
			onHoverState = true;
		else
			onHoverState = false;

		if (onHoverState){
			iSetColor(0, 0, 0);
			//	iFilledRectangle(x, y, width, height);
			iShowBMP2(x + getPercentage(width, 8), y + getPercentage(height, 50), "images//arr.bmp", 0);
			iShowBMP2(x + getPercentage(width, 15), y + getPercentage(height, 50), hover, 0);
			iSetColor(255, 255, 255);
			if (firstEntry){
				PlaySound("Sounds\\btn_hover.wav", NULL, SND_ASYNC);
				firstEntry = false;
			}
		}
		else{
			firstEntry = true;
		}

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
	char **titlesText, **titlesImg, **hoverImg;

	Menu(int x, int y, int width, int height, MenuItem items[], int totalItems, char **menuTitlesText, char **menuTitlesImg, char **hoverImg) 
		:x(x), y(y), width(width), height(height), totalItems(totalItems), titlesText(menuTitlesText), 
		 titlesImg(menuTitlesImg), hoverImg(hoverImg){

		this->items = items;
	}


	void display(){
		for (int i = 0; i < totalItems; i++){
			items[i].x = this->x;
			items[i].y = this->y;
			items[i].width = this->width;
			items[i].height = this->height;
			items[i].title = titlesText[i];
			items[i].hover = hoverImg[i];
			items[i].backgroundImg = titlesImg[i];
			items[i].display();

			y += dy;
		}
		y -= dy*totalItems; // Resetting y
	}
};


MenuItem menuItems[5];
Menu menu(300, 200, 400, 50, menuItems, totalMenuItems, menuTitlesText, menuTitlesImg, hoverImg);