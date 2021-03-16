void gameOverPage(){

	life = 3;
	if (optionMusicOn == true && gameOver == true && gameOverSound == true){
		PlaySound("SOUNDS\\gameover.WAV", NULL, 1);
		gameOverSound = false;

	}

	if (optionMusicOn){
		musicOn = true;
	}
	index0 = 0;
	userName[index0] = '\0';

	point = 0;
	takeInput = true;
	char p[100];
	iShowBMP(0, 0, gameOverImg[gameOverIndex]);
	gameOverIndex++;
	iDelayMS(100);
	if (gameOverIndex == 3){
		gameOverIndex = 0;
	}
	iShowBMP2(370, 260, "images//yourScore.bmp", 0);
	//convertInt(p, universalScoreVar);
	show(universalScoreVar, 465, 200);
	//iText(400, 210,p, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(300, 70, "PRESS ANY KEY TO RETURN HOME", GLUT_BITMAP_TIMES_ROMAN_24);
	gameOver = false;
}