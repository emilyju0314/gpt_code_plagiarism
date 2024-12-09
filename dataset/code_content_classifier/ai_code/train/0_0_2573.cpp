#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    if (a == 1 && b == 1) {
        if (n == 2) {
            cout << "NO" << endl;
            return 0;
        }
    }

    if (a == 1 && b == 2) {
        if (n == 2) {
            cout << "NO" << endl;
            return 0;
        }
        if ((n == 3) || (n == 4)) {
            cout << "NO" << endl;
            return 0;
        }
    }

    if (a == 1 && b == 3) {
        if (n == 2) {
            cout << "NO" << endl;
            return 0;
        }
        if (n == 3) {
            cout << "NO" << endl;
            return 0;
        }
    }

    if (a == 2 && b == 2) {
        if ((n == 2) || (n == 3)) {
            cout << "NO" << endl;
            return 0;
        }
    }

    if (a == 2 && b == 3) {
        if (n == 2) {
            cout << "NO" << endl;
            return 0;
        }
        if (n == 3) {
            cout << "NO" << endl;
            return 0;
        }
        if ((n == 4) || (n == 5)) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    vector<vector<int>> matrix(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a > 1) {
               matrix[i][j] = 1;
               matrix[j][i] = 1;
               a--;
            } else if (b > 1) {
               matrix[i][j] = 0;
               matrix[j][i] = 0;
               b--;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }

    return 0;
}