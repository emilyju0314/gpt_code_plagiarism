void Tool_semitones::markInterval(HTp token) {
	if (!token->isData()) {
		return;
	}
	if (!token->isKern()) {
		return;
	}
	if (token->isNull()) {
		return;
	}
	if (token->isRest()) {
		return;
	}
	if (token->isUnpitched()) {
		return;
	}
	m_markCount++;
	token = markNote(token, m_firstQ);
	if (m_firstQ && !m_secondQ) {
		return;
	}
	// find next note
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
		markNote(current, m_secondQ);
		break;
	}
}