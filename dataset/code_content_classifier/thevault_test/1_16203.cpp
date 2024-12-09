void parsegrammar::accept(LLTOKEN_CODE accept_token)
	{
		if (code == accept_token) {
			get_token();
		}
		else {
			std::cout << "accept: Expecting " << token_desc(accept_token) << " on line " << on_line << " " << on_col << ". \n";
		}
	}