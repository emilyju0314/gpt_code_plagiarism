Centipawns_t material(const Board &board, EvaluationState &es, Color_t color, bool verbose) {
        Centipawns_t ret{0};

        if (verbose) {
#ifndef NDEBUG
            if (color == Color::BOTH) {
                // white bishops
                std::string param_name("White Bishop Material");
                Centipawns_t val = BISHOP_PERC[es.pos_type] * BISHOP_BASE_VAL * pop_count(board.piece_bb(W_BISHOP));
                es.printer.add(param_name, val);

                // black bishops
                param_name = "Black Bishop Material";
                val = BISHOP_PERC[es.pos_type] * BISHOP_BASE_VAL * pop_count(board.piece_bb(B_BISHOP));
                es.printer.add(param_name, -val);

                // w Knight
                param_name = "White Knight Material";
                val = KNIGHT_PERC[es.pos_type] * KNIGHT_BASE_VAL * pop_count(board.piece_bb(W_KNIGHT));
                es.printer.add(param_name, val);

                // b Knight
                param_name = "Black Knight Material";
                val = KNIGHT_PERC[es.pos_type] * KNIGHT_BASE_VAL * pop_count(board.piece_bb(B_KNIGHT));
                es.printer.add(param_name, -val);

                // w queen
                param_name = "White Queen Material";
                val = QUEEN_PERC[es.pos_type]  * QUEEN_BASE_VAL * pop_count(board.piece_bb(W_QUEEN));
                es.printer.add(param_name, val);

                // b queen
                param_name = "Black Queen Material";
                val = QUEEN_PERC[es.pos_type]  * QUEEN_BASE_VAL * pop_count(board.piece_bb(B_QUEEN));
                es.printer.add(param_name, -val);

                // w rook
                param_name = "White Rook Material";
                val = ROOK_PERC[es.pos_type]   * ROOK_BASE_VAL * pop_count(board.piece_bb(W_ROOK));
                es.printer.add(param_name, val);

                // b rook
                param_name = "Black Rook Material";
                val = ROOK_PERC[es.pos_type]   * ROOK_BASE_VAL * pop_count(board.piece_bb(B_ROOK));
                es.printer.add(param_name, -val);

                // w pawn
                param_name = "White Pawn Material";
                val = PAWN_STRENGTH[es.stage] * PAWN_BASE_VAL * pop_count(board.piece_bb(W_PAWN));
                es.printer.add(param_name, val);

                // b pawn
                param_name = "Black Pawn Material";
                val = PAWN_STRENGTH[es.stage] * PAWN_BASE_VAL * pop_count(board.piece_bb(B_PAWN));
                es.printer.add(param_name, -val);
            }
#endif // NDEBUG
        }

        if (color == WHITE) {
            ret = BISHOP_BASE_VAL * pop_count(board.piece_bb(W_BISHOP)) +
                  PAWN_BASE_VAL * pop_count(board.piece_bb(W_PAWN)) +
                  KNIGHT_BASE_VAL * pop_count(board.piece_bb(W_KNIGHT)) +
                  QUEEN_BASE_VAL * pop_count(board.piece_bb(W_QUEEN)) +
                  ROOK_BASE_VAL * pop_count(board.piece_bb(W_ROOK));
        } else if (color == BLACK) {
            ret = BISHOP_BASE_VAL * pop_count(board.piece_bb(B_BISHOP)) +
                  PAWN_BASE_VAL * pop_count(board.piece_bb(B_PAWN)) +
                  KNIGHT_BASE_VAL * pop_count(board.piece_bb(B_KNIGHT)) +
                  QUEEN_BASE_VAL * pop_count(board.piece_bb(B_QUEEN)) +
                  ROOK_BASE_VAL * pop_count(board.piece_bb(B_ROOK));
        } else {
            ret = BISHOP_PERC[es.pos_type] * BISHOP_BASE_VAL * (pop_count(board.piece_bb(W_BISHOP)) - pop_count(board.piece_bb(B_BISHOP))) +
                  KNIGHT_PERC[es.pos_type] * KNIGHT_BASE_VAL * (pop_count(board.piece_bb(W_KNIGHT)) - pop_count(board.piece_bb(B_KNIGHT))) +
                  QUEEN_PERC[es.pos_type]  * QUEEN_BASE_VAL  * (pop_count(board.piece_bb(W_QUEEN))  - pop_count(board.piece_bb(B_QUEEN))) +
                  ROOK_PERC[es.pos_type]   * ROOK_BASE_VAL   * (pop_count(board.piece_bb(W_ROOK))   - pop_count(board.piece_bb(B_ROOK)));

            ret += (PAWN_STRENGTH[es.stage] * PAWN_BASE_VAL * (pop_count(board.piece_bb(W_PAWN)) - pop_count(board.piece_bb((B_PAWN)))));
        }

        return ret;
    }