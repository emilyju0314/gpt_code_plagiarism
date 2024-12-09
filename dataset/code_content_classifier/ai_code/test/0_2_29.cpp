#include <iostream>
#include <vector>

using namespace std;

long long countNearlyFullSubsequences(vector<int>& arr) {
    int n = arr.size();
    long long sum = 0;
    for (int num : arr) {
        sum += num;
    }

    long long result = 0;
    for (int i = 0; i < (1 << n); i++) {
        long long tempSum = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                tempSum += arr[j];
            }
        }
        if (tempSum == sum - 1) {
            result++;
        }
    }
    return result;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        long long result = countNearlyFullSubsequences(arr);
        cout << result << endl;
    }

    return 0;
}