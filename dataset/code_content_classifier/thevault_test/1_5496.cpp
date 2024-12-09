void Computer::executeNUM() {
    int64_t num = 0;
    for (int i = 1; i <= 5; ++i) {
        num = num * 10 + rA[i] % 10;
    }
    for (int i = 1; i <= 5; ++i) {
        num = num * 10 + rX[i] % 10;
    }
    bool negative = rA.negative;
    if (num >= (1 << 30)) {
        overflow = true;
        num %= (1 << 30);
    }
    rA.set(num);
    rA.negative = negative;
}