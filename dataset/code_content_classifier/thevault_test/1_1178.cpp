int Board::find_connected(Block &block){
	int connecteds = 0;

	if (!board[block.x][block.y].readed){
		board[block.x][block.y].readed = true;
		blocks_connected.push_back(board[block.x][block.y]);
	}

	if (block.x - 1 > 0 && board[block.x-1][block.y].free == false && !board[block.x-1][block.y].readed){
		if (block.color == board[block.x-1][block.y].color){
			board[block.x-1][block.y].readed = true;
			blocks_connected.push_back(board[block.x-1][block.y]);
			find_connected(board[block.x-1][block.y]);
		}
		//connecteds += find_connected(board[block.x-1][block.y]);
	}

	if (block.y + 1 < rows && board[block.x][block.y + 1].free == false && !board[block.x][block.y + 1].readed){
		if (block.color == board[block.x][block.y + 1].color){
			board[block.x][block.y + 1].readed = true;
			blocks_connected.push_back(board[block.x][block.y + 1]);
			find_connected(board[block.x][block.y + 1]);
		}
	}

	if (block.x + 1 < cols && board[block.x + 1][block.y].free == false && !board[block.x + 1][block.y].readed){
		if (block.color == board[block.x + 1][block.y].color){
			board[block.x + 1][block.y].readed = true;
			blocks_connected.push_back(board[block.x + 1][block.y]);
			find_connected(board[block.x + 1][block.y]);
		}
	}

	if (block.y - 1 > 0 && board[block.x][block.y - 1].free == false && !board[block.x][block.y - 1].readed){
		if (block.color == board[block.x][block.y - 1].color){
			board[block.x][block.y - 1].readed = true;
			blocks_connected.push_back(board[block.x][block.y - 1]);
			find_connected(board[block.x][block.y - 1]);
		}
	}
	return connecteds;
}