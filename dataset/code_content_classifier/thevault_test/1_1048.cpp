HWND CreateStatusBar(HINSTANCE hinst, HWND hwndParent)
{
	HWND		hwnd;


	hwnd = CreateWindow(STATUSCLASSNAME,
					   "", 
					   WS_CHILD | WS_VISIBLE,
					   0,0,0,0,
					   hwndParent, NULL, hinst, NULL);
	if(hwnd == NULL) 
	{ 
		char	str[20];
		wsprintf(str, "%d", GetLastError());
//		dout(str); 
		return NULL;
	}

	InitStatusBar(hwndParent, hwnd);

	return hwnd;
}