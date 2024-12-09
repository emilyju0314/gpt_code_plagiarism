#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    long long sum = 0;
    for(int i = 0; i < n; i++) {
        sum += nums[i];
    }

    long long maxCircularValue = 0;
    long long currentSum = 0;
    for(int i = 0; i < n; i++) {
        currentSum += nums[i];
        maxCircularValue = max(maxCircularValue, currentSum);
        currentSum = min(currentSum, 0LL);
    }

    cout << max(maxCircularValue, sum - maxCircularValue) << endl;

    return 0;
}