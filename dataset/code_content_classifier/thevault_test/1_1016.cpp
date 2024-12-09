void TetrisInterface::clearLines(){
	for (int i = 0; blockOverlay.linesPresent(); i++){
		blockOverlay.clearLowestLine();
		addToScore((i*i + 1)*BASE_LINE_CLEAR_SCORE);
		addToLinesCleared(1);
	}
}