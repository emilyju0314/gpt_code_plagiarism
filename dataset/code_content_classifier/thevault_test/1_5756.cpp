int spaceFill(char letter, std::string word)
{
	const int len = word.length();
	
	// Check the guess	
	int matches = 0;
	for (int i = 0; i < len; i++) {
		
		// If guess is repeated
		if (letter == fills[i])
			return -1;
		
		// Compare guess
		if (letter == word[i])
		{
			fills[i] = letter;
			matches++;
		}
	}
	
	return matches;
}