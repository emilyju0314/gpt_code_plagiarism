#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> table(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> table[i][j];
        }
    }

    int max_val = 0;
    int a, b;

    for (int i = k; i <= n - k + 1; i++) {
        for (int j = k; j <= m - k + 1; j++) {
            int cur_val = 0;
            for (int x = i - k; x < i + k; x++) {
                for (int y = j - k; y < j + k; y++) {
                    cur_val += table[x][y];
                }
            }
            if (cur_val > max_val) {
                max_val = cur_val;
                a = i;
                b = j;
            }
        }
    }

    cout << a << " " << b << endl;

    return 0;
}