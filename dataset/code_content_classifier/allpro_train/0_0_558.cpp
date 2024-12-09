#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> table(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch;
            cin >> ch;
            table[i][j] = ch - '0';
        }
    }

    vector<int> moveX(10), moveY(10);
    for (int i = 0; i < 10; i++) {
        cin >> moveX[i] >> moveY[i];
    }

    for (int t = 0; t < q; t++) {
        string s;
        cin >> s;

        bool found = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vector<vector<bool>> visited(n, vector<bool>(m, false));
                int x = i, y = j, ptr = 0;
                while (ptr < s.size() && x >= 0 && x < n && y >= 0 && y < m && !visited[x][y]) {
                    visited[x][y] = true;
                    if (s[ptr] == table[x][y] + '0') {
                        ptr++;
                        if (ptr == s.size()) {
                            found = true;
                            break;
                        }
                    }
                    x += moveX[table[x][y]];
                    y += moveY[table[x][y]];
                }
                if (found) break;
            }
            if (found) break;
        }

        if (found) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}