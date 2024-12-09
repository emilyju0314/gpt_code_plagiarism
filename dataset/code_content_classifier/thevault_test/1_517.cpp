void gen_pawn_quiet(Board& board, std::vector<ChessMove>& movelist) {
        Bitboard push_pawn;
        Square_t to_sq;

        if (board.side_2_move() == WHITE) {
            push_pawn = (board.piece_bb(W_PAWN) << 8) & (board.empty_bb() & ~RANK_MASK[RANK8]);
            while (push_pawn) {
                to_sq = bitscan_forward(push_pawn);
                movelist.emplace_back(ChessMove(to_sq - 8, to_sq, QUIET_MOVE, W_PAWN, NO_PIECE));
                push_pawn -= (C64(1) << to_sq);
            }

            push_pawn = (((board.piece_bb(W_PAWN) << 8) & board.empty_bb()) << 8) & RANK_MASK[RANK4] & board.empty_bb();
            while (push_pawn) {
                to_sq = bitscan_forward(push_pawn);
                movelist.emplace_back(ChessMove(to_sq - 16, to_sq, DOUBLE_PUSH_PAWN, W_PAWN, NO_PIECE));
                push_pawn -= (C64(1) << to_sq);
            }
        } else {
            push_pawn = (board.piece_bb(B_PAWN) >> 8) & (board.empty_bb() & ~RANK_MASK[RANK1]);
            while (push_pawn) {
                to_sq = bitscan_forward(push_pawn);
                movelist.emplace_back(ChessMove(to_sq + 8, to_sq, QUIET_MOVE, B_PAWN, NO_PIECE));
                push_pawn -= (C64(1) << to_sq);
            }

            push_pawn = (((board.piece_bb(B_PAWN) >> 8) & board.empty_bb()) >> 8) & RANK_MASK[RANK5] & board.empty_bb();
            while (push_pawn) {
                to_sq = bitscan_forward(push_pawn);
                movelist.emplace_back(ChessMove(to_sq + 16, to_sq, DOUBLE_PUSH_PAWN, B_PAWN, NO_PIECE));
                push_pawn -= (C64(1) << to_sq);
            }
        }
    }