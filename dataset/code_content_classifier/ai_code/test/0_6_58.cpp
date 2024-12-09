#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isSafe(vector<string>& level, int x, int y) {
    return x >= 0 && x < 2 && y >= 0 && y < level[0].size() && level[x][y] == '0';
}

bool isPossibleToComplete(int n, vector<string>& level) {
    int x = 0, y = 0;
    while (y < n - 1) {
        if (isSafe(level, x, y + 1)) {
            y++;
        } else if (isSafe(level, x + 1, y + 1)) {
            x++;
            y++;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<string> level(2);
        cin >> level[0] >> level[1];

        if (isPossibleToComplete(n, level)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}