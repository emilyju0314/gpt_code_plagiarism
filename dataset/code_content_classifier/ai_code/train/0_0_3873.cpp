#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9+7;

int main() {
    int H;
    cin >> H;

    int L = 1 << (H-1);
    vector<int> P(L);
    for(int i = 0; i < L; i++) {
        cin >> P[i];
    }

    long long ans = 0;

    for(int i = 0; i < L; i++) {
        int cycle_start = i;
        int j = i;
        long long product = 1;
        for(int k = 0; k < 2; k++) {
            j = (L + P[j] - 1) % L;
            product = (product * (cycle_start + 1) % MOD) % MOD;
        }

        ans = (ans + product) % MOD;
    }

    cout << ans << endl;

    return 0;
}