#include <iostream>
#include <vector>

using namespace std;

long long countGoodSubarrays(vector<int>& arr) {
    long long count = arr.size(); // All subarrays with length 1 are good
    long long prefixSum = 0;
    vector<int> lastOccurrence(arr.size() + 1, -1);
    lastOccurrence[0] = 0;

    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];

        if (i > 0) {
            if (lastOccurrence[prefixSum] != -1) {
                count += i - lastOccurrence[prefixSum];
            }
        }

        lastOccurrence[prefixSum] = i;
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
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << countGoodSubarrays(arr) << endl;
    }

    return 0;
}