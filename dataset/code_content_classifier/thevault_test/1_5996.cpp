void PaintWindow(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc;
	int lCount;
	TCHAR szOut[200]; //
	long iCurrentX =0;
	long iCurrentY=0;
	INT cy,cx;
	RECT rect,rectCli;
	double dTime;
	int iTime;

	// get the device context
	hdc = BeginPaint(hWnd, &ps);
	
	// clear the back ground by drawing a rectangle
	GetClientRect(hWnd, &rectCli);	
	Rectangle(hdc, rectCli.left,rectCli.top, rectCli.right, rectCli.bottom);

	// Get the height and length of the string
	DrawText (hdc, TEXT ("XX"),  -1, &rect, 
				  DT_CALCRECT | DT_CENTER | DT_SINGLELINE);
	// determine the height of the characters
	cy = rect.bottom - rect.top + 3;

	// report how many messages and errors were read
	wsprintf (szOut,TEXT("Messages Read: %d    Errors Read: %d"),mNumberOfMessagesRead,mNumberOfErrorsRead);
	ExtTextOut(hdc,0,0,0,0,szOut, _tcslen(szOut),0); // write our string to the display

	// draw each message to the window
	for (lCount=0;lCount <mNumberOfMessagesRead;lCount++)
	{
		// Calculate the time for this message
		dTime = ((double) stMessages[lCount].TimeHardware2) * NEOVI_TIMESTAMP_2 + 
							((double) stMessages[lCount].TimeHardware) * NEOVI_TIMESTAMP_1;
		dTime *= 1000;				// convert to milli-seconds
		iTime = (int) dTime;		// conever to an integer

		iCurrentY += cy;	// increment the position
		// is the current message a CAN message
		if (stMessages[lCount].Protocol == SPY_PROTOCOL_CAN)
		{
			// copy a can style message
			wsprintf (szOut,TEXT("Time (ms) %d Message %d Network %d ArbID %X Data Length: %d b1: %X b2: %X b3: %X b4: %X b5: %X b6: %X b7: %X b8: %X") 
				,iTime,lCount,stMessages[lCount].NetworkID,stMessages[lCount].ArbIDOrHeader,
				stMessages[lCount].NumberBytesData,
				stMessages[lCount].Data[0],
				stMessages[lCount].Data[1],
				stMessages[lCount].Data[2],
				stMessages[lCount].Data[3],
				stMessages[lCount].Data[4],
				stMessages[lCount].Data[5],
				stMessages[lCount].Data[6],
				stMessages[lCount].Data[7]);
		}
		else
		{
				wsprintf (szOut,TEXT("Time (ms) %d Message %d Network %d Data Length: %d b1: %X b2: %X b3: %X b4: %X b5: %X b6: %X b7: %X b8: %X b9: %X b10: %X b11: %X") 
				,iTime,lCount,stMessages[lCount].NetworkID,
				stMessages[lCount].NumberBytesData + stMessages[lCount].NumberBytesHeader,
				((icsSpyMessageJ1850 *) stMessages)[lCount].Header[0], // type cast to a icsSpyMessageJ1850 type message to get to the header
				((icsSpyMessageJ1850 *) stMessages)[lCount].Header[1],
				((icsSpyMessageJ1850 *) stMessages)[lCount].Header[2],
				stMessages[lCount].Data[0],
				stMessages[lCount].Data[1],
				stMessages[lCount].Data[2],
				stMessages[lCount].Data[3],
				stMessages[lCount].Data[4],
				stMessages[lCount].Data[5],
				stMessages[lCount].Data[6],
				stMessages[lCount].Data[7]);

		}
		ExtTextOut(hdc,iCurrentX,iCurrentY,0,0,szOut, _tcslen(szOut),0); // write our string to the display
	}

	// call the endpaint routine
	EndPaint(hWnd, &ps);
}