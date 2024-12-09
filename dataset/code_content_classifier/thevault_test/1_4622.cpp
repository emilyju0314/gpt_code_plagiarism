void State::PerformTextUpdated() {
	for (int i = 0; i < (int)textChanged.size(); i++) {
		textChanged[i] = false;
	}
}