#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canSplitSequence(vector<int>& a) {
    int n = a.size();
    vector<int> lis(n);
    vector<int> dp(n+1, 1e9);
    dp[0] = -1;
    
    for (int i = 0; i < n; i++) {
        int j = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        lis[i] = j;
        dp[j] = a[i];
    }
    
    int xorResult = 0;
    for (int i = 0; i < n; i++) {
        xorResult ^= lis[i];
    }
    
    return xorResult == 0;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        if (canSplitSequence(a)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}