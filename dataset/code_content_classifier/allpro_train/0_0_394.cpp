#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> parent(n + 1), type(n + 1);
    for (int i = 1; i <= n; i++) {
        int p, t;
        cin >> p >> t;
        parent[i] = p;
        type[i] = t;
    }

    int q;
    cin >> q;

    while (q--) {
        int queryType, u, v;
        cin >> queryType >> u >> v;

        if (queryType == 1) { // special case query
            bool specialCase = false;
            while (v != -1) {
                if (v == u) {
                    specialCase = true;
                    break;
                }
                v = parent[v];
            }
            if (specialCase) cout << "YES" << endl;
            else cout << "NO" << endl;
        } else if (queryType == 2) { // part query
            bool part = false;
            while (u != -1) {
                if (u == v) {
                    part = true;
                    break;
                }
                u = parent[u];
            }
            if (part) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }

    return 0;
}