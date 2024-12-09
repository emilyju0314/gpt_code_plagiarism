void gen_knight_cap(Board& board, std::vector<ChessMove>& movelist){
        Bitboard push_knight;
        Bitboard knight_bb;
        Square_t from_sq;
        Square_t to_sq;
        PieceType_t ptc;

        if (board.side_2_move() == WHITE) {
            knight_bb = board.piece_bb(W_KNIGHT);
            while (knight_bb) {
                from_sq = bitscan_forward(knight_bb);
                push_knight = knight_moves(C64(1) << from_sq) & board.capturable(BLACK);
                while (push_knight) {
                    to_sq = bitscan_forward(push_knight);
                    ptc = board.piece_type(to_sq, BLACK);
                    movelist.emplace_back(ChessMove(from_sq, to_sq, CAPTURE_MOVE, W_KNIGHT, ptc));
                    push_knight -= (C64(1) << to_sq);
                }
                knight_bb -= (C64(1) << from_sq);
            }
        } else {
            knight_bb = board.piece_bb(B_KNIGHT);
            while (knight_bb) {
                from_sq = bitscan_forward(knight_bb);
                push_knight = knight_moves(C64(1) << from_sq) & board.capturable(WHITE);
                while (push_knight) {
                    to_sq = bitscan_forward(push_knight);
                    ptc = board.piece_type(to_sq, WHITE);
                    movelist.emplace_back(ChessMove(from_sq, to_sq, CAPTURE_MOVE, B_KNIGHT, ptc));
                    push_knight -= (C64(1) << to_sq);
                }
                knight_bb -= (C64(1) << from_sq);
            }
        }
    }