#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

struct Edge {
    int dest;
    int distance;
    int speedLimit;
};

struct Node {
    int city;
    int speed;
    double time;

    bool operator>(const Node& other) const {
        return time > other.time;
    }
};

double dijkstra(vector<vector<Edge>>& graph, int start, int goal) {
    int n = graph.size();
    vector<vector<double>> dist(n, vector<double>(31, INFINITY));
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    pq.push({start, 1, 0.0});
    dist[start][1] = 0.0;

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        if (current.city == goal) {
            return current.time;
        }

        for (Edge& edge : graph[current.city]) {
            for (int speed = max(1, current.speed - 1); speed <= min(30, current.speed + 1); speed++) {
                double newTime = current.time + (double)edge.distance / speed;
                if (newTime < dist[edge.dest][speed]) {
                    dist[edge.dest][speed] = newTime;
                    pq.push({edge.dest, speed, newTime});
                }
            }
        }
    }

    return INFINITY;
}

int main() {
    int n, m;
    
    while (cin >> n >> m && n != 0 && m != 0) {
        vector<vector<Edge>> graph(n+1);

        int start, goal;
        cin >> start >> goal;

        for (int i = 0; i < m; i++) {
            int x, y, d, c;
            cin >> x >> y >> d >> c;
            graph[x].push_back({y, d, c});
            graph[y].push_back({x, d, c});
        }

        double result = dijkstra(graph, start, goal);

        if (result == INFINITY) {
            cout << "unreachable" << endl;
        } else {
            cout << fixed << setprecision(6) << result << endl;
        }
    }

    return 0;
}