Centipawns_t eval_rooks(const Board& board, EvaluationState& es, bool verbose) {
        Bitboard w = board.piece_bb(W_ROOK);
        Bitboard b = board.piece_bb(B_ROOK);
        Centipawns_t ret{0};
#ifndef NDEBUG
        Centipawns_t w_r_pst{0};
        Centipawns_t b_r_pst{0};
#endif // NDEBUG

        /// Piece Square Tables --> Positioning
#ifndef NDEBUG
        w_r_pst = dot_product(w, &ROOK_PST[0]);
        b_r_pst = -dot_product(flip_flop(b), &ROOK_PST[0]);
#endif // NDEBUG
        ret += dot_product(w, &ROOK_PST[0]);
        ret -= dot_product(flip_flop(b), &ROOK_PST[0]);

#ifndef NDEBUG
        if (verbose) {
            es.printer.add("White Rook PST", w_r_pst);
            es.printer.add("Black Rook PST", b_r_pst);
        }
#endif // NDEBUG

        return ret;
    }