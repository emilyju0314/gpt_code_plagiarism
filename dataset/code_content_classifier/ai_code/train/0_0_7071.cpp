#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<char>> basement(n, vector<char>(m));
    pair<int, int> exitPos;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> basement[i][j];
            if (basement[i][j] == 'E') {
                exitPos = {i, j};
            }
        }
    }

    string commands;
    cin >> commands;

    pair<int, int> robotPos = exitPos;
    int prefixLength = 0;

    for (int i = 0; i < k; i++) {
        if (commands[i] == 'L') {
            if (robotPos.second > 0 && basement[robotPos.first][robotPos.second - 1] != '#') {
                robotPos.second--;
            }
        } else if (commands[i] == 'R') {
            if (robotPos.second < m - 1 && basement[robotPos.first][robotPos.second + 1] != '#') {
                robotPos.second++;
            }
        } else if (commands[i] == 'U') {
            if (robotPos.first > 0 && basement[robotPos.first - 1][robotPos.second] != '#') {
                robotPos.first--;
            }
        } else if (commands[i] == 'D') {
            if (robotPos.first < n - 1 && basement[robotPos.first + 1][robotPos.second] != '#') {
                robotPos.first++;
            }
        }

        if (robotPos == exitPos) {
            prefixLength = i + 1;
            break;
        }
    }

    cout << (prefixLength > 0 ? prefixLength : -1) << endl;

    return 0;
}