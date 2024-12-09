#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> agents(M);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        agents[i] = make_pair(a, b);
    }

    int ans = 0;
    for (int mask = 0; mask < (1 << M); mask++) {
        set<int> reachable_islands;
        reachable_islands.insert(1); // Takahashi starts at Island 1

        for (int i = 0; i < M; i++) {
            if (mask & (1 << i)) {
                reachable_islands.insert(agents[i].first);
            } else {
                reachable_islands.insert(agents[i].second);
            }
        }

        if (reachable_islands.count(2) > 0) {
            ans++;
        }
    }

    int result = (ans * pow(2, M)) % MOD;
    cout << result << endl;

    return 0;
}