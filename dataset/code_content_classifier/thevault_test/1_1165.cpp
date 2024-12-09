void Board::draw_screen_title(){
	SDL_Rect sdl_title = {MARGIN, MARGIN, (PUYO_WIDTH * cols) + (PUYO_WIDTH * 3), PUYO_HEIGHT};
	SDL_FillRect(this->screen , &sdl_title , Color::GRAY);

	TTF_Font* font = TTF_OpenFont("arial.ttf", 18);
	SDL_Color foregroundColor = { 255, 255, 255 }; 
    SDL_Color backgroundColor = { 51, 51, 51 };
	SDL_Rect textLocation = { (PUYO_WIDTH * cols) / 2, MARGIN * 2, 0, 0 }; 
	SDL_Surface* textSurface = TTF_RenderText_Shaded(font, "Puyo puyo", foregroundColor, backgroundColor);
	SDL_BlitSurface(textSurface, NULL, screen, &textLocation);
}