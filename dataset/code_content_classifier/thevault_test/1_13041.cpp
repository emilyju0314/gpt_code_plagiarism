std::string GetToken( std::istream & stream ) {
		// ignore whitespace
		for( ; stream.peek( ) == 9 || stream.peek( ) == 10 || stream.peek( ) == 13 || stream.peek( ) == 32; stream.get( ) );

		int c = stream.peek( );
		if( c == -1 ) {
			// return blank token indicating end of stream
			return std::string( );
		} else if( c == '(' || c == ')' || c == ',' || c == ';' || c == '{' || c == '}' || c == '=' ) {
			// single character tokens
			return std::string( 1, (char)stream.get( ) );
		} else if( c >= '0' && c <= '9' || c == '-' || c == '+' ) {
			return GetNumber( stream );
		} else if( c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c == '_' ) {
			return GetIdentifier( stream );
		} else if( c == '"' ) {
			return GetStringConst( stream );
		} else if( c == '#' ) {
			return GetComment( stream );
		} else {
			throw TokenizerError( "unknown start of token: " + std::string( 1, (char)c ) );
		}
	}