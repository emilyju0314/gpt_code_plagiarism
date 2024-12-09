#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> f(n);
    unordered_map<int, int> g_map, h_map;

    int m = 0;
    vector<int> g, h;

    for (int i = 0; i < n; i++) {
        cin >> f[i];
        m = max(m, f[i]);
    }

    for (int i = 0; i < n; i++) {
        if (g_map.find(f[i]) == g_map.end()) {
            g_map[f[i]] = ++m;
        }
        g.push_back(g_map[f[i]]);
    }

    if (m > n) {
        cout << m << endl;
        for (int i = 0; i < n; i++) {
            cout << g[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < m; i++) {
            cout << i + 1 << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}