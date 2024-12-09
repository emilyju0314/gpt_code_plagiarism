TTF_Font* const j1Fonts::Load(const char* path, int size)
{
	
	TTF_Font* font = TTF_OpenFontRW(App->assetManager->Load(path), 1, size);

	if (font == NULL)
	{
		LOG("Could not load TTF font with path: %s. TTF_OpenFont: %s", path, TTF_GetError());
	}
	else
	{
		LOG("Successfully loaded font %s size %d", path, size);
	}

	return font;
}