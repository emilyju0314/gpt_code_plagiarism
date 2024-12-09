#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, char>>> graph(n+1);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        graph[u].push_back({v, c});
        graph[v].push_back({u, c});
    }

    vector<int> colors(n+1, 0); // 0: not colored, 1: red, 2: blue
    vector<int> moves;

    for (int i = 1; i <= n; i++) {
        if (colors[i] != 0) continue;

        queue<int> q;
        q.push(i);
        colors[i] = 1;
        moves.push_back(i);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (auto neighbor : graph[cur]) {
                int next = neighbor.first;
                char color = neighbor.second;

                if (colors[next] == 0) {
                    q.push(next);
                    if (color == 'R') {
                        colors[next] = (colors[cur] == 1) ? 2 : 1;
                    } else {
                        colors[next] = colors[cur];
                    }
                    moves.push_back(next);
                } else if ((color == 'R' && colors[next] == colors[cur]) || (color == 'B' && colors[next] != colors[cur])) {
                    cout << "-1" << endl;
                    return 0;
                }
            }
        }
    }

    cout << moves.size() / 2 << endl;
    for (int i = 0; i < moves.size(); i += 2) {
        cout << moves[i] << " ";
    }

    return 0;
}