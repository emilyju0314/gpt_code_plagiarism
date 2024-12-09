std::string fmtToString(const char * fmt, va_list ap) {
		int size = 128;
		while ( true ) {
			char buf[size];
			va_list args;
			va_copy( args, ap );
			int n = vsnprintf(&buf[0], size, fmt, args);
			va_end( args );
			if ( n < size && n >= 0 ) return buf;
			size *= 2;
		}
		assert( false );
	}