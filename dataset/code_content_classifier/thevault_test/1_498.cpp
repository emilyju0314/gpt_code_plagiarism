void def_pos_type(const Board& board, EvaluationState& es) {
        auto num_pawns = pop_count(board.piece_bb(W_PAWN) | board.piece_bb(B_PAWN));

        if (num_pawns > 12) {
            es.pos_type = CLOSED;
        } else if (num_pawns > 8) {
            es.pos_type = SEMI_CLOSED;
        } else if (num_pawns > 4) {
            es.pos_type = SEMI_OPEN;
        } else {
            es.pos_type = OPEN;
        }
    }