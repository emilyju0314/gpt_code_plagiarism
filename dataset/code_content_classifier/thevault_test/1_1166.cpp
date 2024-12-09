void Board::draw_screen_scores(){
	SDL_Rect sdl_scores = {(PUYO_WIDTH * cols + MARGIN), PUYO_HEIGHT + MARGIN, (PUYO_WIDTH * 3), (PUYO_HEIGHT * rows)};
	SDL_FillRect(this->screen , &sdl_scores , Color::GRAY);

	TTF_Font* font = TTF_OpenFont("arial.ttf", 21);
	SDL_Color foregroundColor = { 255, 255, 255 }; 
    SDL_Color backgroundColor = { 51, 51, 51 };
	SDL_Rect textLocation = { (PUYO_WIDTH * cols + PUYO_WIDTH), PUYO_HEIGHT + MARGIN, 0, 0 }; 
	SDL_Surface* textSurface = TTF_RenderText_Shaded(font, "SCORE", foregroundColor, backgroundColor);
	SDL_BlitSurface(textSurface, NULL, screen, &textLocation);

	refresh_score(score);
}