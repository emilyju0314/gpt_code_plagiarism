#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> inDegree(n + 1, 0);
    vector<int> outDegree(n + 1, 0);
    vector<int> exists(n, 0);

    for (int i = 0; i < m; i++) {
        int j, k;
        cin >> j >> k;
        outDegree[j]++;
        inDegree[k]++;
    }

    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0 && outDegree[i] > 0) {
            exists[i - 1] = 1;
        }
    }

    vector<int> dp(n, 0);
    int sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = max(dp[i], sum);
        sum += exists[i];
    }

    vector<char> res(n, 'A');
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] == count && exists[i] == 1) {
            res[i] = 'E';
        } else {
            count++;
        }
    }

    if (count == n - 1) {
        cout << count << endl;
        for (auto c : res) {
            cout << c;
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}