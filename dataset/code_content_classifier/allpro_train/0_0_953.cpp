#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    vector<int> prefixSum(n+1, 0);
    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i-1] + sequence[i-1];
    }

    cout << *max_element(prefixSum.begin(), prefixSum.end()) << endl;

    for (int i = 0; i < q; i++) {
        int k, x;
        cin >> k >> x;
        int diff = x - sequence[k-1];
        sequence[k-1] = x;

        for (int j = k; j <= n; j++) {
            prefixSum[j] += diff;
        }

        cout << *max_element(prefixSum.begin(), prefixSum.end()) << endl;
    }
    return 0;
}