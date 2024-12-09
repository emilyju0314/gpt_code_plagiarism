inline static bool isThread( DeclarationWithType * decl ) {
		Type * baseType = decl->get_type()->stripDeclarator();
		StructInstType * instType = dynamic_cast<StructInstType *>( baseType );
		if ( nullptr == instType ) { return false; }
		return instType->baseStruct->is_thread();
	}