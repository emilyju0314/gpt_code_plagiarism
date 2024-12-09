HRESULT GetUserDefaultUILanguageLegacyCompat(LANGID* pLangid)
{
	HRESULT hr=E_FAIL;	
	if (pLangid == NULL) { return E_POINTER; }
	PFNGETUSERDEFAULTUILANGUAGE pfnGetUserDefaultUILanguage;	
	HINSTANCE hKernel32 = ::GetModuleHandle(_T("kernel32.dll"));
	pfnGetUserDefaultUILanguage = (PFNGETUSERDEFAULTUILANGUAGE)::GetProcAddress(hKernel32, "GetUserDefaultUILanguage");
	if(pfnGetUserDefaultUILanguage != NULL)
	{
		*pLangid = pfnGetUserDefaultUILanguage();
		hr = S_OK;
	}

	return hr;
}