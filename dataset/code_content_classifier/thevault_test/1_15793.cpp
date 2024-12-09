void resetGame() {
	hardMode = portalLevel == 8;
	fall_rate = hardMode ? 0.4 : 0.2;
	jump_rate = hardMode ? 1.2 : 1.0;
	currFrames = 0;
	xmLeftY = xmRightY = XM_START_Y;
	xmLeftX = hardMode ? XM1_HARD_X : XM1_X;
	xmRightX = hardMode ? XM2_HARD_X : XM2_X;
	obstacleLeftX = 32.0;
	obstacleRightX = 0;
	coordsSet.clear();
	currObstacles.clear();
	toDelete.clear();
	printf("Starting new game...\n");
}