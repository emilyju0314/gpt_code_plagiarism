#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

long long power(long long base, int exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<long long> ways(x + 1, 0);

    ways[0] = 1;

    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = i; k <= x; k++) {
                ways[k] = (ways[k] + ways[k - i]) % MOD;
            }
        }
    }

    long long answer = power(n, MOD - 2);

    for (int i = 1; i <= x; i++) {
        answer = (answer * ways[i]) % MOD;
    }

    cout << answer << endl;

    return 0;
}