char* menuTitles3[4] = { "exit","help","settings","resume" };
char* menuTitles4[4] = { "images//exit.bmp","images//help.bmp", "images//menu2.bmp", "images//resume.bmp" };
char* hoverP[4] = { "images//exitH.bmp","images//help1.bmp", "images//hover2.bmp", "images//resumeH.bmp" };


int totalMenuItems2 = 4;

struct MenuItem2{
	char *title2;
	char *backgroundImg2;
	char *hover2; //to store hover effect image 
	int x, y;
	int width = 400;
	int height = 50;
	bool onHoverState2 = false, firstEntry2 = true;

	MenuItem2(){}
	MenuItem2(int x, int y, char *title2) : x(x), y(y), title2(title2), backgroundImg2(backgroundImg2){

	}

	bool isInsideThis(int mx, int my){ //true if cursor is inside of the MenuItem
		return (mx >= x && mx <= (x + width)) && (my >= y && my <= (y + height));
	}
	void display2(){
		iShowBMP2(x + getPercentage(width, 0), y + getPercentage(height, 40), backgroundImg2, 0);
		if (this->isInsideThis(mpx, mpy))
			onHoverState2 = true;
		else
			onHoverState2 = false;

		if (onHoverState2){
			iSetColor(0, 0, 0);
			//	iFilledRectangle(x, y, width, height);
			iShowBMP2(x + getPercentage(width, -7), y + getPercentage(height, 40), "images//arr.bmp", 0);
			iShowBMP2(x + getPercentage(width, 0), y + getPercentage(height, 40), hover2, 0);
			iSetColor(255, 255, 255);
			if (firstEntry2){
				PlaySound("Sounds\\btn_hover.wav", NULL, SND_ASYNC);
				firstEntry2 = false;
			}
		}
		else{
			//iRectangle(x, y, width, height);
			firstEntry2 = true;
		}

		//iText(x + getPercentage(width, 40), y + getPercentage(height, 40), title, GLUT_BITMAP_HELVETICA_18);

	}

	void cliked(){
		currentPage = this->title2;
	}
};

struct Menu2{
	int x = 0, y = 0;
	int dy = 70, totalItems2;
	int width, height;
	MenuItem2 *items2;

	Menu2(int x, int y, int width, int height, MenuItem2 items2[], int totalItems2) :x(x), y(y), width(width), height(height), totalItems2(totalItems2){
		this->items2 = items2;
	}

	void display2(){
		for (int i = 0; i < totalItems2; i++){
			items2[i].x = this->x;
			items2[i].y = this->y;
			items2[i].width = this->width;
			items2[i].height = this->height;
			items2[i].title2 = menuTitles3[i];
			items2[i].hover2 = hoverP[i];//hover state image (Muhaiminul kabir)
			items2[i].backgroundImg2 = menuTitles4[i];
			items2[i].display2();

			y += dy;
		}
		y -= dy*totalItems2; // Resetting y
	}
};


MenuItem2 menuItems2[5];
Menu2 menu2(300, 200, 400, 50, menuItems2, totalMenuItems2);
void pauseMenu(){
	pause = true;
	BASS_ChannelStop(runningSound);
	iPauseTimer(virusFactoryTimer);
	iShowBMP(0, 0, "images//bg.bmp");
	menu2.display2();

}
