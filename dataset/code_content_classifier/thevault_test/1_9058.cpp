string QueryParser::getNumeric(SPARQLParser::NumericLiteralContext *ctx)
{
	int numType = -1;	// 0 for integer, 1 for decimal, 2 for double
	string ret, baseText = ctx->getText();
	
	if (ctx->numericLiteralUnsigned())
	{
		if (ctx->numericLiteralUnsigned()->num_integer())
			numType = 0;
		else if (ctx->numericLiteralUnsigned()->num_decimal())
			numType = 1;
		else if (ctx->numericLiteralUnsigned()->num_double())
			numType = 2;
	}
	else if (ctx->numericLiteralPositive())
	{
		if (ctx->numericLiteralPositive()->integer_positive())
			numType = 0;
		else if (ctx->numericLiteralPositive()->decimal_positive())
			numType = 1;
		else if (ctx->numericLiteralPositive()->double_positive())
			numType = 2;
	}
	else if (ctx->numericLiteralNegative())
	{
		if (ctx->numericLiteralNegative()->integer_negative())
			numType = 0;
		else if (ctx->numericLiteralNegative()->decimal_negative())
			numType = 1;
		else if (ctx->numericLiteralNegative()->double_negative())
			numType = 2;
	}
	switch (numType)
	{
		case 0:
		{
			long long ll;
			bool succ = 1;
			try
			{
				ll = stoll(baseText);
			}
			catch (invalid_argument &e)
			{
				succ = 0;
				throw "[ERROR] xsd:integer value invalid.";
			}
			catch (out_of_range &e)
			{
				succ = 0;
				throw "[ERROR] xsd:integer out of range.";
			}
			if (succ)
				ret = "\"" + baseText + "\"" + "^^<http://www.w3.org/2001/XMLSchema#integer>";
			break;
		}

		case 1:
		ret = "\"" + baseText + "\"" + "^^<http://www.w3.org/2001/XMLSchema#decimal>";
		break;

		case 2:
		ret = "\"" + baseText + "\"" + "^^<http://www.w3.org/2001/XMLSchema#double>";
		break;
	}

	return ret;
}