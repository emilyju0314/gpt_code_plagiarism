#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    long long n, k;
    cin >> n >> k;

    long long ans = 1;
    for (int i = 0; i < min(n, (long long) 60); i++) {
        ans = (ans * k) % MOD;
    }

    cout << ans << endl;

    return 0;
}