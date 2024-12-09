void gen_king_cap(Board& board, std::vector<ChessMove>& movelist) {
        Bitboard push_king;
        Square_t from_sq;
        Square_t to_sq;
        PieceType_t ptc;

        if(board.side_2_move() == WHITE) {
            from_sq = board.king_location(WHITE);
            push_king = king_moves(board.piece_bb(W_KING)) & board.capturable(BLACK);
            while (push_king) {
                to_sq = bitscan_forward(push_king);
                ptc = board.piece_type(to_sq, BLACK);
                movelist.emplace_back(ChessMove(from_sq, to_sq, CAPTURE_MOVE, W_KING, ptc));
                push_king -= (C64(1) << to_sq);
            }
        } else {
            from_sq = board.king_location(BLACK);
            push_king = king_moves(board.piece_bb(B_KING)) & board.capturable(WHITE);
            while (push_king) {
                to_sq = bitscan_forward(push_king);
                ptc = board.piece_type(to_sq, WHITE);
                movelist.emplace_back(ChessMove(from_sq, to_sq, CAPTURE_MOVE, B_KING, ptc));
                push_king -= (C64(1) << to_sq);
            }
        }
    }