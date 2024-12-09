void TetrisInterface::drawPaused(){
	sf::Font font;
	font.loadFromFile("resources/arial.ttf");

	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(2 * FONT_SIZE);
	text.setFillColor(FONT_COLOR);
	text.setString("Paused");
	text.setPosition((WIDTH - text.getLocalBounds().width) / 2, HEIGHT / 2);

	sf::RectangleShape back;
	back.setSize(sf::Vector2f(text.getLocalBounds().width, text.getLocalBounds().height) + sf::Vector2f(4 * FONT_SIZE, 4 * FONT_SIZE));
	back.setFillColor(INTERFACE_OUTLINE_COLOR);
	back.setOrigin(sf::Vector2f(0, 0));
	back.setOutlineColor(FONT_COLOR);
	back.setOutlineThickness(FONT_SIZE);
	back.setPosition(text.getPosition() - sf::Vector2f(2 * FONT_SIZE, 1 * FONT_SIZE));
	mainWindow.draw(back);
	mainWindow.draw(text);
}