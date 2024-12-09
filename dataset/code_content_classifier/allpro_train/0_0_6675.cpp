#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> garden(n);
    for (int i = 0; i < n; i++) {
        cin >> garden[i];
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
            for (int j = m - 1; j >= 0; j--) {
                if (garden[i][j] == 'W') {
                    moves++;
                }
            }
        }

        facingRight = !facingRight;

        if (i < n - 1) {
            moves++;
        }
    }

    cout << moves << endl;

    return 0;
}