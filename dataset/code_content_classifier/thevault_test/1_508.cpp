Bitboard rook_moves(Square_t sq, Bitboard occ) {
#ifdef USE_SSE
    #if defined (__GNUC__)
#if defined (__BMI2__)
    return attacks_rook(sq, occ);
#endif // __BMI2__
#endif // __GNUC__
#else
    return horzvert_mask(sq, occ);
#endif
}