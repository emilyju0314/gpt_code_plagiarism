#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<vector<char>> room(n, vector<char>(n, '.'));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i+j)%2 == 0 && x > 1) {
                room[i][j] = '>';
                x--;
            } else if (x > 1) {
                room[i][j] = '^';
                x--;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << room[i][j];
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (room[i][j] != '.') {
                cout << i+1 << " " << j+1 << endl;
                return 0;
            }
        }
    }

    return 0;
}