void TetrisInterface::draw(){
	sf::RectangleShape panel;
	panel.setSize(sf::Vector2f(INTERFACE_WIDTH, INTERFACE_HEIGHT) - sf::Vector2f(INTERFACE_OUTLINE_THICKNESS, INTERFACE_OUTLINE_THICKNESS));
	panel.setFillColor(INTERFACE_COLOR);
	panel.setOutlineColor(INTERFACE_OUTLINE_COLOR);
	panel.setOutlineThickness(INTERFACE_OUTLINE_THICKNESS);
	panel.setPosition(sf::Vector2f(WIDTH - INTERFACE_WIDTH + INTERFACE_OUTLINE_THICKNESS, 0));
	mainWindow.draw(panel);

	sf::Font font;
	font.loadFromFile("resources/arial.ttf");

	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(FONT_SIZE);
	text.setFillColor(FONT_COLOR);
	char stringBuffer[30] = { '\0' };
	sprintf_s(stringBuffer, "Next Tetrimino");
	text.setString(stringBuffer);
	text.setPosition(BLOCK_GRID_WIDTH + (INTERFACE_WIDTH - text.getLocalBounds().width) / 2, 0);
	mainWindow.draw(text);

	sprintf_s(stringBuffer, "Level: %i", level);
	text.setPosition(BLOCK_GRID_WIDTH + 5, HEIGHT / 2);
	text.setString(stringBuffer);
	mainWindow.draw(text);

	sprintf_s(stringBuffer, "Lines: %i", linesCleared);
	text.setPosition(BLOCK_GRID_WIDTH + 5, HEIGHT / 2 + FONT_SIZE);
	text.setString(stringBuffer);
	mainWindow.draw(text);

	sprintf_s(stringBuffer, "Score: %i", score);
	text.setPosition(BLOCK_GRID_WIDTH + 5, HEIGHT / 2 + 2 * FONT_SIZE);
	text.setString(stringBuffer);
	mainWindow.draw(text);

	int currentTime = timer.getCurrentTime() / 1000;
	if (isPaused()){
		currentTime = (pauser.getReferenceTime() - timer.getReferenceTime()) / 1000;
	}
	if (currentTime < 60)
		sprintf_s(stringBuffer, "Time: %is", currentTime);
	else if (currentTime >= 60 && currentTime < 3600)
		sprintf_s(stringBuffer, "Time: %im %is", currentTime / 60, currentTime % 60);
	else
		sprintf_s(stringBuffer, "Time: %ih %im %is", currentTime / 3600, (currentTime % 3600) / 60, (currentTime % 3600) % 60);
	text.setPosition(BLOCK_GRID_WIDTH + 5, HEIGHT / 2 + 3 * FONT_SIZE);
	text.setString(stringBuffer);
	mainWindow.draw(text);


	sprintf_s(stringBuffer, "Drop Speed: %ims", getTimeDelay());
	text.setPosition(BLOCK_GRID_WIDTH + 5, HEIGHT / 2 + 4 * FONT_SIZE);
	text.setString(stringBuffer);
	mainWindow.draw(text);

	currentTime = getTimeDelay() - delayer.getCurrentTime();
	if (isPaused()){
		currentTime = pauser.getReferenceTime() - delayer.getReferenceTime();
	}
	sprintf_s(stringBuffer, "Drops in: %ims", currentTime);
	text.setPosition(BLOCK_GRID_WIDTH + 5, HEIGHT / 2 + 5 * FONT_SIZE);
	text.setString(stringBuffer);
	mainWindow.draw(text);
	
	for (int i = 0; i < blockOverlay.getBlockCount(); i++){
		mainWindow.draw(blockOverlay.getBlock(i).asRectangleShape());
	}
}