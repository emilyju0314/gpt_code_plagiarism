#include <iostream>
#include <vector>

using namespace std;

bool canEraseSequence(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[i] % (i + 1) != 0) {
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        
        vector<int> nums(n);
        for (int j = 0; j < n; j++) {
            cin >> nums[j];
        }

        if (canEraseSequence(nums)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}