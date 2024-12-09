#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

const int INF = INT_MAX;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<pii>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        adj[A].push_back({B, C});
        adj[B].push_back({A, C});
    }

    int S, T, U, V;
    cin >> S >> T >> U >> V;

    vector<int> distS(N + 1, INF);
    vector<int> distT(N + 1, INF);

    // Dijkstra from station S
    priority_queue<pii, vector<pii>, greater<pii>> pqS;
    pqS.push({0, S});
    distS[S] = 0;

    while(!pqS.empty()) {
        int u = pqS.top().second;
        int d = pqS.top().first;
        pqS.pop();

        if(distS[u] < d) continue;

        for(auto neighbor : adj[u]) {
            int v = neighbor.first;
            int w = neighbor.second;

            if(distS[v] > distS[u] + w) {
                distS[v] = distS[u] + w;
                pqS.push({distS[v], v});
            }
        }
    }

    // Dijkstra from station T
    priority_queue<pii, vector<pii>, greater<pii>> pqT;
    pqT.push({0, T});
    distT[T] = 0;

    while(!pqT.empty()) {
        int u = pqT.top().second;
        int d = pqT.top().first;
        pqT.pop();

        if(distT[u] < d) continue;

        for(auto neighbor : adj[u]) {
            int v = neighbor.first;
            int w = neighbor.second;

            if(distT[v] > distT[u] + w) {
                distT[v] = distT[u] + w;
                pqT.push({distT[v], v});
            }
        }
    }

    // Find the minimum fare
    int minFare = distS[T];
    minFare = min(minFare, distS[U] + distT[V]);
    minFare = min(minFare, distS[V] + distT[U]);

    cout << minFare << endl;

    return 0;
}