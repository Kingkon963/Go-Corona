char* menuTitles2[6] = { "help", "credits", "highScores", "settings", "newGame", "gameOverPage" };
char* menuTitles[5] = { "images//help.bmp", "images//menu4.bmp", "images//menu3.bmp", "images//menu2.bmp", "images//menu1.bmp" };
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


MenuItem menuItems[5];
Menu menu(300, 200, 400, 50, menuItems, totalMenuItems);