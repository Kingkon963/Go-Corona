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



	/*iText(250, 200 + scrollY, "write insructions, rules here.", GLUT_BITMAP_TIMES_ROMAN_24);*/

	if (!pause) { iShowBMP2(10, 10, "images//home.bmp", 0); }
	else{ iShowBMP2(10, 10, "images//back.bmp", 0); }

}

