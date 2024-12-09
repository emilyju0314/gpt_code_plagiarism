#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Node {
    int town;
    long long cost;

    Node(int town, long long cost) : town(town), cost(cost) {}

    bool operator>(const Node& other) const {
        return cost > other.cost;
    }
};

int main() {
    int N, M, K, S;
    cin >> N >> M >> K >> S;

    vector<int> zombieTowns(K);
    for (int i = 0; i < K; i++) {
        cin >> zombieTowns[i];
    }

    int P, Q;
    cin >> P >> Q;

    vector<vector<pair<int, int>>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        adj[from].emplace_back(to, 0);
        adj[to].emplace_back(from, 0);
    }

    vector<long long> minCost(N + 1, LLONG_MAX);
    minCost[1] = 0;

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.emplace(1, 0);

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        int town = current.town;
        long long cost = current.cost;

        if (cost > minCost[town]) {
            continue;
        }

        for (auto& neighbor : adj[town]) {
            int nextNode = neighbor.first;
            long long nextCost = cost + (zombieTowns[town - 1] <= S ? Q : P);
            
            if (nextCost < minCost[nextNode]) {
                minCost[nextNode] = nextCost;
                pq.emplace(nextNode, nextCost);
            }
        }
    }

    cout << minCost[N] << endl;

    return 0;
}