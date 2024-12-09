#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int dest;
    int cost;
    int time;
};

struct Node {
    int city;
    int silver;
    long long gold;
    int time;

    bool operator>(const Node& other) const {
        return time > other.time;
    }
};

int main() {
    int N, M, S;
    cin >> N >> M >> S;

    vector<vector<Edge>> graph(N+1);

    for (int i = 0; i < M; i++) {
        int U, V, A, B;
        cin >> U >> V >> A >> B;
        graph[U].push_back({V, A, B});
        graph[V].push_back({U, A, B});
    }

    vector<int> C(N+1), D(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> C[i] >> D[i];
    }

    vector<vector<long long>> dist(N+1, vector<long long>(S+1, LLONG_MAX));
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({1, S, 100000000000, 0});
    dist[1][S] = 0;

    while (!pq.empty()) {
        Node curr = pq.top();
        pq.pop();

        if (curr.city == N) {
            cout << curr.time << "\n";
            continue;
        }

        for (Edge& edge : graph[curr.city]) {
            int nextCity = edge.dest;
            int silver = curr.silver - edge.cost;
            int time = curr.time + edge.time;
            
            if (silver >= 0 && time < dist[nextCity][silver]) {
                dist[nextCity][silver] = time;
                pq.push({nextCity, silver, curr.gold, time});
            }
        }

        for (int i = 1; i <= N; i++) {
            if (i != curr.city && curr.gold >= C[i] && curr.time + D[i] < dist[i][curr.silver]) {
                dist[i][curr.silver] = curr.time + D[i];
                pq.push({i, curr.silver, curr.gold - C[i], curr.time + D[i]});
            }
        }
    }

    return 0;
}