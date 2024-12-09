void ScreenText::createTextSurface(void)
{
	if (fontptr == NULL) return;
	//Destroy existing surfaces and textures
	if (this->textSurface != NULL)
		SDL_FreeSurface(this->textSurface);

	//If the texture is not null.. destroy it
	if (this->textTexture != NULL)
		SDL_DestroyTexture(this->textTexture);

	// renders the text via SDL_TTF into a surface, then loads that into a texture
	// note: uncomment the various lines below one at a time to see the difference
	//SDL_Surface * textSurface = TTF_RenderText_Shaded(fontptr, text.c_str(), color, backgroundcolour);
	SDL_Surface * textSurface = TTF_RenderText_Blended(fontptr, text.c_str(), color);
	//SDL_Surface * textSurface = TTF_RenderText_Solid(fontptr, text.c_str(), color);

	if (textSurface != NULL)
	{
		width = textSurface->w;
		height = textSurface->h;

		textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
		if (!textTexture)
		{
			SDL_Log("Unable to create SDL_Texture in ScreenText::CreateTextSurface");
		}
		SDL_FreeSurface(textSurface);
		textSurface = NULL;
	}
	else
	{
		SDL_Log("Unable to create SDL_Surface in ScreenText::CreateTextSurface");
	}



}