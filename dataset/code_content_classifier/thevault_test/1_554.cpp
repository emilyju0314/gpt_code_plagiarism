Bitboard north_fill(Bitboard bb) {
    bb |= (bb << (unsigned)8);
    bb |= (bb << (unsigned)16);
    bb |= (bb << (unsigned)32);
    return bb;
}