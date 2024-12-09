#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

const double INF = 1e9;

struct Edge {
    int to, horses;
    double cost;
};

struct State {
    int city, tickets;
    double time;

    bool operator>(const State& other) const {
        return time > other.time;
    }
};

int main() {
    int n, m, p, a, b;

    while (cin >> n >> m >> p >> a >> b && n != 0) {
        vector<int> tickets(n);
        for (int i = 0; i < n; i++) {
            cin >> tickets[i];
        }

        vector<vector<Edge>> graph(m + 1);
        for (int i = 0; i < p; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            graph[x].push_back({y, 0, double(z) / tickets[0]});
            graph[y].push_back({x, 0, double(z) / tickets[0]});
        }

        vector<vector<double>> dist(m + 1, vector<double>(1 << n, INF));
        dist[a][0] = 0;

        priority_queue<State, vector<State>, greater<State>> pq;
        pq.push({a, 0, 0});

        while (!pq.empty()) {
            State current = pq.top();
            pq.pop();

            if (current.city == b) {
                cout << fixed << setprecision(3) << current.time << endl;
                break;
            }

            if (dist[current.city][current.tickets] < current.time) {
                continue;
            }

            for (const Edge& edge : graph[current.city]) {
                for (int i = 0; i < n; i++) {
                    int new_tickets = current.tickets | (1 << i);
                    if (current.tickets == new_tickets) continue;

                    double new_time = current.time + edge.cost / tickets[i];

                    if (new_time < dist[edge.to][new_tickets]) {
                        dist[edge.to][new_tickets] = new_time;
                        pq.push({edge.to, new_tickets, new_time});
                    }
                }
            }
        }

        if (dist[b][(1 << n) - 1] == INF) {
            cout << "Impossible" << endl;
        }
    }

    return 0;
}