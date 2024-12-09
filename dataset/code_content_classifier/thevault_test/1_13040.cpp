std::string GetIdentifier( std::istream & stream ) {
		std::string ident;
		if( stream.peek( ) >= 'A' && stream.peek( ) <= 'Z' || stream.peek( ) >= 'a' && stream.peek( ) <= 'z' || stream.peek( ) == '_' ) {
			ident += stream.get( );
			for( ; stream.peek( ) >= 'A' && stream.peek( ) <= 'Z' || stream.peek( ) >= 'a' && stream.peek( ) <= 'z' || stream.peek( ) >= '0' && stream.peek( ) <= '9' || stream.peek( ) == '_'; ident += stream.get( ) );
		}
		return ident;
	}