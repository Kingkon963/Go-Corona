struct Virus{
	int image;
	Track track;
	int size;
	double speed;
	bool hide;

	Virus(){
		hide = false;
		speed = 1;
		size = 50;
	}
	void spawn(){
		if (!hide){
			setVirusSize();
			iShowImage(track.getX(), track.getY(), size, size, image);
			track.speed(speed);
		}
		if (track.getY() > Y2) size = 50;
		else if (track.getY() < Y2 && track.getY() > Y1) size = 75;
		else if (track.getY() < Y1) size = 100;

		if (track.trackEnded) hide = true;

	}

	void setVirusSize(){
		if (size == 50) image = virusImg;
		else if (size == 75) image = virusImg75;
		else if (size == 100) image = virusImg100;
		else{
			cout << "Invalid Virus Size" << endl;
			exit(1);
		}
	}
};


Virus virus;
list<Virus> activeViruses;
struct Mask{
	int imageM;
	Track trackM;
	int sizeM;
	double speedM;
	bool hideM;

	Mask(){
		hideM = false;
		speedM = 1;
		sizeM = 50;
	}
	void spawn(){
		if (!hideM){
			setMaskSize();
			iShowImage(trackM.getX(), trackM.getY(), sizeM, sizeM, imageM);
			trackM.speed(speedM);
		}
		if (trackM.getY() > Y2) sizeM = 50;
		else if (trackM.getY() < Y2 && trackM.getY() > Y1) sizeM = 75;
		else if (trackM.getY() < Y1) sizeM = 100;

		if (trackM.trackEnded) hideM = true;

	}

	void setMaskSize(){
		if (sizeM == 50) imageM = maskImg;
		else if (sizeM == 75) imageM = maskImg75;
		else if (sizeM == 100) imageM = maskImg100;
		else{
			cout << "Invalid Virus Size" << endl;
			exit(1);
		}
	}
};


Mask mask;
list<Mask> activeMasks;