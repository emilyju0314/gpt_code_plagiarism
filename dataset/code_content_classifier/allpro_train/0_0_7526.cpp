#include <iostream>
#include <vector>

using namespace std;

double cover_time(int N, const vector<vector<int>>& adj_list) {
    vector<int> dist(N, -1);
    dist[0] = 0;

    double total_steps = 0;

    for (int i = 0; i < N; i++) {
        for (int u = 0; u < N; u++) {
            if (dist[u] == i) {
                for (int v : adj_list[u]) {
                    if (dist[v] == -1) {
                        dist[v] = i + 1;
                        total_steps += i + 1;
                    }
                }
            }
        }
    }

    return total_steps / N;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj_list(N);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj_list[a-1].push_back(b-1);
        adj_list[b-1].push_back(a-1);
    }

    double ct = cover_time(N, adj_list);

    cout << fixed;
    cout.precision(6);
    cout << ct << endl;

    return 0;
}