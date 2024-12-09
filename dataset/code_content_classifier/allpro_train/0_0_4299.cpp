#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int performOperations(vector<int>& nums) {
    long long result = 0;
    int sign = 1;

    for (int i = 0; i < nums.size(); ++i) {
        if (i % 2 == 0) {
            result = (result + sign * nums[i]) % MOD;
        } else {
            sign *= -1;
        }
    }

    return (result + MOD) % MOD;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int finalNumber = performOperations(nums);
    cout << finalNumber << endl;

    return 0;
}