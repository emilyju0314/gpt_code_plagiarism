int32_t Computer::checkRange(int32_t value, int bytes) {
    int32_t range = 1 << (6 * bytes);
    if (std::abs(value) >= range) {
        if (bytes == 5) {
            overflow = true;
        }
        value %= range;
    }
    return value;
}