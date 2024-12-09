#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k, p;
    cin >> n >> m;
    cin >> k;

    vector<vector<int>> table(n, vector<int>(m, 0));
    for (int i = 0; i < k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        table[a-1][b-1] = c;
    }

    cin >> p;

    int count = 0;

    if (k == 0) {
        count = 2;
    } else {
        for (int i = 0; i < n; i++) {
            int negCount = 0;
            int rowCount = 0;
            for (int j = 0; j < m; j++) {
                if (table[i][j] == -1) negCount++;
                if (table[i][j] != 0) rowCount++;
            }
            if (rowCount == 0) continue;
            if (rowCount == 1) {
                if (negCount == 0) count = (count + 1) % p;
            } else if(negCount > 0) {
                count = (count + 1) % p;
            }
        }

        for (int j = 0; j < m; j++) {
            int negCount = 0;
            int colCount = 0;
            for (int i = 0; i < n; i++) {
                if (table[i][j] == -1) negCount++;
                if (table[i][j] != 0) colCount++;
            }
            if (colCount == 0) continue;
            if (colCount == 1) {
                if (negCount == 0) count = (count + 1) % p;
            } else if(negCount > 0) {
                count = (count + 1) % p;
            }
        }
    }

    cout << count << endl;

    return 0;
}