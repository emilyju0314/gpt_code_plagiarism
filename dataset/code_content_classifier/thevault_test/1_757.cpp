void ScreenText::setText(const std::string& text)
{
	//Set text!
	this->text = text;

	//Create text surface
	createTextSurface();
}