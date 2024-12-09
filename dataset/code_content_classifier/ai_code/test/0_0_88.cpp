#include <iostream>
#include <vector>

using namespace std;

bool isPossibleToSplit(vector<int>& nums) {
    int n = nums.size();
    
    // Find the longest increasing subsequence of the sequence
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    // Calculate the XOR of the longest increasing subsequences
    int xr = 0;
    for (int i = 0; i < n; i++) {
        xr ^= dp[i];
    }
    
    return xr == 0;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        
        if (isPossibleToSplit(nums)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}