#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> jobs(N);
    for (int i = 0; i < N; i++) {
        cin >> jobs[i].first >> jobs[i].second;
    }

    vector<int> dp(M+1, 0);
    for (int i = 0; i < N; i++) {
        for (int j = M; j >= jobs[i].first; j--) {
            dp[j] = max(dp[j], dp[j - jobs[i].first] + jobs[i].second);
        }
    }

    cout << dp[M] << endl;

    return 0;
}