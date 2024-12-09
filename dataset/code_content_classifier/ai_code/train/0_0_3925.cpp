#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; // Adjusting indices
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int k;
    cin >> k;

    vector<int> roads(n - 1, 0);
    for (int i = 0; i < k; i++) {
        int start, end;
        cin >> start >> end;
        start--;
        end--;

        vector<bool> visited(n, false);
        vector<int> distance(n, 0);
        
        // Perform bfs to calculate distance from start city to all other cities
        vector<int> queue;
        queue.push_back(start);
        visited[start] = true;
        while (!queue.empty()) {
            int current = queue.front();
            queue.erase(queue.begin());
            for (int neighbor : graph[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    distance[neighbor] = distance[current] + 1;
                    queue.push_back(neighbor);
                }
            }
        }

        int current = end;
        while (current != start) {
            if (distance[current] == 1) {
                roads[current] += 1;
            }
            for (int neighbor : graph[current]) {
                if (distance[neighbor] == distance[current] - 1) {
                    current = neighbor;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        cout << roads[i] << " ";
    }

    return 0;
}