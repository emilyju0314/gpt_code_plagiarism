int TetrisInterface::getTimeDelay(){
	if (level < 10){
		return ((19 - level)*BASE_TIME_DELAY) / 18;
	} else {
		return BASE_TIME_DELAY / 2;
	}
}