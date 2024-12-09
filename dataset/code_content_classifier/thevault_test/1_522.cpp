void gen_knight_quiet(Board& board, std::vector<ChessMove>& movelist){
        Bitboard push_knight;
        Bitboard knight_bb;
        Square_t from_sq;
        Square_t to_sq;

        if (board.side_2_move() == WHITE) {
            knight_bb = board.piece_bb(W_KNIGHT);
            while (knight_bb) {
                from_sq = bitscan_forward(knight_bb);
                push_knight = knight_moves(C64(1) << from_sq) & board.empty_bb(); // shouldn't i just use the empty bitboard rather than the occupied one?; save 1 clock cycle
                // push_knight = knight_moves(knight_bb) & board.empty_bb();
                while (push_knight) {
                    to_sq = bitscan_forward(push_knight);
                    movelist.emplace_back(ChessMove(from_sq, to_sq, QUIET_MOVE, W_KNIGHT, NO_PIECE));
                    push_knight -= (C64(1) << to_sq);
                }
                knight_bb -= (C64(1) << from_sq);
            }
        } else {
            knight_bb = board.piece_bb(B_KNIGHT);
            while (knight_bb) {
                from_sq = bitscan_forward(knight_bb);
                push_knight = knight_moves(C64(1) << from_sq) & board.empty_bb();
                // push_knight = knight_moves(knight_bb) & board.empty_bb();
                while (push_knight) {
                    to_sq = bitscan_forward(push_knight);
                    movelist.emplace_back(ChessMove(from_sq, to_sq, QUIET_MOVE, B_KNIGHT, NO_PIECE));
                    push_knight -= (C64(1) << to_sq);
                }
                knight_bb -= (C64(1) << from_sq);
            }
        }
    }