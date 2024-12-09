#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> parent(n + 1);
    vector<int> depth(n + 1);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        depth[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;

        if (t == 1) {
            int x, y;
            cin >> x >> y;
            parent[x] = y;
            depth[x] = depth[y] + 1;
        } else if (t == 2) {
            int x;
            cin >> x;
        } else {
            int x, i;
            cin >> x >> i;
            while (depth[x] > 0 && i > 0) {
                x = parent[x];
                i--;
            }
            if (i == 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}