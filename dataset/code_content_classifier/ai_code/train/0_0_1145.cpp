#include <iostream>
#include <vector>

using namespace std;

bool checkSimilar(vector<int> &nums, int x) {
    int count1 = __builtin_popcount(x);
    
    for(int num : nums) {
        int differentBits = __builtin_popcount(num ^ x);
        
        if (!(differentBits == count1 || differentBits == num))
            return false;
    }
    
    return true;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    for(int x = 0; x < (1 << 30); x++) {
        if (checkSimilar(nums, x)) {
            cout << x << endl;
            return 0;
        }
    }
    
    cout << -1 << endl;
    
    return 0;
}