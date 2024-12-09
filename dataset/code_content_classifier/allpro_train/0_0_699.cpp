#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> matching;
    set<int> used_vertices;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        
        if (used_vertices.count(u) || used_vertices.count(v)) {
            continue;
        }
        
        matching.push_back(i + 1);
        used_vertices.insert(u);
        used_vertices.insert(v);
        
        if (matching.size() == n) {
            cout << "Matching" << endl;
            for (int edge : matching) {
                cout << edge << " ";
            }
            cout << endl;
            return;
        }
    }

    cout << "IndSet" << endl;
    int remaining = n;
    for (int i = 1; i <= 3 * n; i++) {
        if (used_vertices.count(i) == 0) {
            cout << i << " ";
            remaining--;
        }
        if (remaining == 0) {
            cout << endl;
            return;
        }
    }

    cout << "Impossible" << endl;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}