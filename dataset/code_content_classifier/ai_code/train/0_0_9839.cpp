#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    string w;
    cin >> n >> w;

    vector<int> dp(n, 1);
    
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < i; j++) {
            if (w.substr(j, i-j).find(w.substr(0, j)) != string::npos) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;

    return 0;
}