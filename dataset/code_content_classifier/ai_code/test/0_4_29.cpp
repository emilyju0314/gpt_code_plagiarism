#include <iostream>
#include <vector>

using namespace std;

long long countNearlyFullSubsequences(vector<int>& arr, long long s) {
    int n = arr.size();
    long long count = 0;

    for (int mask = 1; mask < (1 << n); mask++) {
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum += arr[i];
            }
        }
        
        if (sum == s - 1) {
            count++;
        }
    }

    return count;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        vector<int> arr(n);
        long long s = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            s += arr[i];
        }

        cout << countNearlyFullSubsequences(arr, s) << endl;
    }

    return 0;
}