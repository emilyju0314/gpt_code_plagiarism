int GetExternalIPbySTUN(uint64_t rnd, struct sockaddr_in *mapped, const char **srv) {
    randfiller    = rnd;
    uint16_t pos  = rnd;
    uint16_t step;
    do {
        rnd = (rnd >> 8) | 0xff00000000000000LL;
        step = rnd % StunSrvListQty;
    } while(step == 0);

    int attempt; // runs in 8 birs offset, for keep flags in low byte
    for(attempt = 256; attempt < StunSrvListQty * 2 * 256; attempt += 256) {
        pos = (pos + step) % StunSrvListQty;
        int rc = StunRequest(*srv = StunSrvList[pos].name, StunSrvList[pos].port, mapped);
        if(rc > 0)
            return attempt | rc;
    }
    return -1;
}