void Board::moving_blocks_falling(){
	for(int x = 0; x < cols; x++){
		for(int y=rows - 1; y >= 0; y--){
			if (!board[x][y].falling){
				continue;
			}
		}
	}
}