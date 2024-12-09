void State::save(const std::string& filename) {
	//open file and deal with errors if cannot
	std::ofstream outputFile;
	outputFile.open(filename, std::ios::out | std::ios::binary);
	if (!outputFile) {
		std::cout << "file could not be opened.\n";
		return;
	}
	
	//write current position and which map you're on
	sf::Vector2f position = player->getPosition();
	outputFile.write((char*)&position.x, sizeof(float));
	outputFile.write((char*)&position.y, sizeof(float));
	std::cout << "Position recorded: " << position.x << ", " << position.y << "\n";
	std::cout << "Player at: " << player->getBase() << "\n";
	//	outputFile.write((char*)currentMap->ID, sizeof(int));
	
	//write all current conditions
	for(auto condition : this->conditions) {
		outputFile.write((char*)&condition, sizeof(int));
	}
	
	outputFile.close();
	std::cout << "Save completed successfully.\n";
}