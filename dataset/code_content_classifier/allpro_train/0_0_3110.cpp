#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> stones(N);
    for (int i = 0; i < N; i++) {
        cin >> stones[i];
    }

    vector<vector<int>> adjList(N);
    vector<int> inDegree(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a - 1].push_back(b - 1);
        inDegree[b - 1]++;
    }

    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    int player = 1;
    vector<bool> winning(N, false);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (stones[u] == 0) {
            winning[u] = false;
        } else {
            winning[u] = true;
            for (int v : adjList[u]) {
                stones[v]--;
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        player = 3 - player; // Switch player
    }

    if (winning[0]) {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
    }

    return 0;
}