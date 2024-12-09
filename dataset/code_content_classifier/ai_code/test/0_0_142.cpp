#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> p(m, vector<int>(n));
        vector<int> a(n);

        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                cin >> p[j][k];
            }
        }

        for (int j = 0; j < n; j++) {
            int max_joy = p[0][j];
            for (int k = 0; k < m; k++) {
                max_joy = max(max_joy, p[k][j]);
            }
            a[j] = max_joy;
        }

        sort(a.begin(), a.end());

        cout << a[0] << endl;
    }

    return 0;
}