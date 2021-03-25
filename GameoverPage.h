void gameOverPage(){
	activeViruses.clear();
	isCollision = false;
	life = 3;
	BASS_ChannelPause(runningSound);
	BASS_ChannelPause(themeSong2);
	themeSong = true;
	mainSong = true;
	point = 0;
	if (optionMusicOn == true && gameOver == true && gameOverSound == true){
		PlaySound("SOUNDS\\gameover.wav", NULL, 1);
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
  
	pause = false;
	gameOver = false;
}

