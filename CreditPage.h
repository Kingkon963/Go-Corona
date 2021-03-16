void creditPage(){
	iShowBMP(0, 0, "images//creditBack.bmp");
	iShowBMP2(200, 650, "images//credits.bmp", 0);
	iLine(200, 625, 500, 625);
	iShowBMP2(500, 550, "images//naim1.bmp", 0);
	iShowBMP2(500, 400, "images//omi1.bmp", 0);
	iShowBMP2(500, 250, "images//rafid1.bmp", 0);
	iShowBMP2(500, 100, "images//nirjon1.bmp", 0);

	iShowBMP(300, 480, "images//Naim.bmp");
	iShowBMP(300, 330, "images//omi.bmp");
	iShowBMP(300, 180, "images//Fahim.bmp");
	iShowBMP(300, 30, "images//Nirjon.bmp");


	iText(500, 525, "ID- 190204081", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(500, 375, "ID- 190204074", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(500, 225, "ID- 190204082", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(500, 75, "ID- 190204063", GLUT_BITMAP_TIMES_ROMAN_24);
	iDelayMS(10);

	iShowBMP2(10, 10, "images//home_black.bmp", 0);



	//ImgButton home(10, windowHeight - 60, "images//home.bmp", "homePage");
	//home.display();
}