#include <iostream>
#include <vector>
#include <unordered_map>
#define MOD 998244353

using namespace std;

unordered_map<string, int> memo;

int countSequences(int n, int k, int x) {
    if (n == 1) {
        if (k == 0) return x == 0 ? 1 : 2;
        else return 1;
    }

    string key = to_string(n) + "_" + to_string(k) + "_" + to_string(x);
    if (memo.find(key) != memo.end()) return memo[key];

    long long res = 0;
    for (int bit = 0; bit < 2; bit++) {
        int newXor = x ^ bit;
        if (newXor % 2 == 1) {
            res += countSequences(n - 1, k - 1, newXor >> 1);
        } else {
            res += countSequences(n - 1, k, newXor >> 1);
        }
        res %= MOD;
    }

    memo[key] = res;
    return res;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k, x;
        cin >> n >> k >> x;

        long long result = countSequences(n, k, x);
        cout << result << endl;
    }

    return 0;
}