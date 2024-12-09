TypeSubstitution * TypeSubstitution::newFromExpr( const Expr * expr, const TypeSubstitution * env ) {
	if ( env ) {
		TypeSubstitution * newEnv = new TypeSubstitution();
		Pass<EnvTrimmer> trimmer( env, newEnv );
		expr->accept( trimmer );
		return newEnv;
	}
	return nullptr;
}