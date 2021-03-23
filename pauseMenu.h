char* pauseMenuTitlesText[4] = { "exit","help","settings","resume" };
char* pausemenuTitlesImg[4] = { "images//exit.bmp","images//help.bmp", "images//menu2.bmp", "images//resume.bmp" };
char* hoverP[4] = { "images//exitH.bmp","images//help1.bmp", "images//hover2.bmp", "images//resumeH.bmp" };


int totalMenuItems2 = 4;


MenuItem menuItems2[5];
Menu menu2(300, 200, 400, 50, menuItems2, totalMenuItems2, pauseMenuTitlesText, pausemenuTitlesImg, hoverP);

void pauseMenu(){
	BASS_ChannelPause(runningSound);

	iPauseTimer(roadTimer);
	iPauseTimer(charecterTimer);
	iPauseTimer(virusFactoryTimer);
	iPauseTimer(maskFactoryTimer);


	musicOn = true;
	pause = true;

	iShowBMP(0, 0, "images//bg.bmp");
	menu2.display();

}
