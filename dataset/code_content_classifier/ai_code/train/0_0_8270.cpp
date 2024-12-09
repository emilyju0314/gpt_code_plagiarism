#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

int main() {
    int k;
    cin >> k;

    vector<int> colors(k);
    for (int i = 0; i < k; i++) {
        cin >> colors[i];
    }

    sort(colors.begin(), colors.end(), greater<int>());

    int ans = 1;
    for (int i = 0; i < k - 1; i++) {
        for (int j = 0; j < colors[i] - 1; j++) {
            ans = (ans * colors[i + 1] % MOD) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}