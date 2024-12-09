void ScreenText::render(void)
{
	//Source rect is the full width of the text
	SDL_Rect src = { 0, 0, this->width, this->height };

	//Dest rect is using internal state of this ScreenText instance
	SDL_Rect dst = { this->x, this->y, this->width, this->height };

	//Use rendercopy to copy using these parameters
	SDL_RenderCopy(renderer, this->textTexture, &src, &dst);
}