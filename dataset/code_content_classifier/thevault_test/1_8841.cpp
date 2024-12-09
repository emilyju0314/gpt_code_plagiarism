int inBoxLines(int y, vector<BoxLine> target){
	int result = -1;
	for(unsigned int i = 0; i < target.size(); i++){
		if(target[i].y == y){
			result = i;
			break;
		}
	}
	return result;

}