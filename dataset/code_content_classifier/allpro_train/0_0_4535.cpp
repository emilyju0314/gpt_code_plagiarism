#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<double> nums(2 * n);
    vector<int> floored(2 * n);
    vector<int> ceiled(2 * n);

    double sum = 0.0;
    for(int i = 0; i < 2 * n; i++) {
        cin >> nums[i];
        floored[i] = floor(nums[i]);
        ceiled[i] = ceil(nums[i]);
        sum += nums[i];
    }

    sort(nums.begin(), nums.end());
    double diff = sum;

    for(int i = 0; i < 2 * n; i++) {
        for(int j = i + 1; j < 2 * n; j++) {
            double newSum = sum - nums[i] - nums[j] + floored[i] + ceiled[j];
            diff = min(diff, abs(sum - 2 * newSum));
            newSum = sum - nums[i] - nums[j] + ceiled[i] + floored[j];
            diff = min(diff, abs(sum - 2 * newSum));
        }
    }

    cout << fixed;
    cout.precision(3);
    cout << diff << endl;

    return 0;
}