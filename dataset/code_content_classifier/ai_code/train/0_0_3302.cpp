#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check_arithmetic(vector<int>& nums) {
    int diff = nums[1] - nums[0];
    for (int i = 2; i < nums.size(); i++) {
        if (nums[i] - nums[i-1] != diff) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    if (n <= 2) {
        for (int i = 0; i < n; i++) {
            cout << nums[i] << endl;
        }
    } else {
        vector<int> progression1, progression2;
        progression1.push_back(nums[0]);
        progression2.push_back(nums[1]);

        for (int i = 2; i < n; i++) {
            if (check_arithmetic(progression1)) {
                progression1.push_back(nums[i]);
            } else {
                progression2.push_back(nums[i]);
            }
        }

        if (check_arithmetic(progression1) && check_arithmetic(progression2)) {
            for (int num : progression1) {
                cout << num << " ";
            }
            cout << endl;
            for (int num : progression2) {
                cout << num << " ";
            }
            cout << endl;
        } else {
            cout << "No solution" << endl;
        }
    }

    return 0;
}