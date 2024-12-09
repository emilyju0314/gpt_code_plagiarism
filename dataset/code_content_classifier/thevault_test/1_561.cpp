Centipawns_t dot_product(Bitboard bb, const Centipawns_t* weights) {
    Bitboard bit = C64(1);
    int accu = 0;

    for (int sq = 0; sq < 64; ++sq, bit += bit) {
        accu += (bb & bit) ? (weights[sq] & -((bb & bit) == bit)) : (0);
    }

    return accu;
}