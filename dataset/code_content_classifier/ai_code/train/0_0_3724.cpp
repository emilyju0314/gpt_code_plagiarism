#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, s, t;
    cin >> N >> M >> s >> t;

    vector<int> d(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> d[i];
    }

    vector<vector<int>> magic(M, vector<int>(2));
    for (int i = 0; i < M; i++) {
        cin >> magic[i][0] >> magic[i][1];
    }

    int ans = 0;
    int current_dimension = s;
    while (current_dimension != t) {
        int min_damage = INT_MAX;
        int current_dimension_idx = -1;

        for (int i = 0; i < M; i++) {
            if (magic[i][0] == current_dimension) {
                int next_dimension = magic[i][1];
                if (d[next_dimension] < min_damage) {
                    min_damage = d[next_dimension];
                    current_dimension_idx = i;
                }
            }
        }

        ans += min_damage;
        current_dimension = magic[current_dimension_idx][1];
    }

    cout << ans << endl;

    return 0;
}