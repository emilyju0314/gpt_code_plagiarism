Centipawns_t eval_queens(const Board &board, EvaluationState &es, bool verbose) {
        Bitboard w = board.piece_bb(W_QUEEN);
        Bitboard b = board.piece_bb(B_QUEEN);
        Centipawns_t ret{0};
#ifndef NDEBUG
        Centipawns_t w_queen_pst{0};
        Centipawns_t b_queen_pst{0};
        Centipawns_t w_queen_fast_dev{0}; // developed too fast
        Centipawns_t b_queen_fast_dev{0}; // developed too fast
#endif // NDEBUG

#ifndef NDEBUG
        w_queen_pst = dot_product(w, &QUEEN_PST[0]);
        b_queen_pst = -dot_product(flip_flop(b), &QUEEN_PST[0]);
#endif // NDEBUG
        ret += dot_product(w, &QUEEN_PST[0]);
        ret -= dot_product(flip_flop(b), &QUEEN_PST[0]);

        /// Penalize developing queen before 2 minor pieces in opening
        if (es.stage == OPENING) {
            if (board.piece_bb(W_QUEEN) != (C64(1) << D1)) {
                Bitboard minor_piece_development = (board.piece_bb(W_BISHOP) | board.piece_bb(W_KNIGHT)) & (RANK_MASK[RANK1]);
                if (pop_count(minor_piece_development) > 3) {
#ifndef NDEBUG
                    w_queen_fast_dev += Q_B4_3_MINORS;
#endif // NDEBUG
                    ret += Q_B4_3_MINORS;
                }
            }

            if (board.piece_bb(B_QUEEN) != (C64(1) << D8)) {
                Bitboard minor_piece_development = (board.piece_bb(B_BISHOP) | board.piece_bb(B_KNIGHT)) & (RANK_MASK[RANK8]);
                if (pop_count(minor_piece_development) > 3) {
#ifndef NDEBUG
                    b_queen_fast_dev -= Q_B4_3_MINORS;
#endif // NDEBUG
                    ret -= Q_B4_3_MINORS;
                }
            }
        }

#ifndef NDEBUG
        if (verbose) {
            es.printer.add("White Queen PST", w_queen_pst);
            es.printer.add("Black Queen PST", b_queen_pst);
            es.printer.add("White Queen Developed Too Fast", w_queen_fast_dev);
            es.printer.add("Black Queen Developed Too Fast", b_queen_fast_dev);
        }
#endif // NDEBUG

        return ret;
    }