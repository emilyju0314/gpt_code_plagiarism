void Board::init(SDL_Surface *screen) {
	this->screen = screen;
	calculate_screen_size();

	//Draw game screen
	draw_screen_title();
	draw_screen_board();
	draw_screen_scores();
}