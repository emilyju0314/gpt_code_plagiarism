std::string EncodingToType (const std::string &encoding_) {
		if (encoding_.empty()) {
			return "unknown";
		}
		std::string encoding = filterEncoding(encoding_);
		if (encoding == "i") {
			return "int";
		} else if (encoding == "l") {
			return "long";
		} else if (encoding == "c") {
			return "c";
		} else if (encoding == "d") {
			return "double";
		} else if (encoding == "f") {
			return "float";
		} else if (encoding == "s") {
			return "short";
		} else if (encoding == "q") {
			return "long long";
		} else if (encoding == "C") {
			return "unsigned char";
		} else if (encoding == "I") {
			return "unsigned int";
		} else if (encoding == "S") {
			return "unsigned short";
		} else if (encoding == "L") {
			return "unsigned long";
		} else if (encoding == "S") {
			return "unsigned short";
		} else if (encoding == "Q") {
			return "unsigned long long";
		} else if (encoding == "B") {
			return "bool";
		} else if (encoding == "v") {
			return "void";
		} else if (encoding == "*") {
			return "char *";
		} else if (encoding == "@") {
			return "id";
		} else if (encoding == "#") {
			return "Class";
		} else if (encoding == ":") {
			return "SEL";
		} else if (encoding == "@?") {
			return "block";
		}
		char ch = encoding.at(0);
		switch (ch) {
			case '{': {
				return "struct";
			}
			case '^': {
				return "pointer";
			}
			case '[': {
				return "constant_array";
			}
			case '(': {
				return "union";
			}
		}
//		std::cerr << "unknown encoding: " << encoding << std::endl;
		return "unknown";
	}