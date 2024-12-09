#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> tags(n);
        for(int i = 0; i < n; i++) {
            cin >> tags[i];
        }

        vector<int> scores(n);
        for(int i = 0; i < n; i++) {
            cin >> scores[i];
        }

        vector<unordered_map<int, int>> dp(n);

        for(int i = 0; i < n; i++) {
            dp[i][0] = 0;
            for(int j = 0; j < i; j++) {
                int diff = abs((1 << i) - (1 << j));
                if(tags[i] != tags[j] && dp[j].count(diff)) {
                    dp[i][diff] = max(dp[i][diff], dp[j][diff] + abs(scores[i] - scores[j]));
                }
            }

            for(auto& prev : dp[i]) {
                for(auto& next : dp[i]) {
                    dp[i][abs(next.first - prev.first)] = max(dp[i][abs(next.first - prev.first)], prev.second + next.second);
                }
            }
        }

        int max_score = 0;
        for(auto& m : dp) {
            for(auto& p : m) {
                max_score = max(max_score, p.second);
            }
        }

        cout << max_score << endl;
    }

    return 0;
}