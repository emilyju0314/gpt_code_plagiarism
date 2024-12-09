Centipawns_t eval_kings(const Board &board, EvaluationState &es, bool verbose) {
        Bitboard w = board.piece_bb(W_KING);
        Bitboard b = board.piece_bb(B_KING);
        Centipawns_t ret{0};
#ifndef NDEBUG
        Centipawns_t w_king_pst;
        Centipawns_t b_king_pst;
#endif // NDEBUG


        /// if the game stage is early end game or late end game
        if (es.stage & 2) {
#ifndef NDEBUG
            w_king_pst = dot_product(w, &E_KING_PST[0]);
            b_king_pst = -dot_product(flip_flop(b), &E_KING_PST[0]);
#endif // NDEBUG
            ret += dot_product(w, &E_KING_PST[0]);
            ret -= dot_product(flip_flop(b), &E_KING_PST[0]);

            /// if the game stage is opening or midgame
        } else {
#ifndef NDEBUG
            w_king_pst = dot_product(w, &M_KING_PST[0]);
            b_king_pst = -dot_product(flip_flop(b), &M_KING_PST[0]);
#endif // NDEBUG
            ret += dot_product(w, &M_KING_PST[0]);
            ret -= dot_product(flip_flop(b), &M_KING_PST[0]);
        }

        // penalty if not castled by mid game

        // pawn shield
        // - applicable when king has castled, so if the king hasn't castled

#ifndef NDEBUG
        if (verbose) {
            es.printer.add("White King PST", w_king_pst);
            es.printer.add("Black King PST", b_king_pst);
        }
#endif // NDEBUG


        return ret;
    }