static char *coap_add_uint16(char *ptr, uint16_t val) {
    *ptr = val >> 8;
    ptr++;
    *ptr = val & 0x00FF;
    ptr++;
    return ptr;
}