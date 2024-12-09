std::string GetNumber( std::istream & stream ) {
		std::string number;
		if( stream.peek( ) >= '0' && stream.peek( ) <= '9' || stream.peek( ) == '-' || stream.peek( ) == '+' ) {
			number += stream.get( );
			for( ; stream.peek( ) >= '0' && stream.peek( ) <= '9' || stream.peek( ) == '.'; number += stream.get( ) );
		}
		return number;
	}