#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> roads(M, vector<int>(2));

    for (int i = 0; i < M; i++) {
        cin >> roads[i][0] >> roads[i][1];
    }

    int ans = N * (N - 1) / 2;
    for (int i = 0; i < (1 << N); i++) {
        vector<int> group(N);
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                group[j] = 1;
            }
        }

        bool valid = true;
        for (int j = 0; j < M; j++) {
            if (group[roads[j][0] - 1] != group[roads[j][1] - 1]) {
                valid = false;
                break;
            }
        }

        if (valid) {
            int count = count(group.begin(), group.end(), 1);
            ans = min(ans, count * (count - 1) / 2 + (N - count) * (N - count - 1) / 2);
        }
    }

    if (ans == N * (N - 1) / 2) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}