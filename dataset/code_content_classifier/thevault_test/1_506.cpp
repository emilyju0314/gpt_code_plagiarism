Centipawns_t evaluate(const Board& board, EvaluationState& es, bool verbose) {
    internal::def_stage(board, es);
    internal::def_pos_type(board, es);

    Centipawns_t ret = internal::material(board, es, Color::BOTH, verbose);
    ret += internal::eval_pawns(board, es, verbose);
    ret += internal::eval_rooks(board, es, verbose);
    ret += internal::eval_knights(board, es, verbose);
    ret += internal::eval_bishop(board, es, verbose);
    ret += internal::eval_queens(board, es, verbose);
    ret += internal::eval_kings(board, es, verbose);
    ret += internal::eval_tempo(board, es, verbose);
    if (es.stage == OPENING) {
        ret += internal::eval_overall_development(board, es, verbose);
    }

    if (board.side_2_move() == BLACK) {
        ret = -ret;
    }

    return ret;
}