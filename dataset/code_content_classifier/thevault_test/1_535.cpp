std::optional<ChessMove> algnot_to_chessmove(Board& board, std::string algnot) {
    std::vector<ChessMove> movelist;
    movelist.reserve(128);
    gen_all_moves(board, movelist); // generate all the chess moves from the given locations

    for (int i = 0; i < movelist.size(); ++i) {
        if (algnot == movelist[i].to_algebraic_notation()) {
            // the the chess move's algebraic notation string matches the input string, then return that chessmove
            return movelist[i];
        } else if (algnot[algnot.size() - 1] == '+') {
            // the ChessMove algebraic notation interface doesn't put '+' to denote checks, so it is possible that
            // the input string corresponds with this ChessMove, but the nominal string check won't check for that.
            // so in that case remove the '+' from the input move and check for correspondence again
            std::string substring = std::string(algnot.begin(), algnot.end() - 1);
            if (substring == movelist[i].to_algebraic_notation()) {
                return movelist[i];
            }
        }
    }

    return std::nullopt;
}