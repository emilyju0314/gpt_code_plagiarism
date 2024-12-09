Bitboard diag_mask(Square_t sq, Bitboard occupied) {
    Bitboard bb = C64(1) << sq;
    Bitboard occ = occupied;
    Bitboard shifted_bb = 2 * bb;
    Bitboard reverse_bb = reverse(bb);
    Bitboard shifted_rev_bb = 2 * reverse_bb;
    Bitboard diag_mask = DIAGONAL_MASK[(sq / 8) + (sq % 8)];
    Bitboard anti_diag_mask = ANTI_DIAGONAL_MASK[(sq / 8) + 7 - (sq % 8)];

    Bitboard diagonalBB = ((occ & diag_mask) - (shifted_bb)) ^ reverse(reverse(occ & diag_mask) - (shifted_rev_bb));
    Bitboard antiDiagonalBB = ((occ & anti_diag_mask) - (shifted_bb)) ^ reverse(reverse(occ & anti_diag_mask) - (shifted_rev_bb));
    return (diagonalBB & diag_mask) | (antiDiagonalBB & anti_diag_mask);
}