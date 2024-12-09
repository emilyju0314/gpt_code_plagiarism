#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& infected, int current) {
    infected[current] = true;
    for (int neighbor : graph[current]) {
        if (!infected[neighbor]) {
            dfs(graph, infected, neighbor);
        }
    }
}

int main() {
    int N, M;
    while (cin >> N >> M) {
        if (N == 0 && M == 0) {
            break;
        }

        vector<vector<int>> graph(N + 1);
        vector<bool> infected(N + 1, false);
        infected[1] = true;

        for (int i = 0; i < M; i++) {
            int t, s, d;
            cin >> t >> s >> d;
            if (infected[s]) {
                graph[s].push_back(d);
            } else if (infected[d]) {
                graph[d].push_back(s);
            }
        }

        dfs(graph, infected, 1);

        int count = 0;
        for (int i = 1; i <= N; i++) {
            if (infected[i]) {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}