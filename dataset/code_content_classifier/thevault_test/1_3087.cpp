BOOL
QdInitializeGlobals()
{
	WCHAR SysDir[MAX_PATH];
	BOOL ReturnValue = FALSE;

	// TODO IMPORTANT don't disable redirection
#if !defined (_WIN64)
	//
	// Disable wow64 
	//

	BOOL Result = FALSE;
	BOOL Wow64Process = FALSE;
	PVOID OldWowRedirectionValue = NULL;

	Result = IsWow64Process(
		GetCurrentProcess(),
		&Wow64Process
		);
	if (Result == FALSE)
	{
		LOG_ERROR(L"IsWow64Process failed, last error 0x%x", GetLastError());
		goto Exit;
	}

	if (Wow64Process == TRUE)
	{
		//
		// Disable FS redirection to make sure a 32 bit test process will
		// copy our (64 bit) driver to system32\drivers rather than syswow64\drivers.
		//

		Result = Wow64DisableWow64FsRedirection(&OldWowRedirectionValue);
		if (Result == FALSE)
		{
			LOG_ERROR(L"Wow64DisableWow64FsRedirection failed, last error 0x%x", GetLastError());
			goto Exit;
		}
	}
#endif

	//
	// Open the service control manager if not already open
	//
	if (g_QdScmHandle == NULL) 
	{
		g_QdScmHandle = OpenSCManager(
			NULL,
			NULL,
			SC_MANAGER_ALL_ACCESS
			);

		if (g_QdScmHandle == NULL)
		{
			LOG_ERROR(L"OpenSCManager failed, last error 0x%x", GetLastError());
			goto Exit;
		}
	}

	//
	// Construct driver path g_TcDriverPath
	//
	UINT Size = GetSystemDirectory(SysDir, ARRAYSIZE(SysDir));
	if (Size == 0)
	{
		LOG_ERROR(L"GetSystemDirectory failed, last error 0x%x", GetLastError());
		goto Exit;
	}

	HRESULT hr = StringCchPrintf(
		g_QdDriverPath,
		ARRAYSIZE(g_QdDriverPath),
		L"%ls\\drivers\\%ls.sys",
		SysDir,
		QD_DRIVER_NAME
		);
	if (FAILED(hr))
	{
		LOG_ERROR(L"StringCchPrintf failed, hr 0x%08x", hr);
		goto Exit;
	}

	ReturnValue = TRUE;

Exit:
	return ReturnValue;
}