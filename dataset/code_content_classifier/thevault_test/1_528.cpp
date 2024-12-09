void gen_king_quiet(Board& board, std::vector<ChessMove>& movelist){
        Bitboard push_king;
        Square_t from_sq;
        Square_t to_sq;

        if (board.side_2_move() == WHITE) {
            from_sq = board.king_location(WHITE);
            push_king = king_moves(board.piece_bb(W_KING)) & board.empty_bb();
            while (push_king) {
                to_sq = bitscan_forward(push_king);
                movelist.emplace_back(ChessMove(from_sq, to_sq, QUIET_MOVE, W_KING, NO_PIECE));
                push_king -= (C64(1) << to_sq);
            }
        } else {
            from_sq = board.king_location(BLACK);
            push_king = king_moves(board.piece_bb(B_KING)) & board.empty_bb();
            while (push_king) {
                to_sq = bitscan_forward(push_king);
                movelist.emplace_back(ChessMove(from_sq, to_sq, QUIET_MOVE, B_KING, NO_PIECE));
                push_king -= (C64(1) << to_sq);
            }
        }
    }