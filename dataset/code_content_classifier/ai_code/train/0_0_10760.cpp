#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int minOperations(vector<int>& arr) {
    unordered_map<int, int> freq;
    int max_freq = 0;
    for (int num : arr) {
        if (num != arr[0]) {
            freq[num]++;
            max_freq = max(max_freq, freq[num]);
        }
    }
    return max_freq;
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

        cout << minOperations(arr) << endl;
    }

    return 0;
}