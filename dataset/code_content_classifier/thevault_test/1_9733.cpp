HTp Tool_semitones::markNote(HTp token, bool markQ) {
	string subtok = token->getSubtoken(0);
	bool hasTieEnd = false;
	if (subtok.find('_') != string::npos) {
		hasTieEnd = true;
	} else if (subtok.find(']') != string::npos) {
		hasTieEnd = true;
	}

	if (!(hasTieEnd && m_notiesQ)) {
		if (markQ) {
			addMarker(token);
		}
	}

	bool hasTie = false;
	if (subtok.find('[') != string::npos) {
		hasTie = true;
	} else if (subtok.find('_') != string::npos) {
		hasTie = true;
	}

	if (!hasTie) {
		return token;
	}
	HTp current = token->getNextToken();
	while (current) {
		if (!current->isData()) {
			current = current->getNextToken();
			continue;
		}
		if (current->isNull()) {
			current = current->getNextToken();
			continue;
		}
		subtok = current->getSubtoken(0);
		bool hasTie = false;
		if (subtok.find('[') != string::npos) {
			hasTie = true;
		} else if (subtok.find('_') != string::npos) {
			hasTie = true;
		}
		if (!hasTie) {
			if (subtok.find(']') != string::npos) {
				markNote(current, markQ);
			}
			return current;
		} else {
			return markNote(current, markQ);
		}
		break;
	}
	return NULL;
}