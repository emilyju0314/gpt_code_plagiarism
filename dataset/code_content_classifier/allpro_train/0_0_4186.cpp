#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<long long> prefixSum(n), suffixSum(n);

    prefixSum[0] = nums[0];
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i-1] + nums[i];
    }

    suffixSum[n-1] = nums[n-1];
    for (int i = n-2; i >= 0; i--) {
        suffixSum[i] = suffixSum[i + 1] + nums[i];
    }

    long long totalSum = prefixSum[n-1];
    long long ways = 0;
    for (int i = 0; i < n-1; i++) {
        if (prefixSum[i] * 3 == totalSum) {
            for (int j = n-1; j > i+1; j--) {
                if (suffixSum[j] * 3 == totalSum) {
                    ways++;
                }
            }
        }
    }

    cout << ways << endl;

    return 0;
}