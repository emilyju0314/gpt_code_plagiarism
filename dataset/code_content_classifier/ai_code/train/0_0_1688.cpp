#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<bool> dp(m, false);
    dp[0] = true;
    for(int i = 0; i < n; i++) {
        for(int j = m - 1; j >= nums[i]; j--) {
            if(dp[j - nums[i]]) {
                dp[j] = true;
            }
        }
    }

    if(dp[m - 1]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}