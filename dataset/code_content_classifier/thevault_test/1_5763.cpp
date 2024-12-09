Soldier* Board::operator[](std::pair<int,int> location) const{
        if(location.first<0 || location.first>=board.size() || location.second<0 || location.second>=board[0].size()) throw std::invalid_argument("ERROR"); 
        return this->board[location.first][location.second];
        
    }