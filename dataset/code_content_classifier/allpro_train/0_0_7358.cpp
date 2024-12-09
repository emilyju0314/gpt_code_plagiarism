#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int>& counts, int mid, int n) {
    vector<int> dp(n+1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i-1];
        for (int j = 1; j <= i; j++) {
            int num = counts[i] - counts[i - j];
            if (num < mid) {
                dp[i] = max(dp[i], dp[i-j] + j);
            }
        }
    }
    return dp[n] >= mid;
}

int main() {
    int n, h;
    string s;
    cin >> n >> h >> s;

    vector<int> counts(n+1);
    for (int i = 0; i < n; i++) {
        counts[i+1] = counts[i] + (s[i] - '0');
    }

    int low = 0, high = n;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (check(counts, mid, n)) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    string result = "";
    for (int i = 1; i <= n; i++) {
        int num = counts[i] - counts[i - low];
        if (num < low) {
            for (int j = 0; j < low; j++) {
                result += s[i-low+j];
            }
        }
    }

    cout << result << endl;

    return 0;
}