#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<bool>> deleted(n, vector<bool>(n, false));

    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int j = x1 - 1; j < x2; j++) {
            for (int k = y1 - 1; k < y2; k++) {
                deleted[j][k] = true;
            }
        }
    }

    int rooks = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!deleted[i][j]) {
                rooks++;
                for (int k = 0; k < n; k++) {
                    deleted[i][k] = true;
                    deleted[k][j] = true;
                }
            }
        }
    }

    cout << rooks << endl;

    return 0;
}