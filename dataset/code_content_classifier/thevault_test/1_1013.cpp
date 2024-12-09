void TetrisInterface::draw(Tetrimino* current, Tetrimino* typeSource){
	draw();
	Tetrimino* tempTetrimino = typeSource->clone();
	tempTetrimino->setY(BLOCK_LENGTH);
	switch (tempTetrimino->getType()){
	case I_TETRIMINO:
		tempTetrimino->setX(BLOCK_GRID_WIDTH + (WIDTH - BLOCK_GRID_WIDTH) / 2 - BLOCK_LENGTH / 2);
		break;
	case J_TETRIMINO:
		tempTetrimino->setX(BLOCK_GRID_WIDTH + (WIDTH - BLOCK_GRID_WIDTH) / 2);
		break;
	case L_TETRIMINO:
		tempTetrimino->setX(BLOCK_GRID_WIDTH + (WIDTH - BLOCK_GRID_WIDTH) / 2 - BLOCK_LENGTH);
		break;
	case O_TETRIMINO:
		tempTetrimino->setX(BLOCK_GRID_WIDTH + (WIDTH - BLOCK_GRID_WIDTH) / 2);
		break;
	case S_TETRIMINO:
		tempTetrimino->setX(BLOCK_GRID_WIDTH + (WIDTH - BLOCK_GRID_WIDTH) / 2 + BLOCK_LENGTH / 2);
		break;
	case T_TETRIMINO:
		tempTetrimino->setX(BLOCK_GRID_WIDTH + (WIDTH - BLOCK_GRID_WIDTH) / 2 - BLOCK_LENGTH / 2);
		break;
	case Z_TETRIMINO:
		tempTetrimino->setX(BLOCK_GRID_WIDTH + (WIDTH - BLOCK_GRID_WIDTH) / 2 - 3 * BLOCK_LENGTH / 2);
		break;
	default:
		break;
	}
	for (int i = 0; i < tempTetrimino->getBlockCount(); i++){
		sf::RectangleShape block = tempTetrimino->getBlock(i).asRectangleShape();
		mainWindow.draw(block);
	}
	delete tempTetrimino;
	for (int i = 0; i < current->getBlockCount(); i++){
		sf::RectangleShape block = current->getBlock(i).asRectangleShape();
		mainWindow.draw(block);
	}
}