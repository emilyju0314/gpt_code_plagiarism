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

        vector<int> x(n);
        for (int j = 0; j < n; j++) {
            cin >> x[j];
        }

        vector<vector<int>> s(n, vector<int>(m));
        for (int j = 0; j < n; j++) {
            string line;
            cin >> line;
            for (int k = 0; k < m; k++) {
                s[j][k] = line[k] - '0';
            }
        }

        vector<int> p(m);
        iota(p.begin(), p.end(), 1);
        
        // Sort p in descending order based on x values
        sort(p.begin(), p.end(), [&](int a, int b) {
            return x[a-1] > x[b-1];
        });

        for (int j = 0; j < n; j++) {
            int count = 0;
            for (int k = 0; k < m; k++) {
                if (s[j][p[k] - 1] == 1) {
                    count++;
                }
            }
            x[j] = count;
        }

        sort(x.begin(), x.end());

        for (int j = 0; j < m; j++) {
            cout << x[j] << " ";
        }
        cout << endl;
    }

    return 0;
}