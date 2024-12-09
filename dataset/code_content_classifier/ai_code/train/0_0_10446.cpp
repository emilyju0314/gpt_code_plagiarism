#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge {
    int to, capacity;
};

struct Division {
    int city, priority;
};

struct Node {
    int city, days;
};

bool operator<(const Node& a, const Node& b) {
    return a.days > b.days;
}

int main() {
    int n;
    cin >> n;

    vector<Division> divisions(n);
    for (int i = 0; i < n; i++) {
        divisions[i].city = i + 1;
        cin >> divisions[i].priority;
    }

    vector<vector<Edge>> graph(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int v, u, c;
        cin >> v >> u >> c;
        graph[v].push_back({u, c});
        graph[u].push_back({v, c});
    }

    vector<int> days(n + 1, -1);
    priority_queue<Node> pq;
    pq.push({1, 0});

    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();

        if (days[node.city] != -1) {
            continue;
        }

        days[node.city] = node.days;

        for (Edge& edge : graph[node.city]) {
            if (days[edge.to] == -1) {
                int capacity = edge.capacity;
                if (divisions[edge.to - 1].priority < divisions[node.city - 1].priority) {
                    capacity--;
                }

                int nextDays = node.days + (capacity == 0 ? 1 : 0);
                pq.push({edge.to, nextDays});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << days[i] << " ";
    }
    cout << endl;

    return 0;
}