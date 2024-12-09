#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

bool buildRoadNetwork(int n, int m, vector<string>& communities) {
    vector<vector<int>> adjacency(n, vector<int>(n, 0));
    vector<vector<int>> communityVertices(m);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (communities[i][j] == '1') {
                communityVertices[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < communityVertices[i].size(); j++) {
            for (int k = j + 1; k < communityVertices[i].size(); k++) {
                adjacency[communityVertices[i][j]][communityVertices[i][k]] = 1;
                adjacency[communityVertices[i][k]][communityVertices[i][j]] = 1;
            }
        }
    }

    vector<int> visited(n, 0);
    vector<int> stack;
    stack.push_back(0);

    while (!stack.empty()) {
        int curr = stack.back();
        stack.pop_back();
        visited[curr] = 1;

        for (int i = 0; i < n; i++) {
            if (adjacency[curr][i] && !visited[i]) {
                stack.push_back(i);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            return false;
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (adjacency[i][j]) {
                cout << i + 1 << " " << j + 1 << endl;
            }
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;
        
        vector<string> communities(m);
        for (int i = 0; i < m; i++) {
            cin >> communities[i];
        }

        if (!buildRoadNetwork(n, m, communities)) {
            cout << "NO" << endl;
        }
    }

    return 0;
}