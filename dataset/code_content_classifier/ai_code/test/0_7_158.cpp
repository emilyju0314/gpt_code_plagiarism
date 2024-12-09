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
            string str;
            cin >> str;
            for (int j = 0; j < m; j++) {
                s[i][j] = str[j] - '0';
            }
        }

        vector<int> p(m);
        for (int j = 0; j < m; j++) {
            p[j] = j + 1;
        }

        sort(p.begin(), p.end(), [&](int i, int j){
            int sum_i = 0, sum_j = 0;
            for (int k = 0; k < n; k++) {
                if (s[k][i - 1] == 1) {
                    sum_i += x[k];
                }
                if (s[k][j - 1] == 1) {
                    sum_j += x[k];
                }
            }
            return abs(sum_i - (m * (m + 1) / 2 / 2)) > abs(sum_j - (m * (m + 1) / 2 / 2));
        });

        for (int j = 0; j < m; j++) {
            cout << p[j] << " ";
        }
        cout << endl;
    }

    return 0;
}