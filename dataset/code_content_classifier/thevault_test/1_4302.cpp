AssnCandidate(
			const ast::SymbolTable::IdData c, const ast::Type * at, ast::TypeEnvironment && e,
			ast::AssertionSet && h, ast::AssertionSet && n, ast::OpenVarSet && o, ast::UniqueId rs )
		: cdata( c ), adjType( at ), env( std::move( e ) ), have( std::move( h ) ),
		  need( std::move( n ) ), open( std::move( o ) ), resnSlot( rs ) {}