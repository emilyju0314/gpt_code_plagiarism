void Idle(SceCtrlData *pad)
{
	while(true)
	{
		RedrawStatus();
		if(WaitForButtonTimeout(pad, 60)) break; //Stop looping when a button is pressed
	}
}