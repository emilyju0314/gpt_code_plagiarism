void findGlobalDecls( ast::TranslationUnit & translationUnit ) {
	ast::Pass<FindDeclsCore>::run( translationUnit, translationUnit.global );

	// TODO: When everything gets the globals from the translation unit,
	// remove these.
	ast::dereferenceOperator = translationUnit.global.dereference;
	ast::dtorStruct = translationUnit.global.dtorStruct;
	ast::dtorStructDestroy = translationUnit.global.dtorDestroy;

	// TODO: conditionally generate 'fake' declarations for missing features,
	// so that translation can proceed in the event that builtins, prelude,
	// etc. are missing.
}