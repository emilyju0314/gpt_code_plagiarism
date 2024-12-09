void gen_queen_quiet(Board& board, std::vector<ChessMove>& movelist){
        Bitboard push_queen;
        Bitboard queen_bb;
        Square_t from_sq;
        Square_t to_sq;

        if (board.side_2_move() == WHITE) {
            queen_bb = board.piece_bb(W_QUEEN );
            while (queen_bb) {
                from_sq = bitscan_forward(queen_bb);
                push_queen = queen_moves(from_sq, board.occupied_bb()) & board.empty_bb();
                while (push_queen) {
                    to_sq = bitscan_forward(push_queen);
                    movelist.emplace_back(ChessMove(from_sq, to_sq, QUIET_MOVE, W_QUEEN, NO_PIECE));
                    push_queen -= (C64(1) << to_sq);
                }
                queen_bb -= (C64(1) << from_sq);
            }
        } else {
            queen_bb = board.piece_bb(B_QUEEN );
            while (queen_bb) {
                from_sq = bitscan_forward(queen_bb);
                push_queen = queen_moves(from_sq, board.occupied_bb()) & board.empty_bb();
                while (push_queen) {
                    to_sq = bitscan_forward(push_queen);
                    movelist.emplace_back(ChessMove(from_sq, to_sq, QUIET_MOVE, B_QUEEN, NO_PIECE));
                    push_queen -= (C64(1) << to_sq);
                }
                queen_bb -= (C64(1) << from_sq);
            }
        }
    }