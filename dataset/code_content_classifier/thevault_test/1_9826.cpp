std::string cleanString (const std::string &str) {
		auto s = replace(str, "_Nonnull", "");
		s = replace(s, "_Nullable", "");
		s = replace(s, "__restrict", "");
		s = replace(s, " *restrict", " *");
		s = replace(s, " restrict", "");
		s = replace(s, "volatile", "");
		s = replace(s, "  ,", " ,");
		s = replace(s, " *  *", " **");
		s = replace(s, " *  ", " *");
		s = replace(s, "(^ )", "(^)");
		s = replace(s, " , ", ", ");
		s = replace(s, " )", ")");
		s = replace(s, "__kindof", "");
		s = replace(s, " const", "");
		s = replace(s, "const ", "");
		s = replace(s, "_Null_unspecified", "");
		return trim(s);
	}