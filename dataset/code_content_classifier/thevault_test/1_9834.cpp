void addBlockIfFound (Definition *definition, CXCursor cursor, CXCursor parent) {
		if (isBlock(cursor)) {
			auto context = definition->getContext();
			auto blockDef = new BlockDefinition(cursor, context);
			blockDef->parse(cursor, parent, context);
		}
	}