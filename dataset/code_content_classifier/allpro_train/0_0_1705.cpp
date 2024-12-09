#include <iostream>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int row, col;
    if (k < n) {
        row = k + 1;
        col = 1;
    } else {
        row = (k - n) / (m - 1) + 1;
        if (row % 2 != 0) {
            col = 2 + (k - n) % (m - 1);
        } else {
            col = m - (k - n) % (m - 1);
        }
    }

    cout << row << " " << col;

    return 0;
}