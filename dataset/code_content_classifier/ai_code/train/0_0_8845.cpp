#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<vector<int>> graph; // Adjacency list representing the tree graph
vector<unordered_map<int, int>> viruses; // Map representing initial city and propagation speed of virus species

void dfs(int node, int parent, vector<unordered_set<int>>& infected, vector<int>& result) {
    for (auto& [virus, speed] : viruses[node]) {
        bool can_infect = false;
        for (int city : infected[node]) {
            if (speed >= 0 && infected[parent].count(city) && speed >= infected[parent][city]) {
                can_infect = true;
                infected[node].insert(virus);
                result[city-1] = virus;
                break;
            }
        }
        if (can_infect) {
            for (int child : graph[node]) {
                if (child != parent) {
                    dfs(child, node, infected, result);
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    graph.resize(n+1);
    viruses.resize(n+1);

    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int q;
    cin >> q;

    while (q--) {
        int k, m;
        cin >> k >> m;

        vector<unordered_set<int>> infected(n+1);
        vector<int> result(m);

        for (int i = 1; i <= k; i++) {
            int v, s;
            cin >> v >> s;
            viruses[v][i] = s;
            infected[v].insert(i);
        }

        vector<int> important_cities(m);
        for (int i = 0; i < m; i++) {
            cin >> important_cities[i];
        }

        for (int i = 0; i < m; i++) {
            dfs(important_cities[i], 0, infected, result);
        }

        for (int i = 0; i < m; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}