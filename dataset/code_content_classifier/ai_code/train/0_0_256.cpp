#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj[1001];
vector<int> mySubtree, liChenSubtree;
vector<bool> visited(1001);

int ask_A(int x) {
    cout << "A " << x << endl;
    cout.flush();
    int y;
    cin >> y;
    return y;
}

int ask_B(int y) {
    cout << "B " << y << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}

void dfs(int node) {
    visited[node] = true;
    for (int child : adj[node]) {
        if (!visited[child]) {
            dfs(child);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            visited[i] = false;
        }

        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int k1, k2;
        cin >> k1;
        mySubtree.resize(k1);
        for (int i = 0; i < k1; i++) {
            cin >> mySubtree[i];
        }

        cin >> k2;
        liChenSubtree.resize(k2);
        for (int i = 0; i < k2; i++) {
            cin >> liChenSubtree[i];
        }

        cout << "B " << liChenSubtree[0] << endl;
        cout.flush();
        int x = ask_B(liChenSubtree[0]);

        int y = -1;
        for (int node : mySubtree) {
            int py = ask_A(node);
            if (find(liChenSubtree.begin(), liChenSubtree.end(), py) != liChenSubtree.end()) {
                y = node;
                break;
            }
        }

        if (y == -1) {
            dfs(x);
            cout << "C " << x << endl;
            cout.flush();
        } else {
            cout << "C " << y << endl;
            cout.flush();
        }
    }

    return 0;
}