#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> chamber(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> chamber[i][j];
        }
    }

    int magic_columns = 0;
    for (int i = 0; i < n-1; i++) {
        if (chamber[i][m-1] == '#') {
            magic_columns++;
        }
    }

    bool possible = true;
    for (int i = 0; i < n; i++) {
        if (chamber[i][m-1] == '#') {
            for (int j = m-2; j >= 0; j--) {
                if (chamber[i][j] == '#') {
                    possible = false;
                    break;
                }
            }
        }
    }

    if (possible) {
        cout << magic_columns << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}