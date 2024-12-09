Centipawns_t eval_pawns(const Board &board, EvaluationState &es, bool verbose) {
        Bitboard w = board.piece_bb(W_PAWN);
        Bitboard b = board.piece_bb(B_PAWN);
        Centipawns_t ret{0};

#ifndef NDEBUG
        Centipawns_t w_p_pst{0};
        Centipawns_t b_p_pst{0};
#endif // NDEBUG

        /// Piece Square Tables --> Positioning
#ifndef NDEBUG
        w_p_pst = dot_product(w, &PAWN_PST[0]);
        b_p_pst = -dot_product(flip_flop(b), &PAWN_PST[0]);
#endif // NDEBUG
        ret += dot_product(w, &PAWN_PST[0]);
        ret -= dot_product(flip_flop(b), &PAWN_PST[0]);

#ifndef NDEBUG
        if (verbose) {
            es.printer.add("White Pawn PST", w_p_pst);
            es.printer.add("Black Pawn PST", b_p_pst);
        }
#endif // NDEBUG

        return ret;
    }