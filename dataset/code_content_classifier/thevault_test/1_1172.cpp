bool Board::update_falling2(){
	bool flag = false;
	for(int x = 0; x < cols; x++){
		for(int y = rows - 2; y >= 0; y--){
			if (board[x][y].free){
				continue;
			}
			if (board[x][y + 1].free){
				move(board[x][y], DOWN);
				flag = true;
			}
		}
	}
	return flag;
}