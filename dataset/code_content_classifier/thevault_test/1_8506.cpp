static int coap_get_ext_opt(char *ptr, struct mbuf *io, uint16_t *opt_info) {
    int ret = 0;

    if (*opt_info == 13) {
        /*
         * 13:  An 8-bit unsigned integer follows the initial byte and
         * indicates the Option Delta/Length minus 13.
         */
        if (ptr < io->buf + io->len) {
            *opt_info = (uint8_t) *ptr + 13;
            ret = sizeof(uint8_t);
        } else {
            ret = -1; /* LCOV_EXCL_LINE */
        }
    } else if (*opt_info == 14) {
        /*
         * 14:  A 16-bit unsigned integer in network byte order follows the
         * initial byte and indicates the Option Delta/Length minus 269.
         */
        if (ptr + sizeof(uint8_t) < io->buf + io->len) {
            *opt_info = ((uint8_t) *ptr << 8 | (uint8_t) * (ptr + 1)) + 269;
            ret = sizeof(uint16_t);
        } else {
            ret = -1; /* LCOV_EXCL_LINE */
        }
    }

    return ret;
}