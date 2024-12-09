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

        vector<int> p(m);
        for (int j = 0; j < m; j++) {
            p[j] = j + 1;
        }

        sort(p.begin(), p.end());

        vector<int> result(m);
        int max_surprise = 0;

        do {
            int surprise = 0;
            for (int i = 0; i < n; i++) {
                int sum = 0;
                for (int j = 0; j < m; j++) {
                    sum += s[i][j] * p[j];
                }
                surprise += abs(x[i] - sum);
            }

            if (surprise > max_surprise) {
                max_surprise = surprise;
                result = p;
            }
        } while (next_permutation(p.begin(), p.end()));

        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}