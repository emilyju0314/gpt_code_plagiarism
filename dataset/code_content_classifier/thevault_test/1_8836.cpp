bool inRect(Point p, Rect rect){
	bool result = false;
	if(p.x >= rect.x && p.x <= rect.x + rect.width && p.y >= rect.y && p.y <= rect.y + rect.height){
		result = true;
	}
	return result;
}