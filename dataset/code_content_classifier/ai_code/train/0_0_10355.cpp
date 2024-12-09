#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<bool> dp(k+1, false);
    dp[0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = k; j >= coins[i]; j--) {
            if (dp[j - coins[i]]) {
                dp[j] = true;
            }
        }
    }

    vector<int> result;
    for (int i = 0; i <= k; i++) {
        if (dp[i]) {
            result.push_back(i);
        }
    }

    cout << result.size() << endl;
    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}