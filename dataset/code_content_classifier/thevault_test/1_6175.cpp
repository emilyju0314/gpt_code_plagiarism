int
Connect2Port()

	{

	outCommandPort.Register("/TestGUI/out/command");
	inPositionPort.Register("/TestGUI/in/position");
	return 1;

	}