bool Board::is_block_falling(){
	for(int x = 0; x < cols; x++){
		for(int y = 0; y < rows; y++){
			if (board[x][y].moving){
				return true;
			}
		}
	}
	return false;
}