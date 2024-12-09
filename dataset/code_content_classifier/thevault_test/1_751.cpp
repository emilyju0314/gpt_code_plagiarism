void ScreenText::updateSurface(void)
{
	//Do a bit of cheating, remake surface with same string.. updating it :)
	this->setText(this->text);
}