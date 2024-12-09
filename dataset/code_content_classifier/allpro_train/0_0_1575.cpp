#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 2005;

vector<int> graph[MAXN];
int cnt[MAXN];
int anc[MAXN];
vector<int> leaves;

bool compare(int u, int v) {
    return cnt[u] < cnt[v];
}

void bfs(int start) {
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (graph[cur].empty()) {
            leaves.push_back(cur);
            continue;
        }

        sort(graph[cur].begin(), graph[cur].end(), compare);

        int val = 1;
        for (int neighbour : graph[cur]) {
            cnt[neighbour] = val++;
            q.push(neighbour);
        }
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int p, c;
        cin >> p >> c;
        if (p != 0) {
            graph[p].push_back(i);
        } else {
            anc[i] = i;
            leaves.push_back(i);
        }
        cnt[i] = c;
    }

    for (int leaf : leaves) {
        bfs(leaf);
    }

    for (int i = 1; i <= n; i++) {
        for (int neighbour : graph[i]) {
            if (cnt[neighbour] <= cnt[i]) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) {
        cout << cnt[i] << " ";
    }
    return 0;
}