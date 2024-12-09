int pop_count(const Bitboard bb) {
#if defined (__GNUC__)
    return __builtin_popcountll(bb);
#else
    /// need to implement my own version.
        return -1;
#endif // __GNUC__
}