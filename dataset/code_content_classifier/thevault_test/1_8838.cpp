int inBox(int index, vector<Rect> rectangles) {
	int result = -1;
	Rect current = rectangles[index];
	unsigned int i = 0;

	for (i = 0; i < rectangles.size(); i++) {
		if (i != index) {
			for (int j = 0; j < 4; j++) {
				int x, y;


				if (inRect(Point(current.x, current.y), rectangles[i]) &&
						inRect(Point(current.x + current.width, current.y ), rectangles[i]) &&
						inRect(Point(current.x, current.y + current.height), rectangles[i]) &&
						inRect(Point(current.x + current.width, current.y + current.height), rectangles[i])) {
					result = i;
					break;
				}
			}
		}
	}

	return result;
}