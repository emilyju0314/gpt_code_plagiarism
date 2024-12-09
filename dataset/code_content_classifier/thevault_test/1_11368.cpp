void composite(uint8_t *a, uint8_t *b, uint8_t *dst) {
    uint8_t alpha = b[3];
    dst[0] = (alpha * b[0] + (256 - alpha) * a[0]) >> 8;
    dst[1] = (alpha * b[1] + (256 - alpha) * a[1]) >> 8;
    dst[2] = (alpha * b[2] + (256 - alpha) * a[2]) >> 8;
    dst[3] = 0xff;
}