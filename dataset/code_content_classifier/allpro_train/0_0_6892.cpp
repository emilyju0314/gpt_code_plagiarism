#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int k;
    cin >> k;

    long long ans = 1;
    for (int i = 0; i < k; i++) {
        ans = (ans * 2) % MOD;
    }

    cout << ans << endl;

    return 0;
}