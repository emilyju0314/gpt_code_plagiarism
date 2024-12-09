static size_t coap_get_ext_opt_size(uint32_t value) {
    int ret = 0;

    if (value >= 13 && value <= 0xFF + 13) {
        ret = sizeof(uint8_t);
    } else if (value > 0xFF + 13 && value <= 0xFFFF + 269) {
        ret = sizeof(uint16_t);
    }

    return ret;
}