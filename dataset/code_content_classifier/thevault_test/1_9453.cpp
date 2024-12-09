static U64 parseDecimalUnsignedInt(const char*& nextChar,
								   ParseState* parseState,
								   U64 maxValue,
								   const char* context)
{
	U64 result = 0;
	const char* firstDigit = nextChar;
	while(true)
	{
		if(*nextChar == '_')
		{
			++nextChar;
			continue;
		}
		if(*nextChar < '0' || *nextChar > '9') { break; }

		const U8 digit = *nextChar - '0';
		++nextChar;

		if(result > U64(maxValue - digit) / 10)
		{
			parseErrorf(parseState, firstDigit, "%s is too large", context);
			result = maxValue;
			while((*nextChar >= '0' && *nextChar <= '9') || *nextChar == '_') { ++nextChar; };
			break;
		}
		WAVM_ASSERT(result * 10 + digit >= result);
		result = result * 10 + digit;
	};
	return result;
}