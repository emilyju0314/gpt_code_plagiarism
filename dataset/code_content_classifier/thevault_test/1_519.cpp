void gen_rook_cap(Board& board, std::vector<ChessMove>& movelist) {
        Bitboard push_rook;
        Bitboard rook_bb;
        Square_t from_sq;
        Square_t to_sq;
        PieceType_t ptc;

        if (board.side_2_move() == WHITE) {
            rook_bb = board.piece_bb(W_ROOK);
            while (rook_bb) {
                from_sq = bitscan_forward(rook_bb);
                push_rook = rook_moves(from_sq, board.occupied_bb()) & board.capturable(BLACK);
                while (push_rook) {
                    to_sq = bitscan_forward(push_rook);
                    ptc = board.piece_type(to_sq, BLACK);
                    movelist.emplace_back(ChessMove(from_sq, to_sq, CAPTURE_MOVE, W_ROOK, ptc));
                    push_rook -= (C64(1) << to_sq);
                }
                rook_bb -= (C64(1) << from_sq);
            }
        } else {
            rook_bb = board.piece_bb(B_ROOK);
            while (rook_bb) {
                from_sq = bitscan_forward(rook_bb);
                push_rook = rook_moves(from_sq, board.occupied_bb()) & board.capturable(WHITE);
                while (push_rook) {
                    to_sq = bitscan_forward(push_rook);
                    ptc = board.piece_type(to_sq, WHITE);
                    movelist.emplace_back(ChessMove(from_sq, to_sq, CAPTURE_MOVE, B_ROOK, ptc));
                    push_rook -= (C64(1) << to_sq);
                }
                rook_bb -= (C64(1) << from_sq);
            }
        }
    }