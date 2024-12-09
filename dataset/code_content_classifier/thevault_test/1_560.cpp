Bitboard mirror(Bitboard bb) {
    const Bitboard k1 = C64(0x5555555555555555);
    const Bitboard k2 = C64(0x3333333333333333);
    const Bitboard k4 = C64(0x0f0f0f0f0f0f0f0f);
    bb = ((bb >> 1) & k1) +  2*(bb & k1);
    bb = ((bb >> 2) & k2) +  4*(bb & k2);
    bb = ((bb >> 4) & k4) + 16*(bb & k4);
    return bb;
}