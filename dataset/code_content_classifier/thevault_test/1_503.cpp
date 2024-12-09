Centipawns_t eval_bishop(const Board &board, EvaluationState &es, bool verbose) {
        Bitboard w = board.piece_bb(W_BISHOP);
        Bitboard b = board.piece_bb(B_BISHOP);
        Centipawns_t ret{0};

#ifndef NDEBUG
        Centipawns_t w_b_pst{0};
        Centipawns_t b_b_pst{0};
#endif // NDEBUG


        /// Piece Square Tables --> Positioning
#ifndef NDEBUG
        w_b_pst = dot_product(w, &BISHOP_PST[0]);
        b_b_pst = -dot_product(flip_flop(b), &BISHOP_PST[0]);
#endif // NDEBUG
        ret += dot_product(w, &BISHOP_PST[0]);
        ret -= dot_product(flip_flop(b), &BISHOP_PST[0]);

#ifndef NDEBUG
        if (verbose) {
            es.printer.add("White Bishop PST", w_b_pst);
            es.printer.add("Black Bishop PST", b_b_pst);
        }
#endif // NDEBUG

        return ret;
    }