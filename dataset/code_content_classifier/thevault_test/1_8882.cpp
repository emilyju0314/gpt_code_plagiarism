void ShowSearch()
{
	SceCtrlData pad;
	static u8 SearchByte[256];
	static u32 Pos = 0, NumBytes = 1;
	static bool Init = false;
	
	if(!Init)
	{
		memset(SearchByte, 0, sizeof(SearchByte));
		Init = true;
	}
	
	pspDebugScreenClear();
	while(true)
	{
		//Display cursor
		pspDebugScreenSetTextColor(WHITE);
		pspDebugScreenSetXY(7, 4);
		for(int i=0; i<25; i++) printf(" ");
		pspDebugScreenSetXY(7 + Pos, 4);
		printf("V\n");
		
		//Display string
		printf("  Find ");
		for(u32 i=0; i<NumBytes; i++)
			printf("%02X", SearchByte[i]);
		
		printf("\n  Text ");
		for(u32 i=0; i<NumBytes; i++)
			printf(" %c", ((SearchByte[i] >= 0x20) && (SearchByte[i] < 0x7F))
				? SearchByte[i] : '.');
		
		printf("\n\n  O/X: Accept\n  Start: Cancel\n"
			"  Left/Right: Select\n  Up/Down: Adjust\n"
			"  L/R: String length\n\n"
			"  Search range is current position (%08X) to EOF", EditAddr);
		
		//Process buttons
		Idle(&pad);
		
		if(pad.Buttons & PSP_CTRL_LEFT) //Left: Move left
		{
			Pos--;
			if((int)Pos < 0) Pos = (NumBytes * 2) - 1;
		}
		else if(pad.Buttons & PSP_CTRL_RIGHT) //Right: Move right
		{
			Pos++;
			if(Pos > ((NumBytes * 2) - 1)) Pos = 0;
		}
		else if(pad.Buttons & PSP_CTRL_UP) //Up: Increment
		{
			int i = Pos >> 1;
			u8 Mask = (Pos & 1) ? 0x0F : 0xF0, n = SearchByte[i] & Mask;
			n += (Pos & 1) ? 0x01 : 0x10;
			SearchByte[i] = (SearchByte[i] & ~Mask) | (n & Mask);
		}
		else if(pad.Buttons & PSP_CTRL_DOWN) //Down: Decrement
		{
			int i = Pos >> 1;
			u8 Mask = (Pos & 1) ? 0x0F : 0xF0, n = SearchByte[i] & Mask;
			n -= (Pos & 1) ? 0x01 : 0x10;
			SearchByte[i] = (SearchByte[i] & ~Mask) | (n & Mask);
		}
		else if(pad.Buttons & PSP_CTRL_LTRIGGER) //L: Reduce string length
		{
			if(NumBytes > 1) NumBytes--;
			if(Pos > ((NumBytes * 2) - 1)) Pos = (NumBytes * 2) - 1;
		}
		else if(pad.Buttons & PSP_CTRL_RTRIGGER) //R: Increase string length
		{
			if(NumBytes < sizeof(SearchByte)) NumBytes++;
		}
		else if(pad.Buttons & (PSP_CTRL_CIRCLE | PSP_CTRL_CROSS)) //O or X: Accept
		{
			WaitForButtonRelease(&pad);
			
			//Perform search
			u32 NumMatched = 0;
			u32 CurAddr = EditAddr;
			u32 MatchStart = 0;
			u32 BestMatch = 0, BestSize = 0;
			u32 PadReadCounter = 0;
			bool Cancelled = false;
			
			pspDebugScreenSetXY(2, 16);
			pspDebugScreenSetTextColor(GREEN);
			printf("Searching... (X: Cancel)");
			
			CurFile->SeekTo(CurAddr);
			while((NumMatched < NumBytes) && (CurAddr < CurFile->Size))
			{
				u8 Byte = CurFile->GetByte();
				
				if(Byte == SearchByte[NumMatched])
				{
					if(!NumMatched) MatchStart = CurAddr;
					NumMatched++;
					
					//Keep track of the best match so far
					if(NumMatched > BestSize)
					{
						BestMatch = MatchStart;
						BestSize = NumMatched;
					}
				}
				else NumMatched = 0;
				
				CurAddr++;
				
				//Read the buttons periodically to check for cancel
				PadReadCounter++;
				if(PadReadCounter == 32768)
				{
					PadReadCounter = 0;
					sceCtrlReadBufferPositive(&pad, 1);
					if(pad.Buttons & PSP_CTRL_CROSS)
					{
						Cancelled = true;
						break;
					}
				}
			}
			
			if(NumMatched == NumBytes) //got exact match
			{
				CurFile->StartAddr = MatchStart;
				EditAddr = MatchStart;
				break; //exit loop to return from function
			}
			else
			{
				pspDebugScreenSetXY(2, 16);
				pspDebugScreenSetTextColor(RED);
				if(Cancelled) printf("Search cancelled        \n");
				else printf("String not found        \n");
				pspDebugScreenSetTextColor(WHITE);
				printf("  Closest match: %u bytes at %08X",
					BestSize, BestMatch);
			}
			
			WaitForButtonRelease(&pad);
		}
		else if(pad.Buttons & PSP_CTRL_START) //Start: cancel
		{
			WaitForButtonRelease(&pad);
			Delay(5);
			pspDebugScreenClear();
			return;
		}
		
		Delay(5);
	}
	
	pspDebugScreenClear();
}