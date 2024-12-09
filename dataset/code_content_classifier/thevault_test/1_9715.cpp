void markNote(NotePoint& np) {
	Marked = 1;
	HTp token = np.token;
	if (!token) {
		return;
	}
	if (!token->isChord()) {
		string contents = *token;
		contents += "@";
		token->setText(contents);
		return;
	}
	vector<string> tokens = token->getSubtokens();
	tokens[np.subindex] += "@";
	string output = tokens[0];
	for (int i=1; i<(int)tokens.size(); i++) {
		output += " ";
		output += tokens[i];
	}
	token->setText(output);
}