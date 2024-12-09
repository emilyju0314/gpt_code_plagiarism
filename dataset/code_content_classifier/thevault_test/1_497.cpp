void def_stage(const Board& board, EvaluationState& es) {
        auto m = material(board, es, WHITE, false) + material(board, es, BLACK, false);

        if (m > 6600) {
            es.stage = OPENING;
        } else if (m > 4000) {
            es.stage = MID_GAME;
        } else if (m > 2000) {
            es.stage = EARLY_END_GAME;
        } else {
            es.stage = LATE_END_GAME;
        }
    }