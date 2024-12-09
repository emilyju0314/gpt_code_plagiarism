#include <iostream>
#include <vector>

using namespace std;

int main() {
    int q;
    cin >> q;

    while (q--) {
        int n, m;
        cin >> n >> m;

        vector<vector<char>> picture(n, vector<char>(m));

        vector<int> rowCount(n, 0);
        vector<int> colCount(m, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> picture[i][j];
                if (picture[i][j] == '.') {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }

        int maxWhite = 0;
        for (int i = 0; i < n; i++) {
            maxWhite = max(maxWhite, rowCount[i]);
        }
        for (int j = 0; j < m; j++) {
            maxWhite = max(maxWhite, colCount[j]);
        }

        int minMinutes = n * m - maxWhite;

        cout << minMinutes << endl;
    }

    return 0;
}