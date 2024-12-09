void idleCallback(void) {
	switch (getStage()) {
	case RUNNING:
		RunningIdle();
		break;
	}
	stage = 3;
}