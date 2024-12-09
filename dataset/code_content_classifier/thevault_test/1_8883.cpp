void ShowFileList()
{
	SceCtrlData pad;
	std::list<cFile*>::iterator OldCurFileIter = CurFileIter;
	
	WaitForButtonRelease(&pad);
	pspDebugScreenClear();
	
	while(true)
	{
		pspDebugScreenSetXY(0, 0);
		pspDebugScreenSetTextColor(GREEN);
		printf("Open files (%u):\n", File.size());
		
		pspDebugScreenSetTextColor(WHITE);
		for(std::list<cFile*>::iterator i=File.begin(); i != File.end(); i++)
			printf("%c%s\n", (i == CurFileIter) ? '>' : ' ', (*i)->DispName);
			
		Idle(&pad);
		
		if(pad.Buttons & PSP_CTRL_UP) //Up: Move up
		{
			if(CurFileIter == File.begin()) CurFileIter = File.end();
			CurFileIter--;
		}
		else if(pad.Buttons & PSP_CTRL_DOWN) //Down: Move down
		{
			CurFileIter++;
			if(CurFileIter == File.end()) CurFileIter = File.begin();
		}
		else if(pad.Buttons & (PSP_CTRL_CIRCLE | PSP_CTRL_CROSS | PSP_CTRL_START)) //O, X, or Start: Accept
			break;
		else if(pad.Buttons & PSP_CTRL_SELECT) //Sel: Cancel
		{
			CurFileIter = OldCurFileIter;
			break;
		}
		Delay(10);
	}
	WaitForButtonRelease(&pad);
	CurFile = *CurFileIter;
}