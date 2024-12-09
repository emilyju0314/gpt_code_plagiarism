#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(vector<long long>& nums, long long k) {
    int n = nums.size();
    vector<long long> diffs;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            long long diff = abs(nums[i] - nums[j]);
            if (find(nums.begin(), nums.end(), diff) == nums.end()) {
                diffs.push_back(diff);
            }
        }
    }

    for (long long diff : diffs) {
        bool possible = true;
        for (int i = 0; i < n; i++) {
            if (find(nums.begin(), nums.end(), 2*nums[i]-diff) == nums.end()) {
                possible = false;
                break;
            }
        }
        if (possible && 2*diff == k) return true;
    }

    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        long long k;
        cin >> n >> k;

        vector<long long> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        if (isPossible(nums, k)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}