void newGame(){
	iResumeTimer(virusFactoryTimer);

        iResumeTimer(maskTimer);

	
       if ((musicOn == true && optionMusicOn == true && gameOver == false) || (pause && optionMusicOn == true && gameOver == false))
	{
		//PlaySound("SOUNDS\\runSound.WAV", NULL, SND_LOOP | SND_ASYNC);
		BASS_ChannelPlay(runningSound, true);

		musicOn = false;
		pause = false;
		
	}

	

	iShowBMP(0, 524, "images//sky.bmp");
	
	sun();
	showCloud();
	iShowBMP2(0 ,650, "images//pause.bmp",0);
	iShowBMP2(0, 0, roads[roadIndex], -1);

	iText(10, windowHeight - 30, userName, GLUT_BITMAP_TIMES_ROMAN_24);


	if (!activeViruses.empty()){
		for (list<Virus>::iterator virus = activeViruses.begin(); virus != activeViruses.end(); virus++){
			virus->spawn();

			if ((virus->track.getX() + 110 > charecterX&&virus->track.getX() - 110<charecterX) && virus->track.getY() < charecterY + 100 && virus->hide == false && !jump)
			{
				if (optionMusicOn){
					BASS_ChannelPlay(collisionSound, false);
				}
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
			//jumpY -= 20;
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

	gameOverLogic();

}
