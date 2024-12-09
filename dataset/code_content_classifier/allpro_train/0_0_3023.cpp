#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<int> scores(N, 0);
    vector<vector<pair<int, int>>> roads(N);

    for (int i = 0; i < M; i++) {
        int f, t, p;
        cin >> f >> t >> p;
        roads[f].push_back({t, p});
        roads[t].push_back({f, p});
    }

    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;

        vector<int> max_score(N, 0);
        max_score[a] = scores[a];

        vector<bool> visited(N, false);
        visited[a] = true;

        for (int j = 0; j < N; j++) {
            int max_idx = -1;
            int max_val = 0;
            for (int k = 0; k < N; k++) {
                if (!visited[k] && max_score[k] > max_val) {
                    max_val = max_score[k];
                    max_idx = k;
                }
            }
            if (max_idx == -1) {
                break;
            }
            visited[max_idx] = true;

            for (auto& road : roads[max_idx]) {
                int next_node = road.first;
                int score = road.second;
                max_score[next_node] = max(max_score[next_node], max_score[max_idx] ^ score);
            }
        }

        cout << max_score[b] << endl;
    }

    return 0;
}