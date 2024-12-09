#include <iostream>
#include <cmath>

using namespace std;

uint32_t fast_pow(uint32_t base, uint32_t exp) {
    uint32_t result = 1;
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % (1UL << 32);
        }
        base = (base * base) % (1UL << 32);
        exp >>= 1;
    }
    return result;
}

int main() {
    int n, A, B, C, D;
    cin >> n >> A >> B >> C >> D;

    // Calculate f(x) for x = 1, 2, 3
    uint32_t f1 = (A * 1 + B) % (1UL << 32);
    uint32_t f2 = (A * fast_pow(2, 3) + B * fast_pow(2, 2) + C * 2 + D) % (1UL << 32);
    uint32_t f3 = (A * fast_pow(3, 3) + B * fast_pow(3, 2) + C * 3 + D) % (1UL << 32);

    uint32_t answer = 0;
    for (int i = 1; i <= n; i++) {
        uint32_t exlog_fi;
        if (i == 1) {
            exlog_fi = 0;
        } else if (i == 2) {
            exlog_fi = f1;
        } else if (i == 3) {
            exlog_fi = f2;
        } else {
            exlog_fi = (A * f1 + B * f2 + C * f3 + D) % (1UL << 32);
            f1 = f2;
            f2 = f3;
            f3 = exlog_fi;
        }
        answer = (answer + exlog_fi) % (1UL << 32);
    }

    cout << answer << endl;

    return 0;
}