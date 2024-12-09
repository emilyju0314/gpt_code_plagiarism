static size_t parse_chunk(char *buf, size_t len, char **chunk_data,
                          size_t *chunk_len) {
    unsigned char *s = (unsigned char *) buf;
    size_t n = 0; /* scanned chunk length */
    size_t i = 0; /* index in s */

    /* Scan chunk length. That should be a hexadecimal number. */
    while (i < len && isxdigit(s[i])) {
        n *= 16;
        n += (s[i] >= '0' && s[i] <= '9') ? s[i] - '0' : tolower(s[i]) - 'a' + 10;
        i++;
    }

    /* Skip new line */
    if (i == 0 || i + 2 > len || s[i] != '\r' || s[i + 1] != '\n') {
        return 0;
    }
    i += 2;

    /* Record where the data is */
    *chunk_data = (char *) s + i;
    *chunk_len = n;

    /* Skip data */
    i += n;

    /* Skip new line */
    if (i == 0 || i + 2 > len || s[i] != '\r' || s[i + 1] != '\n') {
        return 0;
    }
    return i + 2;
}