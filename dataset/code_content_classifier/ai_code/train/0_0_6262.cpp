#include <iostream>

using namespace std;

int main() {
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;

    char ans[n][m];

    // Fill the room with empty spaces
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans[i][j] = '.';
        }
    }

    // Try to lay 2x2 planks first
    for (int i = 0; i < n-1; i += 2) {
        for (int j = 0; j < m-1; j += 2) {
            if (c > 0) {
                ans[i][j] = ans[i][j+1] = ans[i+1][j] = ans[i+1][j+1] = 'a' + (i/2) % 26;
                c--;
            }
        }
    }

    // Try to lay 2x1 planks next
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m-1; j++) {
            if (a > 0) {
                if (ans[i][j] == '.') {
                    ans[i][j] = ans[i][j+1] = 'a' + (i+j) % 26;
                    a--;
                }
            }
        }
    }

    // Try to lay 1x2 planks last
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m; j++) {
            if (b > 0) {
                if (ans[i][j] == '.' && ans[i+1][j] == '.') {
                    ans[i][j] = ans[i+1][j] = 'a' + (i+j) % 26;
                    b--;
                }
            }
        }
    }

    if (a > 0 || b > 0 || c > 0) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << ans[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}