void homePage(){
	isHelpPage = false;
	iPauseTimer(virusFactoryTimer);
	iPauseTimer(maskTimer);
	iShowBMP(0, 0, "images//bg.bmp");
	menu.display();
}