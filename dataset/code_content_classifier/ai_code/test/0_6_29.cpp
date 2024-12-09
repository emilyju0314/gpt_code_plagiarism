#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int countNearlyFullSubsequences(vector<int>& arr, int n, long long sum) {
    unordered_map<long long, int> freq;
    freq[0] = 1;

    int ans = 0;
    long long currSum = 0;

    for (int i = 0; i < n; i++) {
        currSum += arr[i];
        ans += freq[currSum - (sum - 1)];
        freq[currSum]++;
    }

    return ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }

        cout << countNearlyFullSubsequences(arr, n, sum) << endl;
    }

    return 0;
}