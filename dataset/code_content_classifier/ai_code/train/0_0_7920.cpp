#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int count_damn_rhombi(int n, int m, vector<pair<int, int>>& roads) {
    unordered_map<int, vector<int>> graph;

    for (const auto& road : roads) {
        graph[road.first].push_back(road.second);
    }

    int count = 0;
    for (int a = 1; a <= n; a++) {
        for (int c = 1; c <= n; c++) {
            if (a != c) {
                for (int b : graph[a]) {
                    for (int d : graph[c]) {
                        if (b != a && d != c && b != c && d != a && graph[b].size() && graph[d].size()) {
                            if (find(graph[b].begin(), graph[b].end(), c) != graph[b].end() && find(graph[d].begin(), graph[d].end(), a) != graph[d].end()) {
                                count++;
                            }
                        }
                    }
                }
            }
        }
    }

    return count;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> roads;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        roads.push_back({a, b});
    }

    int result = count_damn_rhombi(n, m, roads);
    cout << result << endl;

    return 0;
}