int functionCast(
		const ast::Type * src, const ast::TypeEnvironment & env, const ast::SymbolTable & symtab
	) {
		return -1 * objectCast( src, env, symtab );
	}