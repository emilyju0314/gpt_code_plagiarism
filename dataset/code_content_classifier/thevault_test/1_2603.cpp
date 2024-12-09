void CVCardUtils::WriteTextValue(std::ostream& os, const cdstring& value)
{
	cdstring::size_type start_pos = 0;
	cdstring::size_type end_pos = value.find_first_of("\r\n;\\,", start_pos);
	cdstring::size_type size_pos = value.length();
	if (end_pos != cdstring::npos)
	{
		while(true)
		{
			// Write current segment
			os.write(value.c_str() + start_pos, end_pos - start_pos);

			// Write escape
			switch(value[end_pos])
			{
			case '\r':
				if (size_pos > end_pos + 1)
				{
					if (value[end_pos + 1] != '\n')
						os << "\\n";
				}
				else
					os << "\\n";
				break;
			case '\n':
				os << "\\n";
				break;
			case ';':
				os << "\\;";
				break;
			case '\\':
				os << "\\\\";
				break;
			case ',':
				os << "\\,";
				break;
			}

			// Bump past escapee and look for next segment
			start_pos = end_pos + 1;

			end_pos = value.find_first_of("\r\n;\\,", start_pos);
			if (end_pos == cdstring::npos)
			{
				os.write(value.c_str() + start_pos, size_pos - start_pos);
				break;
			}
		}
	}
	else
		os.write(value.c_str(), size_pos);
}