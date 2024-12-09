Bitboard horzvert_mask(Square_t sq, Bitboard occupied) {
    Bitboard bb = C64(1) << sq;
    Bitboard occ = occupied;
    Bitboard shifted_bb = 2 * bb;
    Bitboard reverse_bb = reverse(bb);
    Bitboard shifted_rev_bb = 2 * reverse_bb;
    Bitboard file_bb = FILE_MASK[sq % 8];
    Bitboard rank_bb = RANK_MASK[sq / 8];

    Bitboard horiz_bb = (occ - shifted_bb) ^ reverse(reverse(occ) - shifted_rev_bb);
    Bitboard vert_bb = ((occ & file_bb) - (shifted_bb)) ^ reverse(reverse(occ & file_bb) - (shifted_rev_bb));
    return (horiz_bb & rank_bb) | (vert_bb & file_bb);
}