#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    vector<int> dp(n+1, -1);
    vector<int> prev(n+1, -1);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    dp[0] = 0;

    for (int i = 0; i <= n; i++) {
        if (dp[i] == -1) continue;

        for (int j = 0; j < i; j++) {
            int h = i - a[i] + b[i];
            if (h >= 0 && dp[h] == -1) {
                dp[h] = dp[i] + 1;
                prev[h] = i;
            }
        }
    }

    if (dp[0] == -1) {
        cout << -1 << endl;
    } else {
        vector<int> path;
        int curr = 0;
        while (curr != -1) {
            path.push_back(curr);
            curr = prev[curr];
        }

        cout << path.size() - 1 << endl;
        for (int i = path.size() - 1; i > 0; i--) {
            cout << path[i] << " ";
        }
        cout << endl;
    }

    return 0;
}