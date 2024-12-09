#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findMinDisconnects(int N, vector<int> devices, vector<pair<int, int>> connections) {
    unordered_map<int, vector<int>> graph;
    for (auto& connection : connections) {
        graph[connection.first].push_back(connection.second);
        graph[connection.second].push_back(connection.first);
    }

    vector<bool> visited(N + 1, false);
    int totalDisconnects = 0;

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            int numComputers = 0;
            int totalPower = 0;

            vector<int> stack;
            stack.push_back(i);
            visited[i] = true;

            while (!stack.empty()) {
                int node = stack.back();
                stack.pop_back();

                if (devices[node - 1] < 0) {
                    numComputers++;
                }
                totalPower += devices[node - 1];

                for (int neighbor : graph[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        stack.push_back(neighbor);
                    }
                }
            }

            if (totalPower < 0 || numComputers > 0) {
                totalDisconnects++;
            }
        }
    }

    return totalDisconnects - 1;
}

int main() {
    int N;
    cin >> N;

    vector<int> devices(N);
    for (int i = 0; i < N; i++) {
        cin >> devices[i];
    }

    vector<pair<int, int>> connections(N - 1);
    for (int i = 0; i < N - 1; i++) {
        cin >> connections[i].first >> connections[i].second;
    }

    int minDisconnects = findMinDisconnects(N, devices, connections);
    cout << minDisconnects << endl;

    return 0;
}