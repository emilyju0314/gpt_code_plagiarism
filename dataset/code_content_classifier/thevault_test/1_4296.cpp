bool isFtype( const Type * type ) {
	if ( dynamic_cast< const FunctionType * >( type ) ) {
		return true;
	} else if ( auto typeInst = dynamic_cast< const TypeInstType * >( type ) ) {
		return typeInst->kind == TypeDecl::Ftype;
	} else return false;
}