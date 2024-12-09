bool hasText(HTp token) {
	HTp current = token->getNextFieldToken();
	while (current) {
		if (current->isKern()) {
			break;
		}
		if (current->isDataType("**text")) {
			if (current->isNull()) {
				return false;
			} else {
				return true;
			}
		}
		current = current->getNextFieldToken();
	}
	return false;
}