#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> colors(n);
    for (int i = 0; i < n; i++) {
        cin >> colors[i];
    }

    unordered_map<int, int> lastIdx;
    vector<int> dp(n, 0);
    int operations = 0;

    for (int i = 0; i < n; i++) {
        if (lastIdx.find(colors[i]) != lastIdx.end()) {
            dp[i] = dp[lastIdx[colors[i]]] + 1;
        }
        lastIdx[colors[i]] = i;
        operations = max(operations, dp[i]);
    }

    cout << n - 1 - operations << endl;

    return 0;
}