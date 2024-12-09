HRESULT CheckFileDiff(LPCTSTR szSrcPath, LPCTSTR szDestPath)
{
	CAtlFile fSrc, fDest;
	HRESULT hr = E_FAIL;

	if (S_OK == fSrc.Create(szSrcPath, GENERIC_READ, 0, OPEN_EXISTING))
	{
		if (S_OK == fDest.Create(szDestPath, GENERIC_READ, 0, OPEN_EXISTING))
		{
			ULONGLONG lenSrc=0,lenDest=0;
			if (S_OK == fSrc.GetSize(lenSrc) && 
				S_OK == fDest.GetSize(lenDest))
			{
				if (lenSrc != lenDest)
					hr = S_FALSE;
				else
				{
					if (lenSrc > ULONG_MAX ||
						lenDest > ULONG_MAX)
					{
						hr = E_FAIL;
					}
					else
					{
						if (lenSrc > ULONG_MAX || 
							lenDest > ULONG_MAX)
							hr = E_FAIL;
						else
						{
							CHeapPtr<BYTE> pBuffSrc;
							CHeapPtr<BYTE> pBuffDest;
							hr = S_OK;
							if (!pBuffSrc.Allocate((DWORD)lenSrc))
								hr = S_FALSE;
							if (hr == S_OK && !pBuffDest.Allocate((DWORD)lenDest))
								hr = S_FALSE;
							if (hr == S_OK && S_OK != fSrc.Read((LPVOID)(BYTE*)pBuffSrc, (DWORD)lenSrc))
								hr = S_FALSE;
							if (hr == S_OK && S_OK != fDest.Read((LPVOID)(BYTE*)pBuffDest, (DWORD)lenDest))
								hr = S_FALSE;
							if (hr == S_OK)
								hr = memcmp((LPVOID)(BYTE*)pBuffSrc, (LPVOID)(BYTE*)pBuffDest, (DWORD)lenDest) != 0 ? S_FALSE : S_OK;
						}
					}

				}
			}
		}
		else
			hr = S_FALSE; // dest doesn't exist
	}
	else
	{
		CString strFormat;
		DWORD dwLast = GetLastError();
		if (dwLast == ERROR_FILE_NOT_FOUND &&
		    strFormat.LoadString(IDS_WARN_SOURCE_NOT_EXIST))
		{
			CString strMsg;
			strMsg.Format(strFormat, szSrcPath);
			PrintWarningFormatted(strMsg);
		}
		else
		{
			if (strFormat.LoadString(IDS_WARN_SOURCE_ACCESS_ERROR))
			{
				CString strMsg;
				strMsg.Format(strFormat, dwLast);
				PrintWarningFormatted(strMsg);
			}
			
		}
	}
	return hr;
}