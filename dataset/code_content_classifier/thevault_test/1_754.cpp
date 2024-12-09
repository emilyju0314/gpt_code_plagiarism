void ScreenText::setColor(unsigned int color)
{
	//Extract R G and B channels, mask with 0xff
	unsigned char
		r = (color >> 16) & 0xff,
		g = (color >> 8) & 0xff,
		b = (color >> 0) & 0xff;

	//Set the colour
	this->setColor(r, g, b);
}