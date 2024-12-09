std::string structDefinitionToEncoding (StructDefinition *def) {
		std::stringstream str;
		//example: {CATransform3D=dddddddddddddddd}
		str << "{" << def->getName() << "=";
		auto fields = def->getFields();
		for (auto it = fields.begin(); it != fields.end(); it++) {
			auto arg = *it;
			auto type = arg->getType();
			if (type) {
				str << CXTypeUnknownToEncoding(def->getContext(), type);
//				str << type->getEncoding();
			}
		}
		str << "}";
		return filterEncoding(str.str());
	}