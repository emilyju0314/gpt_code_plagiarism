bool is_end_of_game(const GameOptions& game_options, const Board& board) {
        
        bool end = false;

        // comparaison du nombre d essai effectue par l utilisateur et le nombre max de test
        if (board.attempts_and_feedbacks.size() == game_options.max_number_of_attempts){
            end = true;
            std::cout << "it is the end of the game" << std::endl;
        }

        else{
            end = false;
            std::cout << "you have an other chance " << std::endl;
        }
        return end;
    }