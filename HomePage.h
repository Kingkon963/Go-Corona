void homePage(){
	if (mainSong == true && optionMusicOn == true)
	{
		BASS_ChannelPlay(themeSong1, true);
		mainSong = false;
	}
	isHelpPage = false;
	iPauseTimer(virusFactoryTimer);
	iPauseTimer(maskTimer);
	iShowBMP(0, 0, "images//bg.bmp");
	menu.display();
}