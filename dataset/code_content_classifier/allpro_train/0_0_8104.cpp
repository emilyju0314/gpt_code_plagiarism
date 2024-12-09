long long power(long long x, long long y, long long mod) {
    long long res = 1;
    x = x % mod;

    while (y > 0) {
        if (y % 2 == 1) {
            res = (res * x) % mod;
        }
        y = y / 2;
        x = (x * x) % mod;
    }

    return res;
}