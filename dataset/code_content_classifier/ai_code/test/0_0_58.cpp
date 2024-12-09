#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<string>& level, int x, int y) {
    if (x < 0 || x >= 2 || y < 0 || y >= level[0].size()) {
        return false;
    }
    if (level[x][y] == '1') {
        return false;
    }
    return true;
}

string canCompleteLevel(int n, vector<string>& level) {
    int x = 0, y = 0;
    while (true) {
        if (x == 1 && y == n - 1) {
            return "YES";
        }
        if (isSafe(level, x + 1, y + 1)) {
            x++;
            y++;
        }
        else if (isSafe(level, x, y + 1)) {
            y++;
        }
        else if (isSafe(level, x + 1, y)) {
            x++;
        }
        else {
            return "NO";
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<string> level(2);
        cin >> level[0] >> level[1];

        cout << canCompleteLevel(n, level) << endl;
    }

    return 0;
}