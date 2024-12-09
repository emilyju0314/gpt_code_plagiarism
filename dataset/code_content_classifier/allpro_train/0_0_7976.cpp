#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> garden(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> garden[i][j];
        }
    }

    int moves = 0;
    bool facingRight = true;
    for (int i = 0; i < n; i++) {
        if (facingRight) {
            for (int j = 0; j < m; j++) {
                if (garden[i][j] == 'W') {
                    moves++;
                }
            }
        } else {
            for (int j = m-1; j >= 0; j--) {
                if (garden[i][j] == 'W') {
                    moves++;
                }
            }
        }

        facingRight = !facingRight;
    }

    cout << moves << endl;

    return 0;
}