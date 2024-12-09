std::vector<std::string> World::buildUserFullInput(std::vector<std::string> structuredPlayerInput, const std::string playerInput)
{
	const char *playerInputData = playerInput.c_str();
	int wordBeginning = 0;
	int wordCounter = 0;

	for (unsigned int wordIndex = 0; wordIndex <= playerInput.length(); ++wordIndex) {
		wordCounter++;
		if (playerInputData[wordIndex] == ' ') {
			structuredPlayerInput.push_back(playerInput.substr(wordBeginning, wordCounter - 1));
			wordBeginning = wordIndex + 1;
			wordCounter = 0;
		}
	}
	structuredPlayerInput.push_back(playerInput.substr(wordBeginning, wordCounter));
	return structuredPlayerInput;
}