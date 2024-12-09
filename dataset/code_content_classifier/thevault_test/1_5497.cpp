void Computer::executeCHAR() {
    int32_t num = std::abs(rA.value());
    for (int i = 5; i >= 1; --i) {
        rX[i] = 30 + num % 10;
        num /= 10;
    }
    for (int i = 5; i >= 1; --i) {
        rA[i] = 30 + num % 10;
        num /= 10;
    }
}