long hashWord(word saxWord) {
	char beginSym = 'a';
	int result = 0;
	for (int i = m_string_size - 1; i >= 0; i--)
	{
		result += abs(saxWord[i] - 'a')*powl(m_string_size, m_string_size - 1 - i);
	}
	return result;
}