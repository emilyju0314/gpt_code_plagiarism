void ScreenText::setText(const std::string& text, const int posX, const int posY, const bool bCenterText, const int fontSize, const int r, const int g, const int b)
{
	//Set x, y and font scale
	this->x = posX;
	this->y = posY;

	// this will reload font from TTF file for the right font point size if needed
	setFontSize(fontSize);

	//If parameters have been changed
	if (r != -1 && g != -1 && b != -1)
		this->setColor(r, g, b);

	//Call set text normally
	setText(text);

	// if bCenterText is true, then our X,Y is meant to be the position of the center of the text (so we can use it centered on screen)
	// so in this case, compute the new X and Y position based on the size of the text surface created with this text output (surface)
	if (bCenterText)
	{
		this->x = posX - (width * 0.5);
		this->y = posY - (height * 0.5);
	}

}