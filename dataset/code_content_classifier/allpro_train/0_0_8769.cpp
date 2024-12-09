#include <iostream>
#include <vector>

using namespace std;

bool isPossible(vector<int>& nums) {
    int n = nums.size();
    vector<int> left(n), right(n);
    left[0] = 1;
    right[n-1] = 1;

    for(int i = 1; i < n; i++) {
        left[i] = min(nums[i], left[i-1]-1);
    }

    for(int i = n-2; i >= 0; i--) {
        right[i] = min(nums[i], right[i+1]-1);
    }

    for(int i = 0; i < n-1; i++) {
        if(left[i] > right[i+1]) {
            return false;
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> nums(n);
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        if(isPossible(nums)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}