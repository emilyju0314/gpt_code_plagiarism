ST::string CleanOutControlCodesFromString(const ST::utf32_buffer& codepoints)
{
	ST::string buf;
	const char32_t* s = codepoints.c_str();
	for (;;)
	{
		switch (*s)
		{
			case TEXT_CODE_CENTER:
			case TEXT_CODE_NEWCOLOR:
			case TEXT_CODE_BOLD:
			case TEXT_CODE_DEFCOLOR:
				++s;
				if (*s == TEXT_SPACE)
					++s;
				break;

			case TEXT_CODE_NEWLINE:
				++s;
				break;

			case U'\0':
				return buf;

			default:
				buf += *s++;
				break;
		}
	}
}