#include <iostream>
#include <vector>
#define MOD 998244353
using namespace std;

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return (n * factorial(n - 1)) % MOD;
}

int modularExponentiation(int base, int exponent) {
    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exponent /= 2;
    }
    return result;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> cards(n);
        for (int i = 0; i < n; i++) {
            cin >> cards[i];
        }

        int odd_sum = 0, even_sum = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                even_sum += cards[i];
            } else {
                odd_sum += cards[i];
            }
        }

        int diff = abs(even_sum - odd_sum) % 11;
        if (diff == 0) {
            int num_dup = 1;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (cards[i] == cards[j]) {
                        num_dup++;
                    }
                }
            }

            int result = factorial(n);
            for (int i = 1; i <= num_dup; i++) {
                result = (result * modularExponentiation(i, MOD - 2)) % MOD;
            }

            cout << result << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}