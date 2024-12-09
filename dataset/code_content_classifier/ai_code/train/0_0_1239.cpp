#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> plates(n);
    for (int i = 0; i < n; i++) {
        cin >> plates[i];
    }

    vector<pair<int, int>> friends;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        friends.push_back({x, y});
    }

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        graph[friends[i].first - 1].push_back(friends[i].second - 1);
        graph[friends[i].second - 1].push_back(friends[i].first - 1);
    }

    queue<int> q;
    vector<bool> visited(m, false);

    for (int i = 0; i < m; i++) {
        q.push(i);
    }

    vector<int> order;

    while (!q.empty()) {
        int friend_idx = q.front();
        q.pop();

        int food1 = friends[friend_idx].first - 1;
        int food2 = friends[friend_idx].second - 1;

        if (plates[food1] > 0 && plates[food2] > 0) {
            plates[food1]--;
            plates[food2]--;
            visited[friend_idx] = true;
            order.push_back(friend_idx);
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i] && plates[friends[i].first - 1] > 0 && plates[friends[i].second - 1] > 0) {
                q.push(i);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (plates[i] > 0) {
            cout << "DEAD" << endl;
            return 0;
        }
    }

    cout << "ALIVE" << endl;
    for (int i = 0; i < order.size(); i++) {
        cout << order[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}