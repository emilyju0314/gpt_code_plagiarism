#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> powerhouses(N);
    for(int i = 0; i < N; i++) {
        cin >> powerhouses[i].first >> powerhouses[i].second;
    }

    int max_weight = 100000;

    vector<vector<int>> dp(N + 1, vector<int>(max_weight + 1, 1e9));
    dp[0][0] = 0;

    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= max_weight; j++) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            if(j >= powerhouses[i-1].first) {
                dp[i][j] = min(dp[i][j], dp[i-1][j-powerhouses[i-1].first] + 1);
            } else if(j >= powerhouses[i-1].first - powerhouses[i-1].second) {
                dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
            }
        }
    }

    int min_people = 1e9;
    for(int j = 0; j <= max_weight; j++) {
        min_people = min(min_people, dp[N][j]);
    }

    cout << min_people << endl;

    return 0;
}