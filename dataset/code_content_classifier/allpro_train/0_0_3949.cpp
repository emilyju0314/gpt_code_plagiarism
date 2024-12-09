#include <iostream>
#include <vector>
#include <set>

using namespace std;

long long power(long long base, int exp) {
    long long ans = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            ans *= base;
        }
        base *= base;
        exp /= 2;
    }
    return ans;
}

int main() {
    int n, l, r;
    cin >> n >> l >> r;

    long long ans = 0;
    for (int i = 1; i <= r; i++) {
        long long current = 1;
        for (int j = 0; j < n; j++) {
            current *= i;
            if (current > r) {
                break;
            }
            if (current >= l) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}