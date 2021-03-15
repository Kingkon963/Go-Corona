void background()
{
	iFilledRectangle(0, 0, windowWidth, windowHeight);

}
void homePage(){
	iShowBMP(0, 0, "images//bg.bmp");
	menu.display();

}
/************************************************************************NEW GAME****************************************/
void newGame(){

	int life = 3;
	if (musicOn == true)
	{
		PlaySound("SOUNDS\\runSound.WAV", NULL, SND_LOOP | SND_ASYNC);

		musicOn = false;
	}


	iShowBMP(0, 524, "images//sky.bmp");
	showCloud();

	iShowBMP2(0, 0, roads[roadIndex], -1);

	iText(10, windowHeight - 30, userName, GLUT_BITMAP_TIMES_ROMAN_24);

	//iDelayMS(10);

	if (!activeViruses.empty()){
		for (list<Virus>::iterator virus = activeViruses.begin(); virus != activeViruses.end(); virus++){
			virus->spawn();

			if ((virus->track.getX() + 110 > charecterX&&virus->track.getX() - 110<charecterX) && virus->track.getY() < charecterY + 100 && virus->hide == false)
			{
				point = point - 50;
				isCollision = true;
				virus->hide = true;
				collisionX = virus->track.getX() - 40;
				collisionY = virus->track.getY();
			}
			showExplosion();
		}
	}





	if (!jump)
	{
		iShowBMP2(charecterX, charecterY, person_run[runningIndex], 0);
	}


	if (jump)
	{

		iShowBMP2(charecterX, charecterY + jumpY, "images//b14.bmp", 0);
		jumpY += 20;
		iDelayMS(10);
		if (jumpY > 200)
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
	/*iShowBMP2(lt.getX(), lt.getY(), "images//virus.bmp", 255);
	lt.speed(1);*/


	/*collision();
	if(isCollision)
	showExplosion();*/

	iShowBMP2(windowWidth - 50, windowHeight - 50, "images//heart_filled.bmp", 0);
	iShowBMP2(windowWidth - 110, windowHeight - 50, "images//heart.bmp", 0);
	if (gameOver){
		takeScore = true;
	}
	if (takeScore){
		universalScoreVar = point;
		setHigh(userName, point);//now for testing this function is taking score after pressing 'l',, it will take score when game over
		takeScore = false;
	}
	if (gameOver == true && takeScore == false){
		currentPage = "gameOverPage";
	}
	int id1 = iLoadImage("images//run1-01.png");
	iShowImage(50, 50, 150, 250, id1);

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

	iText(260, 575, "Music", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(260, 475, "Difficulity", GLUT_BITMAP_TIMES_ROMAN_24);

	if (scrollSettingsY == 0 && optionMusicOn == true){
		iText(470, 575, "ON", GLUT_BITMAP_TIMES_ROMAN_24);
		musicStateIndex = 0;
	}
	else if (scrollSettingsY == 0 && optionMusicOff == true){
		iText(470, 575, "OFF", GLUT_BITMAP_TIMES_ROMAN_24);
		musicStateIndex = 1;
	}
	else if (scrollSettingsY == 100 && optionDifficulityHigh == true){
		iText(470, 475, "HIGH", GLUT_BITMAP_TIMES_ROMAN_24);
		difficulityStateIndex = 2;
	}
	else if (scrollSettingsY == 100 && optionDifficulityLow == true){
		iText(470, 475, "LOW", GLUT_BITMAP_TIMES_ROMAN_24);
		difficulityStateIndex = 0;
	}
	else if (scrollSettingsY == 100 && optionDifficulityMedium == true){
		iText(470, 475, "MEDIUM", GLUT_BITMAP_TIMES_ROMAN_24);
		difficulityStateIndex = 1;
	}

	iRectangle(470, 565 - scrollSettingsY, 200, 50);
	iText(470, 575, musicState[musicStateIndex], GLUT_BITMAP_TIMES_ROMAN_24);
	iText(470, 475, difficulityState[difficulityStateIndex], GLUT_BITMAP_TIMES_ROMAN_24);
	iText(300, 275, "PRESS ARROW KEYS TO NAVIGATE", GLUT_BITMAP_TIMES_ROMAN_24);
	//iShowBMP2(370, 600, "images//22.bmp", 0);
	iShowBMP2(10, 10, "images//home.bmp", 0);
}
void helpPage(){
	/*
	write insructions, rules here.
	*/
	iText(250, 200 + scrollY, "write insructions, rules here.", GLUT_BITMAP_TIMES_ROMAN_24);
	iShowBMP2(10, 10, "images//home.bmp", 0);
}
void creditPage(){
	iShowBMP(0, 0, "images//creditBack.bmp");
	iShowBMP2(200, 650, "images//credits.bmp", 0);
	iLine(200, 625, 500, 625);
	iShowBMP2(500, 550, "images//naim1.bmp", 0);
	iShowBMP2(500, 400, "images//omi1.bmp", 0);
	iShowBMP2(500, 250, "images//rafid1.bmp", 0);
	iShowBMP2(500, 100, "images//nirjon1.bmp", 0);

	iShowBMP(300, 480, "images//Naim.bmp");
	iShowBMP(300, 330, "images//omi.bmp");
	iShowBMP(300, 180, "images//Fahim.bmp");
	iShowBMP(300, 30, "images//Nirjon.bmp");


	iText(500, 525, "ID- 190204081", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(500, 375, "ID- 190204074", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(500, 225, "ID- 190204082", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(500, 75, "ID- 190204063", GLUT_BITMAP_TIMES_ROMAN_24);
	iDelayMS(10);

	iShowBMP2(10, 10, "images//home_black.bmp", 0);



	//ImgButton home(10, windowHeight - 60, "images//home.bmp", "homePage");
	//home.display();
}
void gameOverPage(){
	PlaySound(NULL, 0, 0);
	point = 0;
	takeInput = true;
	char p[100];
	iShowBMP(0, 0, gameOverImg[gameOverIndex]);
	gameOverIndex++;
	iDelayMS(100);
	if (gameOverIndex == 3){
		gameOverIndex = 0;
	}
	iText(640, 260, "YOUR SCORE", GLUT_BITMAP_TIMES_ROMAN_24);
	convertInt(p, universalScoreVar);
	iText(690, 210, p, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(265, 70, "PRESS ANY KEY TO RETURN HOME", GLUT_BITMAP_TIMES_ROMAN_24);
	gameOver = false;
}