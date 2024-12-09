#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MOD = 998244353;

int gcdExtended(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1;
    int gcd = gcdExtended(b % a, a, x1, y1);

    x = y1 - (b/a) * x1;
    y = x1;

    return gcd;
}

int modInverse(int a, int m) {
    int x, y;
    int gcd = gcdExtended(a, m, x, y);

    if (gcd != 1) {
        return -1;
    } else {
        return (x % m + m) % m;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> liked(n);
    vector<int> weights(n);

    for (int i = 0; i < n; i++) {
        cin >> liked[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    int total_sum = 0;
    for (int i = 0; i < n; i++) {
        total_sum += weights[i];
    }

    for (int i = 0; i < m; i++) {
        int total_weight = 0;
        for (int j = 0; j < n; j++) {
            if (liked[j] == 1) {
                total_weight += weights[j] + 1;
            } else {
                total_weight += weights[j] - 1;
            }
        }

        vector<int> new_weights(n);

        for (int j = 0; j < n; j++) {
            if (liked[j] == 1) {
                new_weights[j] = (weights[j] + 1) * modInverse(total_weight, MOD) % MOD;
            } else {
                new_weights[j] = (weights[j] - 1) * modInverse(total_weight, MOD) % MOD;
            }

            weights[j] = new_weights[j];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << weights[i] << endl;
    }

    return 0;
}