#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, h, t;
    cin >> n >> m >> h >> t;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a-1].push_back(b);
        graph[b-1].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (graph[i].size() < h + t) {
            continue;
        }

        vector<int> heads, tails;
        for (int node : graph[i]) {
            if (heads.size() < h && graph[node-1].size() >= 1) {
                heads.push_back(node);
            } else if (tails.size() < t && graph[node-1].size() >= 1) {
                tails.push_back(node);
            }

            if (heads.size() == h && tails.size() == t) {
                cout << "YES" << endl;
                cout << i+1 << " " << graph[i][0] << endl;
                for (int head : heads) {
                    cout << head << " ";
                }
                cout << endl;
                for (int tail : tails) {
                    cout << tail << " ";
                }
                cout << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}