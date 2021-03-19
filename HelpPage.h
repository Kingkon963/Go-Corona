void helpPage(){
	/*
	write insructions, rules here.
	*/

	/*iText(250, 200 + scrollY, "write insructions, rules here.", GLUT_BITMAP_TIMES_ROMAN_24);*/
	iShowImage(0, 0, 1020, 720, helpImg);
	if (!pause) { iShowBMP2(10, 10, "images//home.bmp", 0); }
	else{ iShowBMP2(10, 10, "images//back.bmp", 0); }

}
