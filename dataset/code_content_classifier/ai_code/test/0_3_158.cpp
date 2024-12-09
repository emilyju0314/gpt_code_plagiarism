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

        vector<vector<int>> responses(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++) {
                responses[i][j] = s[j] - '0';
            }
        }

        vector<int> p(m);
        for (int j = 0; j < m; j++) {
            p[j] = j + 1;
        }

        sort(p.begin(), p.end());

        cout << "Permutation for test case " << t << ": ";
        for (int j = 0; j < m; j++) {
            cout << p[j] << " ";
        }
        cout << endl;
    }

    return 0;
}