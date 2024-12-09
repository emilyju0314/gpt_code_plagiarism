void gen_bishop_cap(Board& board, std::vector<ChessMove>& movelist) {
        Bitboard push_bishop;
        Bitboard bishop_bb;
        Square_t from_sq;
        Square_t to_sq;
        PieceType_t ptc;

        if (board.side_2_move() == WHITE) {
            bishop_bb = board.piece_bb(W_BISHOP);
            while (bishop_bb) {
                from_sq = bitscan_forward(bishop_bb);
                push_bishop = bishop_moves(from_sq, board.occupied_bb()) & board.capturable(BLACK);
                while (push_bishop) {
                    to_sq = bitscan_forward(push_bishop);
                    ptc = board.piece_type(to_sq, BLACK);
                    movelist.emplace_back(ChessMove(from_sq, to_sq, CAPTURE_MOVE, W_BISHOP, ptc));
                    push_bishop -= (C64(1) << to_sq);
                }
                bishop_bb -= (C64(1) << from_sq);
            }
        } else {
            bishop_bb = board.piece_bb(B_BISHOP);
            while (bishop_bb) {
                from_sq = bitscan_forward(bishop_bb);
                push_bishop = bishop_moves(from_sq, board.occupied_bb()) & board.capturable(WHITE);
                while (push_bishop) {
                    to_sq = bitscan_forward(push_bishop);
                    ptc = board.piece_type(to_sq, WHITE);
                    movelist.emplace_back(ChessMove(from_sq, to_sq, CAPTURE_MOVE, B_BISHOP, ptc));
                    push_bishop -= (C64(1) << to_sq);
                }
                bishop_bb -= (C64(1) << from_sq);
            }
        }
    }