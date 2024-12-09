void TetrisInterface::setPause(bool pause){
	paused = pause;
	if (!paused){
		delayer.setReferenceTime(delayer.getReferenceTime() + pauser.getCurrentTime());
		timer.setReferenceTime(timer.getReferenceTime() + pauser.getCurrentTime());
	} else {
		pauser.setReferenceTime(GetTickCount());
	}

}