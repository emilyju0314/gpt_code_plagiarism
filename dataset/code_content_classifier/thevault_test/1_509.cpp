Bitboard queen_moves(Square_t sq, Bitboard occupied) {
#ifdef USE_SSE
    #if defined (__GNUC__)
#if defined (__BMI2__)
    return attacks_rook(sq, occupied) | attacks_bishop(sq, occupied);
#endif // __BMI2__
#endif // __GNUC__
#else
    return horzvert_mask(sq, occupied) | diag_mask(sq, occupied);
#endif
}