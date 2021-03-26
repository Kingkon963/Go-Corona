void homePage(){
	if (mainSong == true && optionMusicOn == true)
	{
		BASS_ChannelPlay(themeSong1, true);
		mainSong = false;
	}
	isHelpPage = false;

	helpIndex = 1;

	

	iPauseTimer(virusFactoryTimer);
	iPauseTimer(maskFactoryTimer);

	//iShowBMP(0, 0, "images//bg.bmp");
	iShowImage(0, 0, 1020, 720, homeImg);

	
	menu.display();
}