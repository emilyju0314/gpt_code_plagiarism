static U64 parseHexUnsignedInt(const char*& nextChar, ParseState* parseState, U64 maxValue)
{
	const char* firstHexit = nextChar;
	WAVM_ASSERT(nextChar[0] == '0' && (nextChar[1] == 'x' || nextChar[1] == 'X'));
	nextChar += 2;

	U64 result = 0;
	U8 hexit = 0;
	while(true)
	{
		if(*nextChar == '_')
		{
			++nextChar;
			continue;
		}
		if(!tryParseHexit(nextChar, hexit)) { break; }
		if(result > (maxValue - hexit) / 16)
		{
			parseErrorf(parseState, firstHexit, "integer literal is too large");
			result = maxValue;
			while(tryParseHexit(nextChar, hexit)) {};
			break;
		}
		WAVM_ASSERT(result * 16 + hexit >= result);
		result = result * 16 + hexit;
	}
	return result;
}