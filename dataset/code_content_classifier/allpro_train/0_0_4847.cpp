#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> P(N);
    vector<int> c(N);
    vector<int> J(N);
    unordered_map<int, vector<pair<int, int>>> jams;

    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> c[i];
        jams[c[i]].push_back(make_pair(P[i], i+1));
    }

    for (int i = 0; i < N; i++) {
        cin >> J[i];
    }

    int u, v, t;
    vector<pair<int, pair<int, int>>> roads;
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> t;
        roads.push_back(make_pair(t, make_pair(u, v)));
    }

    sort(roads.begin(), roads.end());

    vector<int> max_happiness(K, -1);
    for (int i = 0; i < K; i++) {
        for (auto& jam : jams[i+1]) {
            int jam_happiness = jam.first;
            int city = jam.second;
            int max_jam_happiness = 0;

            for (int j = 0; j < M; j++) {
                int time = roads[j].first;
                int u = roads[j].second.first;
                int v = roads[j].second.second;

                if (u == city || v == city) {
                    if (max_jam_happiness < J[v-1]) {
                        max_jam_happiness = J[v-1];
                    }
                }
            }

            max_happiness[i] = max(max_happiness[i], jam_happiness + max_jam_happiness);
        }
    }

    for (int i = 0; i < K; i++) {
        cout << max_happiness[i] << endl;
    }

    return 0;
}