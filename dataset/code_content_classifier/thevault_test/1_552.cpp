int bitscan_reverse(const Bitboard bb) {
#if defined (__GNUC__)
    return __builtin_clzll(bb);
#else
    /**
     * @author Eugene Nalimov
     */
    int result = 0;
    if (bb > 0xFFFFFFFF) {
        bb >>= 32;
        result = 32;
    }
    if (bb > 0xFFFF) {
        bb >>= 16;
        result += 16;
    }
    if (bb > 0xFF) {
        bb >>= 8;
        result += 8;
    }
    return result + ms1bTable[bb];
#endif // __GNUC__
}