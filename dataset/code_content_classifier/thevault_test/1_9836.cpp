ParserContext* parse (CXTranslationUnit tu, std::string &sdkPath, std::string &minVersion, bool excludeSys) {
		auto cursor = clang_getTranslationUnitCursor(tu);
		auto ctx = new ParserContext(sdkPath, minVersion, excludeSys);
		clang_visitChildren(cursor, begin, ctx);
		ClassDefinition::complete(ctx);
		return ctx;
	}