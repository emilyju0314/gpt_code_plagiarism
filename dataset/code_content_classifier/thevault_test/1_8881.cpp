void ShowGoto()
{
	SceCtrlData pad;
	int Pos = 7;
	unsigned int Mask, Addr, OldAddr;
	
	OldAddr = CurFile->StartAddr;
	pspDebugScreenClear();
	while(true)
	{
		//Display cursor
		pspDebugScreenSetTextColor(WHITE);
		pspDebugScreenSetXY(7, 4);
		printf("        ");
		pspDebugScreenSetXY(7 + Pos, 4);
		printf("V\n");
		
		//Display address
		printf("  Goto %08X\n  Size %08X\n\n  O/X: Accept\n  Start: Cancel\n"
			"  Left/Right: Select\n  Up/Down: Adjust",
			CurFile->StartAddr, CurFile->Size);
		if(CurFile->StartAddr >= CurFile->Size)
		{
			pspDebugScreenSetXY(16, 5);
			pspDebugScreenSetTextColor(RED);
			printf("* Past EOF");
		}
		
		//Process buttons
		Idle(&pad);
		if(pad.Buttons & PSP_CTRL_LEFT) //Left: Move left
		{
			Pos--;
			if(Pos < 0) Pos = 7;
		}
		else if(pad.Buttons & PSP_CTRL_RIGHT) //Right: Move right
		{
			Pos++;
			if(Pos > 7) Pos = 0;
		}
		else if(pad.Buttons & PSP_CTRL_UP) //Up: Increment
		{
			Mask = 0xF0000000 >> (Pos * 4);
			Addr = (CurFile->StartAddr & Mask) >> ((7 - Pos) * 4);
			Addr = (Addr + 1) & 0xF;
			CurFile->StartAddr = (CurFile->StartAddr & ~Mask)
				| (Addr << ((7 - Pos) * 4));
		}
		else if(pad.Buttons & PSP_CTRL_DOWN) //Down: Decrement
		{
			Mask = 0xF0000000 >> (Pos * 4);
			Addr = (CurFile->StartAddr & Mask) >> ((7 - Pos) * 4);
			Addr = (Addr - 1) & 0xF;
			CurFile->StartAddr = (CurFile->StartAddr & ~Mask)
				| (Addr << ((7 - Pos) * 4));
		}
		else if(pad.Buttons & (PSP_CTRL_CIRCLE | PSP_CTRL_CROSS)) //O or X: Accept
		{
			if(CurFile->StartAddr < CurFile->Size)
			{
				WaitForButtonRelease(&pad);
				break;
			}
		}
		else if(pad.Buttons & PSP_CTRL_START) //Start: cancel
		{
			WaitForButtonRelease(&pad);
			CurFile->StartAddr = OldAddr;
			break;
		}
		
		Delay(5);
	}
	
	pspDebugScreenClear();
}