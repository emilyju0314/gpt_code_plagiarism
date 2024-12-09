void TetrisInterface::resetDelayer(){
	if (isTimeToMove()){
		delayer.setReferenceTime(delayer.getReferenceTime() + getTimeDelay());
	} else {
		delayer.setReferenceTime(GetTickCount());
	}
}