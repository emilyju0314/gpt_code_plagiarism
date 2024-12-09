void Board::update_board(){
	for(int x = 0; x < cols; x++){
		for(int y=rows - 1; y >= 0; y--){
			if (board[x][y].free){
				continue;
			}
			board[x][y].falling = true;
		}
	}
}