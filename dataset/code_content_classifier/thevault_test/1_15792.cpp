bool updateGame() {
	xmLeftY += fall_rate; //Move down players every 1/3 a second
	xmRightY += fall_rate;
	currFrames++;

	//Determine if a new glyph should spawn, then spawn one for each matrix
	if(currFrames % SPAWN_THRESHOLD == 1) {
		printf("Creating glyphs...\n");
		int rand_x = rand() % 12, rand_idx = rand() % 8;
		currObstacles.push_back(Glyph(make_pair(rand_x, COLS), allGlyphs[rand_idx], GLYPH_LENGTHS[rand_idx], true));
		currObstacles.push_back(Glyph(make_pair(rand_x, COLS), allGlyphs[rand_idx], GLYPH_LENGTHS[rand_idx], false));
	}

	//Update all existing glyphs. If a glyph should disappear, queue its index
	for(size_t i = 0; i < currObstacles.size(); i++) {
		Glyph temp = currObstacles[i];
		if(temp.getOrigin().second + temp.getLength() < 0) {
			toDelete.push_back(i);
			printf("Destroying glyph...\n");
		} else
			currObstacles[i].updateOrigin();
	}

	for(int i : toDelete)
		currObstacles.erase(currObstacles.begin() + i);
	toDelete.clear();

	//Update the coordinate set
	coordsSet.clear();
	for(Glyph g : currObstacles)
		for(auto pair : g.getData())
			coordsSet.insert(make_pair(pair.second + g.getOrigin().second, pair.first + g.getOrigin().first));

	return checkCollision() || xmLeftY >= ROWS || xmRightY >= ROWS || xmLeftY < 0.0 || xmRightY < 0.0;
}