#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    // Calculate the minimum value of m
    int m = 1;
    while (m*m < n) {
        m++;
    }

    cout << m << endl;

    // Place the n chess pieces on the chessboard
    vector<pair<int, int>> pieces;
    for (int i = 0; i < n; i++) {
        int r = i % m + 1;  // Row index
        int c = i / m + 1;  // Column index

        if (c % 2 == 0) {
            c = m - c + 1;
        }

        pieces.push_back({r, c});
    }

    for (auto piece : pieces) {
        cout << piece.first << " " << piece.second << endl;
    }

    return 0;
}