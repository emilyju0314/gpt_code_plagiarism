#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> jobs(N);
    vector<int> inDegree(N, 0);

    for (int i = 0; i < N; i++) {
        int M;
        cin >> M;
        
        for (int j = 0; j < M; j++) {
            int x;
            cin >> x;
            jobs[x-1].push_back(i);
            inDegree[i]++;
        }
    }

    vector<int> dp(N, 0);

    for (int i = 0; i < N; i++) {
        for (int j : jobs[i]) {
            dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    int maxLoss = *max_element(dp.begin(), dp.end());

    cout << maxLoss << endl;

    return 0;
}