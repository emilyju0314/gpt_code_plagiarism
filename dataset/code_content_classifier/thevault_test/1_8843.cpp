void splitLargeRectangles(vector<Rect> &rects, int size){
	//cout << "splitLargeRectangles: " << rects.size() << endl;
	int msize = size * 1.0;
	vector<Rect> tohigh;
	for(unsigned int i; i < rects.size(); i++){
		int factor = (rects[i].height / msize) + 1;
		//cout << "height: " << rects[i].height << ", size: " << size  << endl;
		//cout << "tohigh: " << (rects[i].height / size) + 1.0  << endl;
		if(factor > 1){
			//cout << "tohigh: " << rects[i].height << endl;
			tohigh.push_back(rects[i]);
			rects.erase(rects.begin() + i);

			i--;

		}
	}
	for(unsigned int i = 0; i < tohigh.size(); i++){
		int factor = (tohigh[i].height / size);
		int remainder = tohigh[i].height % size;
		//cout << tohigh[i].height << ", " << (factor + 0.5) << endl;
		//cout << "remainder: " << remainder << endl;
		if(remainder != 0){
			Rect top = Rect(tohigh[i].x, tohigh[i].y, tohigh[i].width, remainder);
			rects.push_back(top);
		}
		int newheight = ((tohigh[i].height - remainder) / factor);
		for(int j = 0; j < factor; j++){
			int newy = (tohigh[i].y + remainder) + j * newheight;
			Rect n = Rect(tohigh[i].x, newy, tohigh[i].width, newheight);
			rects.push_back(n);
		}





	}




}