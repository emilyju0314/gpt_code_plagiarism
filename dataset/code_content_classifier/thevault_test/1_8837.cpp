void filterRectangles(vector<Rect> &rects, Mat img){
	float margin = 0.8;
	int maxwidth = img.cols * margin;
	int maxheight = img.rows * margin;
	for(unsigned int i = 0; i < rects.size(); i++){
		if(rects[i].width > maxwidth || rects[i].height > maxheight){
			rects.erase(rects.begin() + i);
			i--;
			cout << "To large rectangle erased" << endl;
		}
	}
}