#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    if (n == 1 && m == 1) {
        cout << "YES\n1\n";
    } else if (n == 1 || m == 1) {
        cout << "NO\n";
    } else if (n == 2 && m == 2) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        int curr = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i + j) % 2 == 0) {
                    matrix[i][j] = curr;
                    curr += 1;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i + j) % 2 == 1) {
                    matrix[i][j] = curr;
                    curr += 1;
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