Bitboard flip_flop(Bitboard bb) {
    bb = flip_vertically(bb);
    bb = mirror(bb);
    return bb;
}