std::string CXStringToString (const CXString &str) {
		auto typeString = clang_getCString(str);
		std::string result;
		if (typeString) {
			result = typeString;
		}
		clang_disposeString(str);
		return result;
	}