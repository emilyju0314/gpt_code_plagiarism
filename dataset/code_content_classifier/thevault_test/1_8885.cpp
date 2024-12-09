void WaitForButton(SceCtrlData *pad)
{
	do {
		sceDisplayWaitVblankStart();
		sceCtrlReadBufferPositive(pad, 1);
	} while(!(pad->Buttons & ALL_USER_BUTTONS)
		&& (pad->Lx > (128 - AnalogDeadZone))
		&& (pad->Lx < (128 + AnalogDeadZone))
		&& (pad->Ly > (128 - AnalogDeadZone))
		&& (pad->Ly < (128 + AnalogDeadZone)));
}