void flattenList( std::list< DeclarationWithType * > src, std::list< DeclarationWithType * > & dst, TypeEnvironment & env ) {
		dst.clear();
		for ( DeclarationWithType * dcl : src ) {
			PassVisitor<TtypeExpander_old> expander( env );
			dcl->acceptMutator( expander );
			std::list< Type * > types;
			flatten( dcl->get_type(), back_inserter( types ) );
			for ( Type * t : types ) {
				// outermost const, volatile, _Atomic qualifiers in parameters should not play a role in the unification of function types, since they do not determine whether a function is callable.
				// Note: MUST consider at least mutex qualifier, since functions can be overloaded on outermost mutex and a mutex function has different requirements than a non-mutex function.
				t->get_qualifiers() -= Type::Qualifiers(Type::Const | Type::Volatile | Type::Atomic);

				dst.push_back( new ObjectDecl( "", Type::StorageClasses(), LinkageSpec::C, nullptr, t, nullptr ) );
			}
			delete dcl;
		}
	}