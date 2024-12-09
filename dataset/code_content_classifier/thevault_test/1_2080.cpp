static uint translateKey(uint r){
    const uint log2N = 32;

    r = ((r >>  1) & 0x55555555) | ((r & 0x55555555) <<  1);
    r = ((r >>  2) & 0x33333333) | ((r & 0x33333333) <<  2);
    r = ((r >>  4) & 0x0F0F0F0F) | ((r & 0x0F0F0F0F) <<  4);
    r = ((r >>  8) & 0x00FF00FF) | ((r & 0x00FF00FF) <<  8);
    r = ((r >> 16) & 0x0000FFFF) | ((r & 0x0000FFFF) << 16);
    return r >> (32 - log2N);
}