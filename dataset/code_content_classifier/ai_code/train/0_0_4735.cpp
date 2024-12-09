#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> graph(n+1);
    vector<int> inDegree(n+1, 0);
    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++) {
            int vertex;
            cin >> vertex;
            graph[i].push_back(vertex);
            inDegree[vertex]++;
        }
    }
    
    int initialPos;
    cin >> initialPos;
    
    queue<int> q;
    vector<int> winCount(n+1, 0);
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
            winCount[i] = 1;
        }
    }
    
    bool canWin = false;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        for (int neighbor : graph[current]) {
            if (--inDegree[neighbor] == 0) {
                q.push(neighbor);
                winCount[neighbor] = max(winCount[neighbor], winCount[current]) + 1;
            }
        }
        
        if (graph[current].empty() && winCount[current] % 2 == 0) {
            canWin = true;
            break;
        }
    }
    
    if (canWin) {
        cout << "Win" << endl;
        int current = initialPos;
        cout << current;
        while (!graph[current].empty()) {
            for (int neighbor : graph[current]) {
                if (winCount[current] == winCount[neighbor] + 1) {
                    cout << " " << neighbor;
                    current = neighbor;
                    break;
                }
            }
        }
    } else {
        int drawCount = 0;
        for (int i = 1; i <= n; i++) {
            if (inDegree[i] == 0) {
                drawCount++;
            }
        }
        
        if (drawCount > 0) {
            cout << "Draw";
        } else {
            cout << "Lose";
        }
    }
    
    return 0;
}