#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> field(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> field[i][j];
        }
    }

    int x = 0, y = 0;
    char dir = 'R';
    while (true) {
        if (dir == 'L') {
            cout << dir << endl;
            x--;
        } else if (dir == 'R') {
            cout << dir << endl;
            x++;
        } else if (dir == 'U') {
            cout << dir << endl;
            y--;
        } else if (dir == 'D') {
            cout << dir << endl;
            y++;
        }

        cout.flush();

        int new_x, new_y;
        cin >> new_x >> new_y;

        if (field[new_x - 1][new_y - 1] == 'F') {
            break;
        } else if (field[new_x - 1][new_y - 1] == '*') {
            return 0;
        } else {
            x = new_x - 1;
            y = new_y - 1;
        }

        if (dir == 'R') {
            dir = 'L';
        } else if (dir == 'L') {
            dir = 'R';
        } else if (dir == 'U') {
            dir = 'D';
        } else {
            dir = 'U';
        }
    }

    return 0;
}