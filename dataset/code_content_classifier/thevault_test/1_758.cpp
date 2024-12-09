bool ScreenText::loadFontData(const std::string& path)
{
	fontpath = path;
	//Log to tell the user we're starting
	SDL_Log("Font loading started! Path is '%s'", fontpath.c_str());

	//  fontptr wasn't NULL, so release the old font, set its pointer to null and then call loadFontData
	if (fontptr != NULL)
	{
		TTF_CloseFont(fontptr);
		fontptr = NULL;
	}

	//Try to open up the file 
	fontptr = TTF_OpenFont(fontpath.c_str(), fontScale);

	//Couldn't be opened. Return false.
	if (!fontptr)
		return false;

	//Return true -- everything is good!
	return true;
}