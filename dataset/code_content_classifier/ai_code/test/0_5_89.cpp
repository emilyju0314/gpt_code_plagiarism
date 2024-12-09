#include <iostream>
#include <vector>

using namespace std;

bool canEraseSequence(vector<int>& nums) {
    int n = nums.size();
    bool canErase = false;
    for (int i = 0; i < n; i++) {
        if (nums[i] % (i + 1) != 0) {
            canErase = true;
            break;
        }
    }
    return canErase;
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

        if (canEraseSequence(nums)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}