#include <iostream>
#include <vector>

using namespace std;

bool canWin(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n));
    
    for (int i = 0; i < n; i++) {
        dp[i][i] = nums[i];
    }
    
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
        }
    }
    
    return dp[0][n-1] >= 0;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    if (canWin(nums)) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }
    
    return 0;
}