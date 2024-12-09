#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] % nums[j] != 0 || nums[i] / nums[j] != k) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int maxSubsetSize = *max_element(dp.begin(), dp.end());
    cout << maxSubsetSize << endl;

    return 0;
}