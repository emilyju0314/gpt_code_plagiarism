bool inPointVector(Point2d a, vector<Point2d> target){
	bool result = false;
	for(unsigned int i = 0; i < target.size(); i++){
		if(target[i].x == a.x && target[i].y == a.y){
			result = true;
			break;
		}
	}
	return result;

}