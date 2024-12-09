#include <iostream>
#include <vector>

using namespace std;

bool is_beautiful(vector<long long> nums, long long d) {
    for (int i = 0; i < nums.size() - 1; i++) {
        if ((nums[i] % d == 0 && nums[i+1] % d == 0) || 
            (nums[i] % d != 0 && nums[i+1] % d != 0)) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        long long result = 0;

        for (int i = 0; i < n; i++) {
            if (nums[0] % nums[i] == 0) {
                if (is_beautiful(nums, nums[i])) {
                    result = nums[i];
                    break;
                }
            }
        }

        cout << result << endl;
    }

    return 0;
}