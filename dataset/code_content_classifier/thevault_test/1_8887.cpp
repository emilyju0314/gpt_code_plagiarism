bool WaitForButtonTimeout(SceCtrlData *pad, int Timeout)
{
	for(; Timeout > 0; Timeout--)
	{
		sceDisplayWaitVblankStart();
		sceCtrlReadBufferPositive(pad, 1);
		if((pad->Buttons & ALL_USER_BUTTONS)
		|| (pad->Lx < (128 - AnalogDeadZone))
		|| (pad->Lx > (128 + AnalogDeadZone))
		|| (pad->Ly < (128 - AnalogDeadZone))
		|| (pad->Ly > (128 + AnalogDeadZone))) return true;
	}
	return false;
}