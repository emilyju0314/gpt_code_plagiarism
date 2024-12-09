Centipawns_t eval_knights(const Board &board, EvaluationState &es, bool verbose) {
        Bitboard w = board.piece_bb(W_KNIGHT);
        Bitboard b = board.piece_bb(B_KNIGHT);
        Centipawns_t ret{0};

#ifndef NDEBUG
        Centipawns_t w_n_pst{0};
        Centipawns_t b_n_pst{0};
#endif // NDEBUG

        /// Piece Square Tables --> Positioning
#ifndef NDEBUG
        w_n_pst = dot_product(w, &KNIGHT_PST[0]);
        b_n_pst = -dot_product(flip_flop(b), &KNIGHT_PST[0]);
#endif // NDEBUG
        ret += dot_product(w, &KNIGHT_PST[0]);
        ret -= dot_product(flip_flop(b), &KNIGHT_PST[0]);

#ifndef NDEBUG
        if (verbose) {
            es.printer.add("White Knight PST", w_n_pst);
            es.printer.add("Black Knight PST", b_n_pst);
        }
#endif // NDEBUG

        return ret;
    }