void gen_queen_cap(Board& board, std::vector<ChessMove>& movelist){
        Bitboard push_queen;
        Bitboard queen_bb;
        Square_t from_sq;
        Square_t to_sq;
        PieceType_t ptc;

        if (board.side_2_move() == WHITE) {
            queen_bb = board.piece_bb(W_QUEEN);
            while (queen_bb) {
                from_sq = bitscan_forward(queen_bb);
                push_queen = queen_moves(from_sq, board.occupied_bb()) & board.capturable(BLACK);
                while (push_queen) {
                    to_sq = bitscan_forward(push_queen);
                    ptc = board.piece_type(to_sq, BLACK);
                    movelist.emplace_back(ChessMove(from_sq, to_sq, CAPTURE_MOVE, W_QUEEN, ptc));
                    push_queen -= (C64(1) << to_sq);
                }
                queen_bb -= (C64(1) << from_sq);
            }
        } else {
            queen_bb = board.piece_bb(B_QUEEN );
            while (queen_bb) {
                from_sq = bitscan_forward(queen_bb);
                push_queen = queen_moves(from_sq, board.occupied_bb()) & board.capturable(WHITE);
                while (push_queen) {
                    to_sq = bitscan_forward(push_queen);
                    ptc = board.piece_type(to_sq, WHITE);
                    movelist.emplace_back(ChessMove(from_sq, to_sq, CAPTURE_MOVE, B_QUEEN , ptc));
                    push_queen -= (C64(1) << to_sq);
                }
                queen_bb -= (C64(1) << from_sq);
            }
        }
    }