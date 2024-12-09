void j1Fonts::BlitText(int x, int y, int font_id, const char* text) const {
	int aux1 = 1;
	if (text == nullptr || font_id < 0 || font_id >= MAX_FONTS || fonts[font_id].graphic == nullptr) {
		LOG("Unable to render text with bmp font id %d", font_id);
		return;
	}

	const Font* font = &fonts[font_id];
	SDL_Rect rect;
	uint len = strlen(text);

	rect.w = font->char_w;
	rect.h = font->char_h;

	for (uint i = 0; i < len; ++i)	{
		int aux = 0;
		for (uint j = 0; j < fonts[font_id].row_chars; ++j) {
			if (fonts[font_id].table[j] == text[i]) {
				aux = j;
			}
		}
		rect.x = aux * fonts[font_id].char_w;
		rect.y = 0;
		App->render->Blit(fonts[font_id].graphic, x + aux1 * rect.w, y, &rect, 0.00f, false);
		aux1++;
	}
}