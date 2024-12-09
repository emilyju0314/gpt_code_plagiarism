int bitscan_forward(const Bitboard bb) {
#if defined (__GNUC__)
    return __builtin_ctzll(bb);
#else
    /**
     * @author Gerd Isenberg
     */
    unsigned int lsb;
    assert (bb != 0);
    bb &= -bb; // LS1B-Isolation
    lsb = (unsigned)bb | (unsigned)(bb>>32);
    return (((((((((((unsigned)(bb>>32) !=0)  * 2)
                 + ((lsb & 0xffff0000) !=0)) * 2)
                 + ((lsb & 0xff00ff00) !=0)) * 2)
                 + ((lsb & 0xf0f0f0f0) !=0)) * 2)
                 + ((lsb & 0xcccccccc) !=0)) * 2)
                 + ((lsb & 0xaaaaaaaa) !=0);
#endif // __GNUC__
}