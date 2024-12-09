BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   RECT windowRect{};
   windowRect.right = 640;
   windowRect.bottom = 448;
   AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, FALSE);

   hMainWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, windowRect.right - windowRect.left, windowRect.bottom - windowRect.top, NULL, NULL, hInstance, NULL);

   if (!hMainWnd)
   {
	   return FALSE;
   }

   ShowWindow(hMainWnd, nCmdShow);
   UpdateWindow(hMainWnd);

   // Create DirectDraw and its objects
   DirectDrawInit();
   graphicsLoaded = true;

   return TRUE;
}