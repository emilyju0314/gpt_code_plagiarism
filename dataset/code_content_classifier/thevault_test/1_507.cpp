Bitboard bishop_moves(Square_t sq, Bitboard occ) {
#ifdef USE_SSE
    #if defined (__GNUC__)
#if defined (__BMI2__)
    return attacks_bishop(sq, occ);
#endif // __BMI2__
#endif // __GNUC__
#else
    return diag_mask(sq, occ);
#endif // USE_SSE
}