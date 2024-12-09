#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> room(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            room[i][j] = row[j] - '0';
        }
    }

    int perimeter = 0;

    // Check horizontal
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            if (room[i][j] == 1) {
                perimeter += cnt * 2;
                cnt = 0;
            } else {
                cnt++;
            }
        }
        perimeter += cnt * 2;
    }

    // Check vertical
    for (int j = 0; j < m; j++) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (room[i][j] == 1) {
                perimeter += cnt * 2;
                cnt = 0;
            } else {
                cnt++;
            }
        }
        perimeter += cnt * 2;
    }

    cout << perimeter << endl;

    return 0;
}