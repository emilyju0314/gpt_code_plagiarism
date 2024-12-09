static char *coap_add_opt_info(char *ptr, uint16_t val, size_t len) {
    if (len == sizeof(uint8_t)) {
        *ptr = val;
        ptr++;
    } else if (len == sizeof(uint16_t)) {
        ptr = coap_add_uint16(ptr, val);
    }

    return ptr;
}