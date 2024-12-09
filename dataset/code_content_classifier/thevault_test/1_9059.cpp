string QueryParser::getTextWithRange(antlr4::tree::ParseTree *ctx)
{
	string ret, baseText = ctx->getText();
	long long ll;
	if (baseText[0] == '"' && baseText.find("^^<http://www.w3.org/2001/XMLSchema#integer>") != string::npos)
	{
		string val = baseText.substr(1, baseText.find("^^<http://www.w3.org/2001/XMLSchema#integer>") - 2);
		try
		{
			ll = stoll(val);
		}
		catch (invalid_argument &e)
		{
			throw "[ERROR] xsd:integer value invalid.";
		}
		catch (out_of_range &e)
		{
			throw "[ERROR] xsd:integer out of range.";
		}
	}
	else if (baseText[0] == '"' && baseText.find("^^<http://www.w3.org/2001/XMLSchema#long>") != string::npos)
	{
		string val = baseText.substr(1, baseText.find("^^<http://www.w3.org/2001/XMLSchema#long>") - 2);
		try
		{
			ll = stoll(val);
		}
		catch (invalid_argument &e)
		{
			throw "[ERROR] xsd:long value invalid.";
		}
		catch (out_of_range &e)
		{
			throw "[ERROR] xsd:long out of range.";
		}
	}
	else if (baseText[0] == '"' && baseText.find("^^<http://www.w3.org/2001/XMLSchema#int>") != string::npos)
	{
		string val = baseText.substr(1, baseText.find("^^<http://www.w3.org/2001/XMLSchema#int>") - 2);
		bool succ = 1;
		try
		{
			ll = stoll(val);
		}
		catch (invalid_argument &e)
		{
			succ = 0;
			throw "[ERROR] xsd:int value invalid.";
		}
		catch (out_of_range &e)
		{
			succ = 0;
			throw "[ERROR] xsd:int out of range.";
		}
		if (succ && (ll < (long long)INT_MIN || ll > (long long)INT_MAX))
			throw "[ERROR] xsd:int out of range.";
	}
	else if (baseText[0] == '"' && baseText.find("^^<http://www.w3.org/2001/XMLSchema#short>") != string::npos)
	{
		string val = baseText.substr(1, baseText.find("^^<http://www.w3.org/2001/XMLSchema#short>") - 2);
		bool succ = 1;
		try
		{
			ll = stoll(val);
		}
		catch (invalid_argument &e)
		{
			succ = 0;
			throw "[ERROR] xsd:short value invalid.";
		}
		catch (out_of_range &e)
		{
			succ = 0;
			throw "[ERROR] xsd:short out of range.";
		}
		if (succ && (ll < (long long)SHRT_MIN || ll > (long long)SHRT_MAX))
			throw "[ERROR] xsd:short out of range.";
	}
	else if (baseText[0] == '"' && baseText.find("^^<http://www.w3.org/2001/XMLSchema#byte>") != string::npos)
	{
		string val = baseText.substr(1, baseText.find("^^<http://www.w3.org/2001/XMLSchema#byte>") - 2);
		bool succ = 1;
		try
		{
			ll = stoll(val);
		}
		catch (invalid_argument &e)
		{
			succ = 0;
			throw "[ERROR] xsd:byte value invalid.";
		}
		catch (out_of_range &e)
		{
			succ = 0;
			throw "[ERROR] xsd:byte out of range.";
		}
		if (succ && (ll < (long long)SCHAR_MIN || ll > (long long)SCHAR_MAX))	// signed char
			throw "[ERROR] xsd:byte out of range.";
	}
	else if (baseText[0] == '"' && baseText.find("^^<http://www.w3.org/2001/XMLSchema#float>") != string::npos
		|| baseText[0] == '"' && baseText.find("^^<http://www.w3.org/2001/XMLSchema#double>") != string::npos)
	{
		if (baseText.substr(1, 3) == "NaN")
			throw "[ERROR] NaN for xsd:float or xsd:double.";
	}

	ret = baseText;
	return ret;
}