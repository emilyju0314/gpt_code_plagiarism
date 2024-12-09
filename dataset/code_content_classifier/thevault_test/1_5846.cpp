String_view(const char* string) noexcept
	{
		_string = string;
		_length = std::char_traits<char>::length(string);
	}