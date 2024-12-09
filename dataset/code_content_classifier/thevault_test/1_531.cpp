void gen_all_caps(Board& board, std::vector<ChessMove>& movelist) {
    internal::gen_pawn_cap(board, movelist);
    internal::gen_pawn_prom(board, movelist);
    internal::gen_ep_cap(board, movelist);
    internal::gen_rook_cap(board, movelist);
    internal::gen_knight_cap(board, movelist);
    internal::gen_bishop_cap(board, movelist);
    internal::gen_queen_cap(board, movelist);
    internal::gen_king_cap(board, movelist);
}