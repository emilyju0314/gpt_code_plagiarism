TetrisInterface::TetrisInterface(int time){
	score = 0;
	linesCleared = 0;
	level = 1;
	timer = Timer(time);
	delayer = Timer(time);
	pauser = Timer(time);
	playing = true;
	gameOver = false;
	paused = false;
	blockOverlay = BlockOverlay();
	mainWindow.create(sf::VideoMode(WIDTH, HEIGHT), "Tetris");
	mainWindow.clear(BACKGROUND_COLOR);
}