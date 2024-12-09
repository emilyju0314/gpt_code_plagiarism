bool checkCollision() {
	auto pair1 = make_pair(xmLeftX, (int) xmLeftY);
	auto pair2 = make_pair(xmRightX, (int) xmRightY);

	return coordsSet.find(pair1) != coordsSet.end() || coordsSet.find(pair2) != coordsSet.end();
}