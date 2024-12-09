bool YabInterface::QuitRequested()
{
	//exiting = true;
	//return false;
	exiting = true;
	ExitRequested();
	snooze(20000);
	return true;
}