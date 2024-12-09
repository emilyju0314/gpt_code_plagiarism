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
            p[j] = j+1;
        }

        sort(p.begin(), p.end(), [&](int a, int b) {
            int sum1 = 0, sum2 = 0;
            for (int i = 0; i < n; i++) {
                int points = 0;
                for (int j = 0; j < m; j++) {
                    if (s[i][j] == 1 && p[j] < a) {
                        points++;
                    }
                }
                sum1 += abs(x[i] - points);
            }

            swap(p[a], p[b]);

            for (int i = 0; i < n; i++) {
                int points = 0;
                for (int j = 0; j < m; j++) {
                    if (s[i][j] == 1 && p[j] < b) {
                        points++;
                    }
                }
                sum2 += abs(x[i] - points);
            }

            swap(p[a], p[b]);

            return sum1 > sum2;
        });

        for (int j = 0; j < m; j++) {
            cout << p[j] << " ";
        }

        cout << endl;
    }

    return 0;
}