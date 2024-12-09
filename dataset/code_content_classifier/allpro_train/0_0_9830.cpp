#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> B(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> B[i][j];
        }
    }

    vector<vector<int>> A(m, vector<int>(n, 1));

    bool possible = true;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (B[i][j] == 0) {
                bool row_all_ones = true;
                for (int k = 0; k < n; k++) {
                    if (B[i][k] == 1) {
                        row_all_ones = false;
                        break;
                    }
                }
                
                bool col_all_ones = true;
                for (int k = 0; k < m; k++) {
                    if (B[k][j] == 1) {
                        col_all_ones = false;
                        break;
                    }
                }
                
                if (row_all_ones && col_all_ones) {
                    possible = false;
                    break;
                }
            }
        }
        if (!possible) {
            break;
        }
    }

    if (possible) {
        cout << "YES" << endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}    