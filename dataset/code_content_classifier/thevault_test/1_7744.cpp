static string maskToVals(uint64_t mask, int64_t baseNum) {
    string out;
    while (mask > 0) {
        baseNum += log2(loc_get_least_bit(mask));
        out += baseNum + " ";
    }
    return out;
}