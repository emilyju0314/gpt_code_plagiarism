#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

long long power(long long base, long long exp) {
    if(exp == 0) return 1;
    if(exp % 2 == 0) {
        long long half = power(base, exp/2);
        return (half * half) % MOD;
    } else {
        return (base * power(base, exp-1)) % MOD;
    }
}

int main() {
    int n, m, k, r, c;
    cin >> n >> m >> k >> r >> c;

    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;

    int pattern_count = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            int color_count = min({ax + i, bx + i, n - r + 1, m - c + 1}) - max(ax, bx) + 1;
            long long combinations = power(k, (long long)color_count);
            pattern_count = (pattern_count + combinations) % MOD;
        }
    }

    cout << pattern_count << endl;

    return 0;
}