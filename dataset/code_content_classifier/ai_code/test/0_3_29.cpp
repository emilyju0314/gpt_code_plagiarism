#include <iostream>
#include <vector>

using namespace std;

long long countNearlyFullSubsequences(vector<int>& arr) {
    int n = arr.size();
    long long s = 0;
    for (int num : arr) {
        s += num;
    }

    long long result = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum += arr[i];
            }
        }
        if (sum == s - 1) {
            result++;
        }
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        
        vector<int> arr(n);
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }
        
        cout << countNearlyFullSubsequences(arr) << endl;
    }

    return 0;
}