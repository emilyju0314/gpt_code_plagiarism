#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n, m;
vector<vector<pair<int, char>>> graph;
vector<vector<vector<int>>> dp;

int getWinner(int i, int j, int letter) {
    if (dp[i][j][letter] != -1) {
        return dp[i][j][letter];
    }
    
    int nextPlayer = (i + j) % 2;
    int winner = nextPlayer;
    
    if (nextPlayer == 0) {
        winner = 1;
        for (auto& edge : graph[i]) {
            if (edge.second >= letter) {
                winner = max(winner, getWinner(edge.first, j, edge.second));
            }
        }
    } else {
        winner = 0;
        for (auto& edge : graph[j]) {
            if (edge.second >= letter) {
                winner = min(winner, getWinner(i, edge.first, edge.second));
            }
        }
    }
    
    return dp[i][j][letter] = winner;
}

int main() {
    cin >> n >> m;
    
    graph.resize(n);
    dp.resize(n, vector<vector<int>>(n, vector<int>(26, -1)));
    
    for (int i = 0; i < m; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        u--;
        v--;
        graph[u].push_back({v, c});
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int winner = getWinner(i, j, 0);
            if (winner == 0) {
                cout << "A";
            } else {
                cout << "B";
            }
        }
        cout << endl;
    }
    
    return 0;
}