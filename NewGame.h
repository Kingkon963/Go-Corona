void newGame(){
	
	iResumeTimer(virusFactoryTimer);

	if (musicOn == true && optionMusicOn == true && gameOver == false)

	{
		PlaySound("SOUNDS\\runSound.WAV", NULL, SND_LOOP | SND_ASYNC);

		musicOn = false;
	}



	iShowBMP(0, 524, "images//sky.bmp");

	showCloud();

	iShowBMP2(0, 0, roads[roadIndex], -1);

	iText(10, windowHeight - 30, userName, GLUT_BITMAP_TIMES_ROMAN_24);


	if (!activeViruses.empty()){
		for (list<Virus>::iterator virus = activeViruses.begin(); virus != activeViruses.end(); virus++){
			virus->spawn();

			if ((virus->track.getX() + 110 > charecterX&&virus->track.getX() - 110<charecterX) && virus->track.getY() < charecterY + 100 && virus->hide == false)
			{
				
				life--;
				isCollision = true;
				virus->hide = true;
				collisionX = virus->track.getX() - 40;
				collisionY = virus->track.getY();
			}
			showExplosion();
		}
	}


	if (!activeMasks.empty()){
		for (list<Mask>::iterator mask = activeMasks.begin(); mask != activeMasks.end(); mask++){
			mask->spawn();
			
			
		}
	}




	if (!jump)
	{
		//iShowBMP2(charecterX, charecterY, charecterImg[runningIndex], 0);
		iShowImage(charecterX, charecterY, 170, 280, charecterImg[runningIndex]);
	}

	if (jump)
	{

		//iShowBMP2(charecterX, charecterY + jumpY, "images//b14.bmp", 0);
		iShowImage(charecterX, charecterY + jumpY, 170, 280, charecterImg[runningIndex]);
		jumpY += 20;
	
		if (jumpY > 200)
		{
			jump = false;
			jumpY = 0;
		}
	}
	
	runningIndex++;
	if (runningIndex >= 20) runningIndex = 0;

	//iLine(240, 140, 442, 514);
	point++;// SHOULD BE CHANGED

	show(point, 400, 670);// Showing int on screen
	lifeIndicator(life);
	if (life < 1)
		gameOver = true;
	/**iShowBMP2(windowWidth - 50, windowHeight - 50, "images//heart_filled.bmp", 0);
	iShowBMP2(windowWidth - 110, windowHeight - 50, "images//heart.bmp", 0);**/

	if (gameOver){
		takeScore = true;
		gameOverSound = true;
	}
	if (takeScore){
		universalScoreVar = point;
		setHigh(userName, point);//now for testing this function is taking score after pressing 'l',, it will take score when game over
		takeScore = false;
	}
	if (gameOver == true && takeScore == false){
		currentPage = "gameOverPage";
	}

}