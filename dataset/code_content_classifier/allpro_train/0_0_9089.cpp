#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool canBeCleared(int n, int m, int s, int t, vector<vector<pair<int, char>>> adjList) {
    vector<int> visited(n, 0);
    vector<int> stamps(n, 0);

    stack<int> stk;
    stk.push(s);

    while (!stk.empty()) {
        int current = stk.top();
        stk.pop();
        visited[current] = 1;

        if (current == t) {
            return true;
        }

        for (auto edge : adjList[current]) {
            int next = edge.first;
            char stamp = edge.second;

            if (visited[next]) {
                if (stamps[next] < stamps[current]) {
                    return false;
                }
                continue;
            }

            if (stamp == '(') {
                stamps[next] = stamps[current];
            } else if (stamp == '[') {
                stamps[next] = stamps[current] + 1;
            } else {
                stamps[next] = stamps[current] + 2;
            }

            stk.push(next);
        }
    }

    return false;
}

int main() {
    int n, m, s, t;
    while (cin >> n >> m >> s >> t) {
        if (n == 0 && m == 0 && s == 0 && t == 0) {
            break;
        }

        vector<vector<pair<int, char>>> adjList(n);

        for (int i = 0; i < m; i++) {
            int a, b;
            char c;
            cin >> a >> b >> c;
            adjList[a-1].push_back({b-1, c});
        }

        bool result = canBeCleared(n, m, s-1, t-1, adjList);

        if (result) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}