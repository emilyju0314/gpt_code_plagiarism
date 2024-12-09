static int coap_split_opt(uint32_t value, uint8_t *base, uint16_t *ext) {
    int ret = 0;

    if (value < 13) {
        *base = value;
    } else if (value >= 13 && value <= 0xFF + 13) {
        *base = 13;
        *ext = value - 13;
        ret = sizeof(uint8_t);
    } else if (value > 0xFF + 13 && value <= 0xFFFF + 269) {
        *base = 14;
        *ext = value - 269;
        ret = sizeof(uint16_t);
    }

    return ret;
}