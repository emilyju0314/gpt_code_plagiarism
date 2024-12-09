Bitboard reverse(Bitboard bb) {
    for (int i = 0; i < 6; i++) {
        int s(1 << i);
        Bitboard f((Bitboard)(1) << s);
        Bitboard k((Bitboard)(-1) / (f + 1) );
        bb = ((bb >> s) & k) + f * (bb & k);
    }
    return bb;
}