void organizeWithLines(vector<Rect> &boxes, vector<Point2d> lines, Mat &img, int size, vector<Rect> &out){
	RNG rng(12345);
	vector<Scalar> colors;
	for(unsigned int j = 0; j < lines.size() + 1; j++){
		colors.push_back(randomColor(rng));
	}

	vector<Point2d> linestarts;

	vector<Box> ordened;
	vector<BoxLine> ordenedl;

	for(unsigned int i = 0; i < boxes.size(); i++){
		Point p = midPoint(boxes[i]);
		int maxliney = img.rows;
		unsigned int maxindex = lines.size();


		Box nn;
		Point nnn;
		Scalar c = randomColor(rng);
		for(unsigned int j = 0; j < lines.size(); j++){
			double lineval = lines[j].x * p.x + lines[j].y;
			if(p.y < lineval &&

					lineval < maxliney ){
				maxliney = lines[j].x * p.x + lines[j].y;
				maxindex = j;
				nn = Box(boxes[i], Point(lines[j].x,lines[j].y));
				nnn = Point2d(0,lines[j].y);

			}
		}

		if(!inPointVector(nnn,linestarts)){
			linestarts.push_back(nnn);
		}

		int index = inBoxLines(nnn.y, ordenedl);
		if(index == -1){
			ordened.clear();
			ordened.push_back(nn);
			ordenedl.push_back(BoxLine(ordened, nnn.y));
		}else {
			ordenedl[index].v.push_back(nn);
		}
		ordened.push_back(nn);



	}
	int lineheight = findLineHeight(boxes, lines, size);
	//cout << lineheight << endl;

	orderLines(ordenedl);
	int count = 0;


	filterLines(ordenedl,lineheight);
	finalPreparations(ordenedl, lineheight);


	for(size_t i = 0; i < ordenedl.size(); i++){
		for(size_t j = 0; j < ordenedl[i].v.size(); j++){
			count++;
			int x = ordenedl[i].v[j].rect.x;
			int y = ordenedl[i].v[j].rect.y;
			putText(img, convertInt2(count), Point(x,y),
							CV_FONT_HERSHEY_COMPLEX, 1.0, Scalar(0, 0, 0), 2);
			rectangle(img,ordenedl[i].v[j].rect, Scalar(0));
			out.push_back(ordenedl[i].v[j].rect);

		}
		int endco = ordenedl[i].v[0].line.x * img.cols + ordenedl[i].v[0].line.y;
		Point p1 = Point(0, ordenedl[i].v[0].line.y);
		Point p2 = Point(img.cols, endco);

		if(ordenedl[i].br_afterline){
			line(img, p1, p2, Scalar(0,255,0),2);

		} else {
			line(img, p1, p2, Scalar(0,0,255),2);
		}
	}


}