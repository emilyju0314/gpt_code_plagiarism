bool Board::has_soldiers(uint pn) const {
        for(int i = 0; i < board.size() ; i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j]!=nullptr && board[i][j]->player==pn) return true;
            }
        }
        return false;


    }