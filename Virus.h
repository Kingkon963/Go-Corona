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