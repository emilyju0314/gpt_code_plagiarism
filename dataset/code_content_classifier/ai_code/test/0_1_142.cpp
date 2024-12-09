#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> joy(m, vector<int>(n));
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                cin >> joy[j][k];
            }
        }

        vector<int> min_joy(n);
        for (int j = 0; j < n; j++) {
            int max_joy = 0;
            for (int k = 0; k < m; k++) {
                max_joy = max(max_joy, joy[k][j]);
            }
            min_joy[j] = max_joy;
        }

        sort(min_joy.begin(), min_joy.end());

        cout << min_joy[0] << endl;
    }

    return 0;
}