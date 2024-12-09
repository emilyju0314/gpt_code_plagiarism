#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 1e9;

struct Edge {
    int to, rev;
    bool is_reversed;
};

void add_edge(vector<vector<Edge>>& graph, int from, int to) {
    graph[from].push_back({to, (int)graph[to].size(), false});
    graph[to].push_back({from, (int)graph[from].size() - 1, true});
}

pair<int, int> shortest_route(vector<vector<Edge>>& graph, int N, int S, int T) {
    vector<int> dist(N, INF);
    vector<int> road_to_alter(N, -1);
    dist[S] = 0;

    queue<int> q;
    q.push(S);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (const Edge& edge : graph[curr]) {
            int next = edge.to;
            if (dist[next] > dist[curr] + 1) {
                dist[next] = dist[curr] + 1;
                road_to_alter[next] = edge.is_reversed ? edge.rev : -1;
                q.push(next);
            }
        }
    }

    return {dist[T], (road_to_alter[T] == -1 ? 0 : road_to_alter[T])};
}

int main() {
    int N, S, T, M;
    while (true) {
        cin >> N;
        if (N == 0) break;

        cin >> S >> T >> M;

        vector<vector<Edge>> graph(N);
        
        for (int i = 0; i < M; i++) {
            int A, B;
            cin >> A >> B;
            add_edge(graph, A - 1, B - 1);
        }

        pair<int, int> result = shortest_route(graph, N, S - 1, T - 1);
        cout << result.first << " " << result.second + 1 << endl;
    }

    return 0;
}