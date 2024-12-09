#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        if (m < n || n == 2) {
            cout << -1 << endl;
        } else {
            int total_cost = 0;
            vector<pair<int, int>> chains;

            for (int i = 0; i < n; i++) {
                total_cost += a[i] + a[(i+1) % n];
                chains.push_back({i+1, (i+1) % n + 1});
            }

            total_cost += a[0] + a[2];
            chains.push_back({1, 3});

            cout << total_cost << endl;
            for (int i = 0; i < m; i++) {
                cout << chains[i].first << " " << chains[i].second << endl;
            }
        }
    }
    
    return 0;
}