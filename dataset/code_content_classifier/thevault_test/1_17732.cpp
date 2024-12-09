int initHardware(struct Container *container, struct Args *args)
{
	if (args->debugEnabled)
		std::cout << "Setting up WiringPi..." << std::endl;

	if (wiringPiSetup())
	{
		std::cout << "Failed to set up WiringPi." << std::endl;
		return -1;
	}

	if (midiIOSetup(container, args))
	{
		std::cout << "Failed to set up MIDI I/O." << std::endl;
		return -1;
	}

	if (radioSetup(container, args))
	{
		std::cout << "Failed to set up radio transceiver." << std::endl;
		return -1;
	}

	if (keypadSetup(container, args))
	{
		std::cout << "Failed to set up keypad." << std::endl;
		return -1;
	}

	return 0;
}