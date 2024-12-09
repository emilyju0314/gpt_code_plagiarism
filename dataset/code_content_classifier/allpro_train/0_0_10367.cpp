#include <iostream>
#include <vector>

using namespace std;
const int MOD = 1e9 + 9;

int main() {
    int n, a, b, k;
    cin >> n >> a >> b >> k;

    string s;
    cin >> s;

    long long sum = 0;
    vector<int> powers(n+1, 1);
    int pa = 1;

    for (int i = 1; i <= n; i++) {
        pa = (pa * a) % MOD;
        powers[i] = pa;
    }

    int pb = 1;
    for (int i = 0; i < k; i++) {
        int sign = (s[i] == '+') ? 1 : -1;
        sum = (sum + 1LL * sign * powers[n - i] * pb) % MOD;
        pb = (pb * b) % MOD;
    }

    sum = ((sum % MOD) + MOD) % MOD; // To ensure non-negative result
    cout << sum << endl;

    return 0;
}