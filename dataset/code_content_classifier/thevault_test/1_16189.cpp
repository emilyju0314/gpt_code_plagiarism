SDL_Texture* ModuleTextures::Load(std::string path, bool isName)
{
	if(isName)
	{
		path = config.child(path.c_str()).attribute("path").as_string();
	}

	std::map<std::string, SDL_Texture*>::iterator it;
	it = texturePath.find(path);

	if (it != texturePath.end())
	{
		return texturePath.find(path)->second;
	}

	SDL_Texture* texture = NULL;
	SDL_Surface* surface = IMG_Load(path.c_str());

	if(surface == NULL)
	{
		LOG("Could not load surface with path: %s. IMG_Load: %s", path, IMG_GetError());
	}
	else
	{
		texture = SDL_CreateTextureFromSurface(App->renderer->renderer, surface);

		if(texture == NULL)
		{
			LOG("Unable to create texture from surface! SDL Error: %s\n", SDL_GetError());
		}
		else
		{
			textures.add(texture);
		}

		SDL_FreeSurface(surface);
	}

	texturePath.insert(std::pair<std::string, SDL_Texture*>(path, texture));

	return texture;
}