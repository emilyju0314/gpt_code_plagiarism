void ScreenText::setColor(unsigned char r, unsigned char g, unsigned char b)
{
	//Make a new colour
	SDL_Color color = { r, g, b };

	//Call other overloaded setColor function
	this->setColor(color);
}