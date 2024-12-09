#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int mean = 0, median = 0;
    for (int num : nums) {
        mean += num;
    }
    mean /= n;

    if (n % 2 == 1) {
        median = nums[n/2];
    } else {
        median = (nums[n/2 - 1] + nums[n/2]) / 2;
    }

    int skewness = mean - median;

    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}