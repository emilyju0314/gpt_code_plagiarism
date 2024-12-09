int Options::define(const string& aDefinition) {
	Option_register* definitionEntry = NULL;

	// Error if definition string doesn't contain an equals sign
	auto location = aDefinition.find("=");
	if (location == string::npos) {
		m_error << "Error: no \"=\" in option definition: " << aDefinition << endl;
		return -1;
	}

	string aliases = aDefinition.substr(0, location);
	string rest    = aDefinition.substr(location+1);
	string otype   = rest;
	string ovalue  = "";

	location = rest.find(":");
	if (location != string::npos) {
		otype  = rest.substr(0, location);
		ovalue = rest.substr(location+1);
	}

	// Remove anyspaces in the option type field
	otype.erase(remove_if(otype.begin(), otype.end(), ::isspace), otype.end());

	// Option types are only a single charater (b, i, d, c or s)
	if (otype.size() != 1) {
		m_error << "Error: option type is invalid: " << otype
			  << " in option definition: " << aDefinition << endl;
		return -1;
	}

	// Check to make sure that the type is known
	if (otype[0] != OPTION_STRING_TYPE  &&
		 otype[0] != OPTION_INT_TYPE     &&
		 otype[0] != OPTION_FLOAT_TYPE   &&
		 otype[0] != OPTION_DOUBLE_TYPE  &&
		 otype[0] != OPTION_BOOLEAN_TYPE &&
		 otype[0] != OPTION_CHAR_TYPE ) {
		m_error << "Error: unknown option type \'" << otype[0]
			  << "\' in defintion: " << aDefinition << endl;
		return -1;
	}

	// Set up space for a option entry in the registry
	definitionEntry = new Option_register(aDefinition, otype[0], ovalue);

	int definitionIndex = (int)m_optionRegister.size();

	// Store option aliases
	string optionName;
	aliases += '|';
	for (int i=0; i<(int)aliases.size(); i++) {
		if (::isspace(aliases[i])) {
			continue;
		} else if (aliases[i] == '|') {
			if (isDefined(optionName)) {
				m_error << "Option \"" << optionName << "\" from definition:" << endl;
				m_error << "\t" << aDefinition << endl;
				m_error << "is already defined in: " << endl;
				m_error << "\t" << getDefinition(optionName) << endl;
				return -1;
			}
			if (optionName.size() > 0) {
				m_optionList[optionName] = definitionIndex;
			}
			optionName.clear();
		} else {
			optionName += aliases[i];
		}
	}

	// Store definition in registry and return its indexed location.
	// This location will be used to link option aliases to the main
	// command name.
	m_optionRegister.push_back(definitionEntry);
	return definitionIndex;
}