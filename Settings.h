void settings(){
	iShowImage(0, 0, 1020, 720, stBG);
	iText(260, 575, "Music", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(260, 475, "Difficulity", GLUT_BITMAP_TIMES_ROMAN_24);

	if (scrollSettingsY == 0 && optionMusicOn == true){
		//iText(470, 575, "ON", GLUT_BITMAP_TIMES_ROMAN_24);
		iShowImage(470, 555, 60, 60, onImg);
		musicStateIndex = 0;
	}
	else if (scrollSettingsY == 0 && optionMusicOff == true){
		//iText(470, 575, "OFF", GLUT_BITMAP_TIMES_ROMAN_24);
		iShowImage(470, 555, 60, 60, offImg);
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
	//iText(470, 575, musicState[musicStateIndex], GLUT_BITMAP_TIMES_ROMAN_24);

	if (musicState[musicStateIndex] == "ON")
		iShowImage(470, 555, 60, 60, onImg);
	else
		iShowImage(470, 555, 60, 60, offImg);


	iText(470, 475, difficulityState[difficulityStateIndex], GLUT_BITMAP_TIMES_ROMAN_24);
	iText(300, 275, "PRESS ARROW KEYS TO NAVIGATE", GLUT_BITMAP_TIMES_ROMAN_24);
	//iShowBMP2(370, 600, "images//22.bmp", 0);
	if (!pause) { iShowBMP2(10, 10, "images//home.bmp", 0); }
	else{ iShowBMP2(10, 10, "images//back.bmp", 0); }
	


}