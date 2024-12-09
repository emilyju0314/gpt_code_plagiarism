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

        vector<int> max_joy(n, 0);

        for (int i = 0; i < m; i++) {
            int min_joy = INT_MAX;

            for (int j = 0; j < n; j++) {
                min_joy = min(min_joy, joy[i][j]);
            }

            for (int j = 0; j < n; j++) {
                max_joy[j] = max(max_joy[j], joy[i][j] - min_joy);
            }
        }

        int result = INT_MAX;

        for (int j = 0; j < n; j++) {
            result = min(result, max_joy[j]);
        }

        cout << result << endl;
    }

    return 0;
}