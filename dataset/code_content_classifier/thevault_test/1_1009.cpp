void TetrisInterface::clear(){
	score = 0;
	linesCleared = 0;
	level = 1;
	playing = true;
	blockOverlay.clear();
	delayer.setReferenceTime(GetTickCount());
	timer.setReferenceTime(GetTickCount());
}