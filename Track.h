struct Track{
	double x1, x2, y1, y2;
	double x, y, m;
	bool trackEnded = false;
	Track(){}
	Track(double x1, double y1, double x2, double y2){
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;

		this->x = x1;

		this->m = (y2 - y1) / (x2 - x1);
	}

	double getX(){
		return x;
	}

	double getY(){
		return abs(m*(x - x1) + y1);
	}

	void speed(double dx){
		if (x1 > x2){
			x -= dx;
			if (x <= x2) trackEnded = true;
		}
		else if (x1 < x2){
			x += dx;
			if (x >= x2) trackEnded = true;
		}
		else{
			cout << "Slope is Zero!" << endl;
		}

	}
};

Track lt(442, 514, 190, 0);
Track mt(490, 517, 450, 0);
Track rt(538, 508, 710, 0);