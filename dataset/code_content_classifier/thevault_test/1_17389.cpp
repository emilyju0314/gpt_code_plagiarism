bool ModuleRender::BlitSym(SDL_Texture* texture, int x, int y, SDL_Rect* section, float speed, bool use_camera)
{
	bool ret = true;

	SDL_Rect rect;
	SDL_Point p;
	p.x = section->w / 2;
	p.y = section->y + section->h;

	if (use_camera) {
		rect.x = (int)((camera.x + camera_offset.x) * speed) + x * SCREEN_SIZE;
		rect.y = (int)((camera.y + camera_offset.x) * speed) + y * SCREEN_SIZE;

		if (section != NULL)
		{
			rect.w = section->w;
			rect.h = section->h;
		}
		else
		{
			SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
		}

	}

	if (use_camera == false) {
		rect.x = (int)((camera.x + camera_offset.x) * speed) + x * SCREEN_SIZE;
		rect.y = (int)((camera.y + camera_offset.x) * speed) + y * SCREEN_SIZE;

		if (section != NULL)
		{
			rect.w = section->w;
			rect.h = section->h;
		}
		else
		{
			SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
		}

	}
	rect.w *= SCREEN_SIZE;
	rect.h *= SCREEN_SIZE;

			SDL_RenderCopyEx(renderer, texture, section, &rect, 0, NULL, SDL_FLIP_HORIZONTAL);


	return ret;
}