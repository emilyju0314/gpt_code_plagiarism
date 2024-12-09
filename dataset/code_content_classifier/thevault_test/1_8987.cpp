bool is_win(const GameOptions& game_options, const Board& board) {
        
        bool win = false;
        
        if (board.attempts_and_feedbacks.empty()) {
            win = false;
        }

        if (board.attempts_and_feedbacks.back().attempt.value == board.secret_code.value) {
            win = true;
        }
        return win;
    }