void helpPage(){
	/*
	write insructions, rules here.
	*/
	isHelpPage = true;
	if (helpIndex == 1)
		iShowImage(0, 0, 1020, 720, helpImg1);
	else if (helpIndex==2)
		iShowImage(0, 0, 1020, 720, helpImg2);
	else if (helpIndex == 3)
		iShowImage(0, 0, 1020, 720, helpImg3);

	iShowBMP2(10, 10, "images//home.bmp", 0);
}