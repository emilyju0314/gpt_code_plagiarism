#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int ALPHABET_SIZE = 26;

bool topologicalSort(vector<int> adj[], vector<int> indegree, vector<char>& result) {
    queue<int> q;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back('a' + u);

        for (int v : adj[u]) {
            if(--indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    return result.size() == ALPHABET_SIZE;
}

int main() {
    int n;
    cin >> n;

    vector<int> adj[ALPHABET_SIZE];
    vector<int> indegree(ALPHABET_SIZE, 0);
    vector<string> names(n);

    for (int i = 0; i < n; i++) {
        cin >> names[i];
    }

    for (int i = 0; i < n - 1; i++) {
        string current = names[i], next = names[i+1];
        int j = 0;

        while (j < current.size() && j < next.size() && current[j] == next[j]) {
            j++;
        }

        if (j < current.size() && j < next.size()) {
            int u = current[j] - 'a';
            int v = next[j] - 'a';
            adj[u].push_back(v);
            indegree[v]++;
        } else if (current.size() > next.size()) {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    vector<char> result;
    if (topologicalSort(adj, indegree, result)) {
        for (char c : result) {
            cout << c;
        }
    } else {
        cout << "Impossible";
    }

    return 0;
}