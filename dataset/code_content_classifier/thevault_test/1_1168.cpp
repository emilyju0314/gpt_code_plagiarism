void Board::draw_screen_pause(){
	SDL_Rect sdl_board = {0, 0, width_px, heigth_px};
	SDL_FillRect(this->screen , &sdl_board , Color::BLACK);

	TTF_Font* font = TTF_OpenFont("arial.ttf", 30);
	SDL_Color foregroundColor = { 255, 255, 255 }; 
    SDL_Color backgroundColor = { 0, 0, 150 };
	SDL_Rect textLocation = { (PUYO_WIDTH * cols) / 2, (PUYO_HEIGHT * rows) / 2, 0, 0 }; 
	SDL_Surface* textSurface = TTF_RenderText_Shaded(font, "GAME PAUSED", foregroundColor, backgroundColor);
	SDL_BlitSurface(textSurface, NULL, screen, &textLocation);

	TTF_Font* font2 = TTF_OpenFont("arial.ttf", 19);
	SDL_Rect textLocation2 = { (PUYO_WIDTH * cols) / 2 - PUYO_WIDTH / 2, (PUYO_HEIGHT * rows) / 2 + MARGIN * 3, 0, 0 }; 
	SDL_Surface* textSurface2 = TTF_RenderText_Shaded(font2, "Press SPACE BAR to continue...", foregroundColor, backgroundColor);
	SDL_BlitSurface(textSurface2, NULL, screen, &textLocation2);
}