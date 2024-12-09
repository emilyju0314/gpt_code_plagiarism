#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void possibleValues(int coins[], int n, int k) {
    vector<int> dp(k + 1, 0);
    dp[0] = 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = k; j >= coins[i]; j--) {
            dp[j] = dp[j] || dp[j - coins[i]];
        }
    }
    
    vector<int> values;
    for (int i = 0; i <= k; i++) {
        if (dp[i]) {
            values.push_back(i);
        }
    }
    
    cout << values.size() << endl;
    for (int val : values) {
        cout << val << " ";
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    int coins[n];
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    possibleValues(coins, n, k);
    
    return 0;
}