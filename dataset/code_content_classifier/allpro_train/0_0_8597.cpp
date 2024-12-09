#include <iostream>
using namespace std;

const int MOD = 1000000009;

int main() {
    int n;
    cin >> n;

    long long ans = 0;
    long long current = 6; // for n = 2

    for (int i = 4; i <= n; i += 2) {
        ans = (current * 4) % MOD;
        current = (current * 4 + ans) % MOD;
    }

    cout << current << endl;

    return 0;
}