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
    
    int min_m = nums[n-1] - nums[0];
    for (int i = 1; i <= k; i++) {
        vector<int> diff(n-1);
        for (int j = 0; j < n-1; j++) {
            diff[j] = nums[j+1] - nums[j];
        }
        sort(diff.begin(), diff.end());
        min_m = min(min_m, diff[n-i-1]);
    }

    cout << min_m << endl;

    return 0;
}