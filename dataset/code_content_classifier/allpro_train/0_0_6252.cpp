#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    unordered_map<int, int> prefixSumCount;
    int prefixSum = 0;
    int ans = 0;
    prefixSumCount[0]++;

    for (int i = 0; i < n; ++i) {
        prefixSum += a[i];
        
        if (prefixSumCount.find(prefixSum) != prefixSumCount.end()) {
            ans = max(ans, prefixSumCount[prefixSum] + 1);
        }
        
        prefixSumCount[prefixSum]++;
    }

    cout << n - ans << endl;

    return 0;
}