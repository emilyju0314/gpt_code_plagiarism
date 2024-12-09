#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> field(n);
    for (int i = 0; i < n; i++) {
        cin >> field[i];
    }

    bool valid = true;
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] != '*') {
                int bombs = 0;
                for (int k = 0; k < 8; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && field[ni][nj] == '*') {
                        bombs++;
                    }
                }
                if (field[i][j] == '.') {
                    if (bombs > 0) {
                        valid = false;
                        break;
                    }
                } else {
                    if (bombs != field[i][j] - '0') {
                        valid = false;
                        break;
                    }
                }
            }
        }
        if (!valid) {
            break;
        }
    }

    if (valid) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}