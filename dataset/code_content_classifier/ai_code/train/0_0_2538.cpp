#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int minElementsToRemove(vector<int>& arr) {
    unordered_map<int, int> freq;

    for (int num : arr) {
        freq[num]++;
    }

    int maxFreq = 0;
    int totalToRemove = arr.size();

    for (auto it = freq.begin(); it != freq.end(); it++) {
        maxFreq = max(maxFreq, it->second);
        totalToRemove -= it->second;
    }

    if (maxFreq >= totalToRemove) {
        return maxFreq - totalToRemove;
    } else {
        return (totalToRemove % 2 == 0) ? 0 : 1;
    }
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

        int result = minElementsToRemove(arr);
        cout << result << endl;
    }

    return 0;
}