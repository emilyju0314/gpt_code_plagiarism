#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

struct Intersection {
    string name;
    int x, y;
};

struct Road {
    string from, to;
};

struct Vertex {
    string name;
    int distance;
    int left_turns;
};

struct Edge {
    string to;
    int weight;
    bool is_right_turn;
};

int main() {
    int num_datasets;
    cin >> num_datasets;

    for (int dataset = 0; dataset < num_datasets; dataset++) {
        int m, n;
        cin >> m >> n;

        map<string, Intersection> intersections;
        map<string, vector<Edge>> graph;
        vector<Road> roads;

        for (int i = 0; i < m; i++) {
            string name;
            int x, y;
            cin >> name >> x >> y;
            intersections[name] = {name, x, y};
        }

        for (int j = 0; j < n; j++) {
            string from, to;
            cin >> from >> to;
            roads.push_back({from, to});
            graph[from].push_back({to, abs(intersections[from].x - intersections[to].x + intersections[from].y - intersections[to].y), intersections[from].x > intersections[to].x});
            graph[to].push_back({from, abs(intersections[from].x - intersections[to].x + intersections[from].y - intersections[to].y), intersections[to].x > intersections[from].x});
        }

        string src, dst;
        cin >> src >> dst;

        priority_queue<Vertex, vector<Vertex>, greater<Vertex>> pq;
        map<string, int> distances;
        map<string, int> left_turns;

        for (const auto& intersection : intersections) {
            distances[intersection.first] = INT_MAX;
            left_turns[intersection.first] = INT_MAX;
        }

        distances[src] = 0;
        left_turns[src] = 0;
        pq.push({src, 0, 0});

        bool found_destination = false;

        while (!pq.empty()) {
            Vertex current = pq.top();
            pq.pop();

            if (current.name == dst) {
                found_destination = true;
                break;
            }

            for (const auto& edge : graph[current.name]) {
                int new_distance = current.distance + edge.weight;
                int new_left_turns = current.left_turns + edge.is_right_turn;

                if (new_distance < distances[edge.to] || (new_distance == distances[edge.to] && new_left_turns < left_turns[edge.to])) {
                    distances[edge.to] = new_distance;
                    left_turns[edge.to] = new_left_turns;
                    pq.push({edge.to, new_distance, new_left_turns});
                }
            }
        }

        if (found_destination) {
            cout << left_turns[dst] << endl;
        } else {
            cout << "impossible" << endl;
        }
    }

    return 0;
}