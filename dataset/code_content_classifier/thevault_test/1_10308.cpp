void InitializeMSAA()
{
	if (g_hWinEventHook==NULL)
	{
		//DBGTRACE("GetArrayMin=0x%x  GetArrayMax=0x%x\n",GetArrayMin(g_arrWinEvents), GetArrayMax(g_arrWinEvents));
		g_hWinEventHook = SetWinEventHook(GetArrayMin(g_arrWinEvents),
										GetArrayMax(g_arrWinEvents), //EVENT_MIN, EVENT_MAX /*EVENT_SYSTEM_FOREGROUND, EVENT_SYSTEM_FOREGROUND*/,
											NULL,  // handle to DLL
											WinEventProcCallback,
											0, 0, // process and thread IDs of interest (0 = all)
											WINEVENT_OUTOFCONTEXT | WINEVENT_SKIPOWNPROCESS);
	}
}