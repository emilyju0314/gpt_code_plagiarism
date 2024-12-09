#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    vector<vector<int>> adj;
    vector<int> in_degree;

public:
    Graph(int n) {
        adj.resize(26);
        in_degree.assign(26, 0);
    }

    void addEdge(char u, char v) {
        adj[u - 'a'].push_back(v - 'a');
        in_degree[v - 'a']++;
    }

    string topologicalSort() {
        string order;
        queue<int> q;

        for (int i = 0; i < 26; i++) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            order += ('a' + u);

            for (int v : adj[u]) {
                in_degree[v]--;
                if (in_degree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return (order.size() == 26) ? order : "";
    }
};

int main() {
    int n;
    cin >> n;

    Graph g(26);

    vector<string> names(n);
    for (int i = 0; i < n; i++) {
        cin >> names[i];
    }

    for (int i = 0; i < n - 1; i++) {
        string word1 = names[i];
        string word2 = names[i + 1];

        bool found = false;
        for (int j = 0; j < min(word1.size(), word2.size()); j++) {
            if (word1[j] != word2[j]) {
                g.addEdge(word1[j], word2[j]);
                found = true;
                break;
            }
        }

        if (!found && word1.size() > word2.size()) {
            cout << "Impossible";
            return 0;
        }
    }

    string order = g.topologicalSort();
    if (order.empty()) {
        cout << "Impossible";
    } else {
        cout << order;
    }

    return 0;
}