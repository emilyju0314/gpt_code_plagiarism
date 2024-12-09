void gen_ep_cap(Board& board, std::vector<ChessMove>& movelist) {
        int to_sq = board.ep_sq();
        if (to_sq == EP_DEFAULT) {
            return;
        }

        Bitboard push_pawn;
        if (board.side_2_move() == WHITE) {
            push_pawn = (board.piece_bb(W_PAWN) << 9) & (C64(1) << board.ep_sq()) & ~FILE_MASK[FILEA];
            if (push_pawn) {
                movelist.emplace_back(ChessMove(to_sq - 9, to_sq, ENPASSANT, W_PAWN, B_PAWN));
            }

            push_pawn = (board.piece_bb(W_PAWN) << 7) & (C64(1) << board.ep_sq()) & ~FILE_MASK[FILEH];
            if (push_pawn) {
                movelist.emplace_back(ChessMove(to_sq - 7, to_sq, ENPASSANT, W_PAWN, B_PAWN));
            }
        } else {
            push_pawn = (board.piece_bb(B_PAWN) >> 9) & (C64(1) << board.ep_sq()) & ~FILE_MASK[FILEH];
            if (push_pawn) {
                movelist.emplace_back(ChessMove(to_sq + 9, to_sq, ENPASSANT, B_PAWN, W_PAWN));
            }

            push_pawn = (board.piece_bb(B_PAWN) >> 7) & (C64(1) << board.ep_sq()) & ~FILE_MASK[FILEA];
            if (push_pawn) {
                movelist.emplace_back(ChessMove(to_sq + 7, to_sq, ENPASSANT, B_PAWN, W_PAWN));
            }
        }
    }