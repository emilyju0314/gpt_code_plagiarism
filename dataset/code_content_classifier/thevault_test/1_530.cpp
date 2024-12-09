void gen_all_moves(Board& board, std::vector<ChessMove>& movelist) {
    internal::gen_pawn_cap(board, movelist);
    internal::gen_pawn_quiet(board, movelist);
    internal::gen_pawn_prom(board, movelist);
    internal::gen_ep_cap(board, movelist);
    internal::gen_rook_cap(board, movelist);
    internal::gen_rook_quiet(board, movelist);
    internal::gen_knight_cap(board, movelist);
    internal::gen_knight_quiet(board, movelist);
    internal::gen_bishop_cap(board, movelist);
    internal::gen_bishop_quiet(board, movelist);
    internal::gen_queen_cap(board, movelist);
    internal::gen_queen_quiet(board, movelist);
    internal::gen_king_cap(board, movelist);
    internal::gen_king_quiet(board, movelist); // 5
    internal::gen_castle(board, movelist);
}