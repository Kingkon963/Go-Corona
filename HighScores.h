void highScores(){
	iShowImage(0, 0, 1020, 720, stBG);
	iShowBMP2(350, 600, "images//high.bmp", 0);

	showHigh();// showing high score of all time
	iShowBMP2(10, 10, "images//home.bmp", 0);
}