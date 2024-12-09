#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    if (n == 1 && m == 1) {
        cout << "YES" << endl;
        cout << 1 << endl;
    } else if ((n == 1 && m != 1) || (n != 1 && m == 1) || (n == 2 && m == 2)) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        vector<vector<int>> matrix(n, vector<int>(m));

        int x = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i + j) % 2 == 0) {
                    matrix[i][j] = x;
                    x++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i + j) % 2 == 1) {
                    matrix[i][j] = x;
                    x++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}