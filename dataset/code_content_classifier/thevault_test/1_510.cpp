Bitboard knight_moves(Bitboard knights) {
    Square_t square = bitscan_forward(knights);
    Bitboard ret = 0;
    for ( ; knights != 0; knights -= C64(1) << square) {
        ret |= KNIGHT_ATTACK_ARRAY[square];
    }
    return ret;
}