void gen_pawn_prom(Board& board, std::vector<ChessMove>& movelist) {
        Bitboard push_pawn;
        Square_t to_sq;
        PieceType_t ptc;

        if (board.side_2_move() == WHITE) {
            push_pawn = (board.piece_bb(W_PAWN) << 9) & board.capturable(BLACK) & RANK_MASK[RANK8] & ~FILE_MASK[FILEA];
            while (push_pawn) {
                to_sq = bitscan_forward(push_pawn);
                ptc = board.piece_type(to_sq, BLACK);
                movelist.emplace_back(ChessMove(to_sq - 9, to_sq, QUEEN_PROMO_CAPTURE, W_PAWN, ptc));
                movelist.emplace_back(ChessMove(to_sq - 9, to_sq, KNIGHT_PROMO_CAPTURE, W_PAWN, ptc));
                movelist.emplace_back(ChessMove(to_sq - 9, to_sq, ROOK_PROMO_CAPTURE, W_PAWN, ptc));
                movelist.emplace_back(ChessMove(to_sq - 9, to_sq, BISHOP_PROMO_CAPTURE, W_PAWN, ptc));
                push_pawn -= C64(1) << to_sq;
            }
            push_pawn = (board.piece_bb(W_PAWN) << 7) & board.capturable(BLACK) & RANK_MASK[RANK8] & ~FILE_MASK[FILEH];
            while (push_pawn) {
                to_sq = bitscan_forward(push_pawn);
                ptc = board.piece_type(to_sq, BLACK);
                movelist.emplace_back(ChessMove(to_sq - 7, to_sq, QUEEN_PROMO_CAPTURE, W_PAWN, ptc));
                movelist.emplace_back(ChessMove(to_sq - 7, to_sq, KNIGHT_PROMO_CAPTURE, W_PAWN, ptc));
                movelist.emplace_back(ChessMove(to_sq - 7, to_sq, ROOK_PROMO_CAPTURE, W_PAWN, ptc));
                movelist.emplace_back(ChessMove(to_sq - 7, to_sq, BISHOP_PROMO_CAPTURE, W_PAWN, ptc));
                push_pawn -= C64(1) << to_sq;
            }
            push_pawn = (board.piece_bb(W_PAWN) << 8) & board.empty_bb() & RANK_MASK[RANK8];
            while (push_pawn) {
                to_sq = bitscan_forward(push_pawn);
                movelist.emplace_back(ChessMove(to_sq - 8, to_sq, QUEEN_PROMO, W_PAWN, NO_PIECE));
                movelist.emplace_back(ChessMove(to_sq - 8, to_sq, KNIGHT_PROMO, W_PAWN, NO_PIECE));
                movelist.emplace_back(ChessMove(to_sq - 8, to_sq, ROOK_PROMO, W_PAWN, NO_PIECE));
                movelist.emplace_back(ChessMove(to_sq - 8, to_sq, BISHOP_PROMO, W_PAWN, NO_PIECE));
                push_pawn -= C64(1) << to_sq;
            }
        } else {
            push_pawn = (board.piece_bb(B_PAWN) >> 9) & (board.capturable(WHITE) & RANK_MASK[RANK1] & ~FILE_MASK[FILEH]);
            while (push_pawn) {
                to_sq = bitscan_forward(push_pawn);
                ptc = board.piece_type(to_sq, WHITE);
                movelist.emplace_back(ChessMove(to_sq + 9, to_sq, QUEEN_PROMO_CAPTURE, B_PAWN, ptc));
                movelist.emplace_back(ChessMove(to_sq + 9, to_sq, KNIGHT_PROMO_CAPTURE, B_PAWN, ptc));
                movelist.emplace_back(ChessMove(to_sq + 9, to_sq, ROOK_PROMO_CAPTURE, B_PAWN, ptc));
                movelist.emplace_back(ChessMove(to_sq + 9, to_sq, BISHOP_PROMO_CAPTURE, B_PAWN, ptc));
                push_pawn -= C64(1) << to_sq;
            }
            push_pawn = (board.piece_bb(B_PAWN) >> 7) & (board.capturable(WHITE) & RANK_MASK[RANK1] & ~FILE_MASK[FILEA]);
            while (push_pawn) {
                to_sq = bitscan_forward(push_pawn);
                ptc = board.piece_type(to_sq, WHITE);
                movelist.emplace_back(ChessMove(to_sq + 7, to_sq, QUEEN_PROMO_CAPTURE, B_PAWN, ptc));
                movelist.emplace_back(ChessMove(to_sq + 7, to_sq, KNIGHT_PROMO_CAPTURE, B_PAWN, ptc));
                movelist.emplace_back(ChessMove(to_sq + 7, to_sq, ROOK_PROMO_CAPTURE, B_PAWN, ptc));
                movelist.emplace_back(ChessMove(to_sq + 7, to_sq, BISHOP_PROMO_CAPTURE, B_PAWN, ptc));
                push_pawn -= C64(1) << to_sq;
            }
            push_pawn = (board.piece_bb(B_PAWN) >> 8) & (board.empty_bb() & RANK_MASK[RANK1]);
            while (push_pawn) {
                to_sq = bitscan_forward(push_pawn);
                movelist.emplace_back(ChessMove(to_sq + 8, to_sq, QUEEN_PROMO, B_PAWN, NO_PIECE));
                movelist.emplace_back(ChessMove(to_sq + 8, to_sq, KNIGHT_PROMO, B_PAWN, NO_PIECE));
                movelist.emplace_back(ChessMove(to_sq + 8, to_sq, ROOK_PROMO, B_PAWN, NO_PIECE));
                movelist.emplace_back(ChessMove(to_sq + 8, to_sq, BISHOP_PROMO, B_PAWN, NO_PIECE));
                push_pawn -= C64(1) << to_sq;
            }
        }
    }