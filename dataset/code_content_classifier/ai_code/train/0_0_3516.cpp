#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isPossible(int n, vector<int>& indexes, vector<int>& roads) {
    vector<vector<int>> graph(n + 1);
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, n + 1));

    for (int i = 2; i <= n; i++) {
        graph[i].push_back(roads[i - 2]);
        graph[roads[i - 2]].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int next : graph[curr]) {
                if (dist[i][next] > dist[i][curr] + 1) {
                    dist[i][next] = dist[i][curr] + 1;
                    q.push(next);
                }
            }
        }
    }

    if (dist[indexes[0]][indexes[1]] == dist[indexes[1]][indexes[0]] &&
        dist[indexes[2]][indexes[3]] == dist[indexes[3]][indexes[2]]) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> indexes(4);
    for (int i = 0; i < 4; i++) {
        cin >> indexes[i];
    }

    vector<int> roads(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> roads[i];
    }

    if (isPossible(n, indexes, roads)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}