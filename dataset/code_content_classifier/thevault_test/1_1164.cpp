void Board::draw_screen_board(){
	SDL_Rect sdl_board = {MARGIN,  PUYO_HEIGHT + MARGIN, (PUYO_WIDTH * cols), (PUYO_HEIGHT * rows)};
	SDL_FillRect(this->screen , &sdl_board , Color::BLACK);

	TTF_Font* font = TTF_OpenFont("arial.ttf", 18);
	SDL_Color foregroundColor = { 255, 255, 255 }; 
    SDL_Color backgroundColor = { 51, 51, 51 };
	SDL_Rect textLocation = { (PUYO_WIDTH * cols) / 2, MARGIN * 2, 0, 0 }; 
	SDL_Surface* textSurface = TTF_RenderText_Shaded(font, "Puyo puyo", foregroundColor, backgroundColor);
	SDL_BlitSurface(textSurface, NULL, screen, &textLocation);
}