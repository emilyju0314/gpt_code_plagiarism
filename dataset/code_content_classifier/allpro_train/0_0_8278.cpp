#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> vertices(n);
    vector<int> in_cycle(n, 0);
    vector<int> out_degree(n, 0);
    vector<int> unknown_vertices;

    for (int i = 0; i < n; i++) {
        cin >> vertices[i].first >> vertices[i].second;
        if (vertices[i].first != 0) {
            in_cycle[i] = 1;
        } else {
            unknown_vertices.push_back(i);
        }
        if (vertices[i].second == n) {
            out_degree[i] = 1;
        }
    }

    vector<int> graph(n, -1);
    int next_unknown = 0;
    int cycle_num = 0;

    for (int i = 0; i < n; i++) {
        if (in_cycle[i] == 1) {
            int cur = i;
            while (graph[cur] == -1) {
                graph[cur] = unknown_vertices[next_unknown++];
                cycle_num++;
                cur = graph[cur];
            }
        }
    }

    int unknown_cycle = n - cycle_num;

    if (unknown_cycle > unknown_vertices.size()) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < n; i++) {
            if (in_cycle[i] == 0) {
                graph[i] = unknown_vertices.back();
                unknown_vertices.pop_back();
            }
        }

        for (int i = 0; i < n; i++) {
            if (out_degree[i] == 1) {
                cout << graph[i] + 1 << " ";
            }
        }
    }

    return 0;
}