bool CVCardLocale::UseDDMMDate()
{
	static bool _init_done_date = false;
	
	if (!_init_done_date)
	{
#if __dest_os == __mac_os || __dest_os == __mac_os_x
#if defined(__MULBERRY) || defined(__MULBERRY_CONFIGURE)
		// Get current locale
		CFLocaleRef locale = ::CFLocaleCopyCurrent();
		if (locale != NULL)
		{
			// Get formatter for current locale
			CFDateFormatterRef formatter = ::CFDateFormatterCreate(kCFAllocatorDefault, locale, kCFDateFormatterShortStyle, kCFDateFormatterShortStyle);
			if (formatter != NULL)
			{
				CFStringRef format = ::CFDateFormatterGetFormat(formatter);
				if (format != NULL)
				{
					// Look for specific characters in string
					sDDMMDate = ::CFStringHasPrefix(format, CFSTR("d"));
				}
				
				::CFRelease(formatter);
			}
			::CFRelease(locale);
		}
#endif
#elif __dest_os == __win32_os
		TCHAR buffer[256];
		::GetLocaleInfo(LOCALE_USER_DEFAULT, LOCALE_IDATE, buffer, 256);
#ifdef _UNICODE
		sDDMMDate = (::wcschr(buffer, '1') != 0);
#endif
#else
		time_t now = ::time(NULL);
		struct tm* now_tm = ::localtime(&now);
		now_tm->tm_mon = 0;
		now_tm->tm_mday = 31;
		cdstring result;
		result.reserve(256);
		::strftime(result.c_str_mod(), 256, "%x", now_tm);

		// If first character is a digit assuming day is first in this lcoale
		sDDMMDate = (result[0UL] == '3');
#endif

		_init_done_date = true;
	}
	
	return sDDMMDate;
}