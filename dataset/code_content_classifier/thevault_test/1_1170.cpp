void Board::falling_new_block(){
	if (board[cols/2][0].free == false|| board[cols/2 + 1][0].free == false){
		current_state = GAMEOVER;
		return;
	}

	if (!is_block_falling() && !gameover){
		if (board[cols/2][0].free && board[cols/2 + 1][0].free){
			board[cols/2][0].color = Color::random_color();
			board[cols/2][0].falling = true;
			board[cols/2][0].moving = true;
			board[cols/2][0].free = false;
			board[cols/2][0].pivot = true;

			board[cols/2 + 1][0].color = Color::random_color();
			board[cols/2 + 1][0].falling = true;
			board[cols/2 + 1][0].moving = true;
			board[cols/2 + 1][0].free = false;
			board[cols/2 + 1][0].pivot = false;

			current_blocks.push_back(board[cols/2][0]);
			current_blocks.push_back(board[cols/2 + 1][0]);
		}
	}
	current_state = WAITING;
}