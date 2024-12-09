#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> x(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }

        vector<vector<int>> s(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char c;
                cin >> c;
                s[i][j] = c - '0';
            }
        }

        vector<int> p;
        for (int j = 0; j < m; j++) {
            p.push_back(j + 1);
        }

        // Sort based on the x values in descending order
        sort(p.begin(), p.end(), [&](int a, int b) {
            return x[a - 1] > x[b - 1];
        });

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < m; j++) {
                sum += s[i][p[j] - 1] * j;
            }
            x[i] = sum;
        }

        sort(x.begin(), x.end());

        for (int i = 0; i < n; i++) {
            if (i > 0) cout << " ";
            cout << x[i] + 1;
        }
        cout << "\n";
    }

    return 0;
}