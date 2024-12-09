void combineRects(vector<Rect> &rectangles) {
	bool change = true;
	while (change) {
		change = false;

		for (unsigned int i = 0; i < rectangles.size(); i++) {
			int result = inBox(i, rectangles);
			if(result != -1){
				rectangles.erase(rectangles.begin() + i);
				i--;
			}

		}
	}

}