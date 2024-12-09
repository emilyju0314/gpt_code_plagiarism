void aligned_memcpy(void *to, const void *from, size_t size) {
    uint32_t *dst = (uint32_t *) to;
    uint32_t *src = (uint32_t *) from;
    int bitmask = sizeof(uint32_t) - 1;

    int di = (uintptr_t) dst & bitmask;
    int si = (uintptr_t) src & bitmask;
    dst = (uint32_t *) ((uintptr_t) dst & ~bitmask);
    src = (uint32_t *) ((uintptr_t) src & ~bitmask);

    uint32_t d_data = (di == 0)? 0 : *dst;
    uint32_t s_data = *src;
    src++;

    while (size > 0) {
        if (si > 3) {
            s_data = *src;
            src++;
            si = 0;
        }

        if (di > 3) {
            *dst = d_data;
            d_data = 0;
            dst++;
            di = 0;
        }
        d_data |= ((s_data >> (si * 8)) & 0xff) << (di * 8);
        si++;
        di++;
        size--;
    }

    if (di > 0) {
        uint32_t ranges[] = {0xff000000, 0xffff0000, 0xffffff00, 0x00000000};
        *dst = d_data | (*dst & ranges[di - 1]);
    }
}