bool ShowSavePrompt(cFile *File)
{
	SceCtrlData Pad;
	bool Ret = true;
	
	if(File->Saved) return true;
	WaitForButtonRelease(&Pad);
	pspDebugScreenClear();
	pspDebugScreenSetXY(0, 0);
	pspDebugScreenSetTextColor(YELLOW);
	printf("Save changes to\n%s?\nO or X: Yes\nTriangle: No\nSquare: Cancel\n",
		File->DispName);
	
	while(!(Pad.Buttons &
		(PSP_CTRL_CROSS | PSP_CTRL_CIRCLE | PSP_CTRL_TRIANGLE | PSP_CTRL_SQUARE)))
		Idle(&Pad);
	
	if(Pad.Buttons & (PSP_CTRL_CROSS | PSP_CTRL_CIRCLE))
	{
		pspDebugScreenSetXY(0, 6);
		pspDebugScreenSetTextColor(GREEN);
		printf("Wrote %u bytes.\n", File->Save());
	}
	else if(Pad.Buttons & PSP_CTRL_SQUARE) Ret = false;
	
	WaitForButtonRelease(&Pad);
	Delay(30);
	pspDebugScreenClear();
	return Ret;
}