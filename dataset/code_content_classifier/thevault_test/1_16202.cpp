unsigned int parsegrammar::lexer(LLTOKEN_CODE token)
	{
		terminal_token_pair pair(token, hash(lexeme));
		if (token_terminal_symbols.count(pair) > 0) {
			return token_terminal_symbols[pair];
		}
		terminal_token_pair pair_default(token, hash("default"));
		if (token_terminal_symbols.count(pair_default) > 0) {
			return token_terminal_symbols[pair_default];
		}
		switch (token) {
		case L_NUMBER_TOKEN:
		case L_WORD_TOKEN:
		case L_SPACE_TOKEN:
		case L_PUNCT_TOKEN:
			return 0;
		case L_END_OF_FILE:
			return eos_sym; // end of stack: the $ terminal symbol
		//case L_ERR_TOKEN:
		//	return TS_INVALID; // end of stack: the $ terminal symbol
		default:
			return 0; // no known terminal found
		}
	}