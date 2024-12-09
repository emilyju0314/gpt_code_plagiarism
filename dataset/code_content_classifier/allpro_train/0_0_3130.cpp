#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> queens(m);
    vector<int> threateningQueens(9, 0);

    for (int i = 0; i < m; i++) {
        int r, c;
        cin >> r >> c;
        queens[i] = {r, c};
    }

    for (int i = 0; i < m; i++) {
        int r = queens[i].first;
        int c = queens[i].second;

        int threats = 0;

        for (pair<int, int> queen : queens) {
            int dr = abs(r - queen.first);
            int dc = abs(c - queen.second);

            if (r == queen.first || c == queen.second || dr == dc) {
                threats++;
            }
        }

        threateningQueens[threats]++;
    }

    for (int i = 0; i < 9; i++) {
        cout << threateningQueens[i] << " ";
    }

    return 0;
}