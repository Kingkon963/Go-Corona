void homePage(){
	if (mainSong == true && optionMusicOn == true)
	{
		BASS_ChannelPlay(themeSong1, true);
		mainSong = false;
	}
	isHelpPage = false;
	helpIndex = 1;
	iPauseTimer(virusFactoryTimer);
	iPauseTimer(maskTimer);

	//iShowBMP(0, 0, "images//bg.bmp");
	iShowImage(0, 0, 1020, 720, homeImg);
	iShowImage(250, 607, 402, 77, logoImg);
	
	menu.display();
}