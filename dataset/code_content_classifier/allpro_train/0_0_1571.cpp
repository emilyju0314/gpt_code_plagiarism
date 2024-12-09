#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char ch;
            cin >> ch;
            graph[i][j] = ch - '0';
        }
    }

    cin >> m;
    vector<int> path(m);
    for (int i = 0; i < m; i++) {
        cin >> path[i];
    }

    vector<int> goodSubsequence;
    goodSubsequence.push_back(path[0]);

    for (int i = 1; i < m - 1; i++) {
        if (graph[goodSubsequence.back() - 1][path[i] - 1]) {
            goodSubsequence.push_back(path[i]);
        }
    }

    goodSubsequence.push_back(path[m - 1]);

    cout << goodSubsequence.size() << endl;
    for (int vertex : goodSubsequence) {
        cout << vertex << " ";
    }
    
    return 0;
}