ScreenText::~ScreenText(void)
{
	//  fontptr wasn't NULL, so release the font, set its pointer to null 
	if (fontptr != NULL)
	{
		TTF_CloseFont(fontptr);
		fontptr = NULL;
	}

	//Destroy existing surfaces and textures
	SDL_FreeSurface(this->textSurface);

	//If the texture is not null.. destroy it
	if (this->textTexture != NULL)
		SDL_DestroyTexture(this->textTexture);
}