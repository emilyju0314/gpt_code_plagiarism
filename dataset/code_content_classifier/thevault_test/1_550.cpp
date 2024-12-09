std::string draw_bitboard(const Bitboard bb) noexcept {
    std::string ret("8 ");
    int i = 56;
    int k = 7;
    for (; i >= 0; i++) {
        ret += ((bb >> i) & 0x1) ? ("1 ") : ("0 ");

        if (i % 8 == 7) {
            ret += "\n";
            i -= 16;

            if (k > 0) {
                ret += std::to_string(k);
                ret += " ";
                k--;
            }
        }
    }

    ret += "  A B C D E F G H\n";
    return ret;
}