void State::ChangeText(TextStruct text, int index) {
	delete m_vAllText[index];
	m_vAllText[index] = nullptr;
	m_vAllText[index] = new TextStruct(text);
	textChanged[index] = true;
}