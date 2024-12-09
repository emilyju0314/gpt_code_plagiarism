void gen_castle(Board& board, std::vector<ChessMove>& movelist) {
        if (board.side_2_move() == WHITE) {
            if ((board.castle_perm() & WKC)) {
                Bitboard bb = C64(96);
                if ((board.empty_bb() & bb) == bb) { // 96 = 2^5 + 2^6
                    if (!board.is_sq_attacked(E1, BLACK) && !board.is_sq_attacked(F1, BLACK) && !board.is_sq_attacked(G1, BLACK)) {
                        movelist.emplace_back(ChessMove(E1, G1, KING_CASTLE, W_KING, NO_PIECE));
                    }
                }
            }

            if ((board.castle_perm() & WQC)) {
                Bitboard bb = C64(14);
                if ((board.empty_bb() & bb) == bb) { // 2^1 + 2^2 + 2^3
                    if (!board.is_sq_attacked(E1, BLACK) && !board.is_sq_attacked(D1, BLACK) && !board.is_sq_attacked(C1, BLACK)) {
                        movelist.emplace_back(ChessMove(E1, C1, QUEEN_CASTLE, W_KING, NO_PIECE));
                    }
                }
            }
        } else {
            if ((board.castle_perm() & BKC)) {
                Bitboard bb = (Bitboard)6917529027641081856;
                if ((bb & board.empty_bb()) == bb) {
                    if (!board.is_sq_attacked(E8, WHITE) && !board.is_sq_attacked(F8, WHITE) && !board.is_sq_attacked(G8, WHITE)) {
                        movelist.emplace_back(ChessMove(E8, G8, KING_CASTLE, B_KING, NO_PIECE));

                    }
                }
            }

            if ((board.castle_perm() & BQC)) {
                Bitboard bb = (Bitboard)1008806316530991104;
                if ((board.empty_bb() & bb) == bb) {
                    if (!board.is_sq_attacked(E8, WHITE) && !board.is_sq_attacked(D8, WHITE) && !board.is_sq_attacked(C8, WHITE)) {
                        movelist.emplace_back(ChessMove(E8, C8, QUEEN_CASTLE, B_KING, NO_PIECE));
                    }
                }
            }
        }
    }