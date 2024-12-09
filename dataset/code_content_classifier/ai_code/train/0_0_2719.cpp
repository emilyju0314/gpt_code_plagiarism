#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> arrays(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arrays[i][j];
        }
    }

    cout << m * (m - 1) / 2 << endl;
    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            if (k == 0) {
                cout << i << " " << j << endl;
            } else {
                cout << j << " " << i << endl;
            }
        }
    }

    return 0;
}