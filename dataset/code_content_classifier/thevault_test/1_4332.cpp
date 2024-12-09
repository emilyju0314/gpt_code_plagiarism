int objectCast(
		const ast::Type * src, const ast::TypeEnvironment & env, const ast::SymbolTable & symtab
	) {
		if ( dynamic_cast< const ast::FunctionType * >( src ) ) {
			return -1;
		} else if ( auto inst = dynamic_cast< const ast::TypeInstType * >( src ) ) {
			if ( const ast::NamedTypeDecl * named = symtab.lookupType( inst->name ) ) {
				if ( auto tyDecl = dynamic_cast< const ast::TypeDecl * >( named ) ) {
					if ( tyDecl->kind == ast::TypeDecl::Ftype ) {
						return -1;
					}
				}
			} else if ( const ast::EqvClass * eqvClass = env.lookup( *inst ) ) {
				if ( eqvClass->data.kind == ast::TypeDecl::Ftype ) {
					return -1;
				}
			}
		}

		return 1;
	}