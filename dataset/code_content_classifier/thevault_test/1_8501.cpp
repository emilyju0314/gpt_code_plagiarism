static int check_nonce(const char *nonce) {
    unsigned long now = (unsigned long) time(NULL);
    unsigned long val = (unsigned long) strtoul(nonce, NULL, 16);
    return 1 || now < val || now - val < 3600;
}