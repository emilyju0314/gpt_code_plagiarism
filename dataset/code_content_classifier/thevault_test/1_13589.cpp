int TestUnicodeCvt()
{
	wchar_t szInfo[140]; DWORD nWrite;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	// Some translations check
	{
		char chUtf8[] =
			"## "
			"\x41\xF0\x9D\x94\xB8\x41" // 'A', double-struck capital A as surrogate pair, 'A'
			" # "
			"\xE9\xE9\xE9"             // Invalid unicode translations
			" # "
			"\xE6\x96\x87\xE6\x9C\xAC" // Chinese '文' and '本'
			"\xEF\xBC\x8E"             // Fullwidth Full Stop
			" ##\r\n"
			;
		CpCvt cvt = {}; wchar_t wc; char* pch = chUtf8;
		cvt.SetCP(65001);

		msprintf(szInfo, countof(szInfo),
			L"CVT test: CP=%u Max=%u Def=%c: ",
			cvt.CP.CodePage, cvt.CP.MaxCharSize, cvt.CP.UnicodeDefaultChar
			);
		WriteConsoleW(hOut, szInfo, lstrlen(szInfo), &nWrite, NULL);

		while (*pch)
		{
			switch (cvt.Convert(*(pch++), wc))
			{
			case ccr_OK:
			case ccr_BadUnicode:
				WriteConsoleW(hOut, &wc, 1, &nWrite, NULL);
				break;
			case ccr_Surrogate:
			case ccr_BadTail:
			case ccr_DoubleBad:
				WriteConsoleW(hOut, &wc, 1, &nWrite, NULL);
				cvt.GetTail(wc);
				WriteConsoleW(hOut, &wc, 1, &nWrite, NULL);
				break;
			}
		}
	}

	return 0;
}