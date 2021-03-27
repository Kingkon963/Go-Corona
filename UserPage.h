void userPage(){
	iShowImage(0, 0, 1020, 720, stBG);
	iShowBMP2(200, 500, "images//12.bmp", 0);

	iText(180, 360, ">>", GLUT_BITMAP_TIMES_ROMAN_24);
	iShowBMP2(200, 100, "images//13.bmp", 0);
	iSetColor(255, 0, 0);
	iText(250, 360, userName, GLUT_BITMAP_TIMES_ROMAN_24);
}