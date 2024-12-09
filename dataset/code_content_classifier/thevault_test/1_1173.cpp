void Board::draw_blocks(){
	for(int x = 0; x < cols; x++){
		for(int y = 0; y < rows; y++){
			render_block(board[x][y], board[x][y].color);
		}
	}
}