#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<char>> classroom(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> classroom[i][j];
        }
    }

    int ways = 0;

    for (int i = 0; i < n; i++) {
        int consecutiveEmptySeatsInRow = 0;
        for (int j = 0; j < m; j++) {
            if (classroom[i][j] == '.') {
                consecutiveEmptySeatsInRow++;
                if (consecutiveEmptySeatsInRow == k) {
                    ways++;
                }
            } else {
                consecutiveEmptySeatsInRow = 0;
            }
        }
    }

    for (int j = 0; j < m; j++) {
        int consecutiveEmptySeatsInColumn = 0;
        for (int i = 0; i < n; i++) {
            if (classroom[i][j] == '.') {
                consecutiveEmptySeatsInColumn++;
                if (consecutiveEmptySeatsInColumn == k) {
                    ways++;
                }
            } else {
                consecutiveEmptySeatsInColumn = 0;
            }
        }
    }

    cout << ways << endl;

    return 0;
}