void Board::sorting_blocks(){
	for(int x = 0; x < cols; x++){
		for(int y=rows - 1; y >= 0; y--){
			if (!board[x][y + 1].free){
				continue;
			}
		}
	}
}