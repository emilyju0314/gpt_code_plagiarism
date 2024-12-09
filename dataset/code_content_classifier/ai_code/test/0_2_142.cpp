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

        vector<int> maxJoy(n, 0);
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                maxJoy[k] = max(maxJoy[k], joy[j][k]);
            }
        }

        int minJoy = *min_element(maxJoy.begin(), maxJoy.end());
        cout << minJoy << endl;
    }

    return 0;
}