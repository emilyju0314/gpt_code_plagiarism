int ModuleFont::Load(const char* texture_path, const char* characters, int id)
{
		if (fonts[id].graphic == nullptr) {

			int width;
			int height;

			if (texture_path == nullptr || characters == nullptr)
			{
				LOG("Could not load font");
			}

			SDL_Texture* tex = App->textures->Load(texture_path);

			if (tex == nullptr || strlen(characters) >= MAX_FONT_CHARS)
			{
				LOG("Could not load font at %s with characters '%s'", texture_path, characters);
			}

			SDL_QueryTexture(tex, NULL, NULL, &width, &height);

			fonts[id].graphic = tex; // graphic: pointer to the texture
			fonts[id].len = strlen(characters); // len: length of the table
			strcpy_s(fonts[id].table, characters);
			fonts[id].char_h = height;
			fonts[id].char_w = width / strlen(characters);

			LOG("Successfully loaded BMP font from %s", texture_path);
			return id;
		}
}