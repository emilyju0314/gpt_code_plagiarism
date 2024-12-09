#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<vector<int>> dp(n, vector<int>(n, 2));

    int max_length = 2;
    for(int i = 2; i < n; i++) {
        for(int j = i - 1; j >= 1; j--) {
            int next_num = 2 * b[j] - b[i];
            if(next_num >= 0) {
                int idx = lower_bound(b.begin(), b.begin() + j, next_num) - b.begin();
                if(idx != j && b[idx] == next_num) {
                    dp[i][j] = max(dp[i][j], dp[j][idx] + 1);
                    max_length = max(max_length, dp[i][j]);
                }
            }
        }
    }

    cout << max_length << endl;

    return 0;
}