#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> joy(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> joy[i][j];
            }
        }

        vector<int> friendJoy(n, INT_MAX);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                friendJoy[j] = min(friendJoy[j], joy[i][j]);
            }
        }

        sort(friendJoy.begin(), friendJoy.end());

        cout << friendJoy[1] << endl;
    }

    return 0;
}