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

        vector<vector<int>> p(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> p[i][j];
            }
        }

        vector<int> minJoy(n, INT_MAX);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                minJoy[j] = min(minJoy[j], p[i][j]);
            }
        }

        sort(minJoy.begin(), minJoy.end());
        cout << minJoy[n - 2] << endl;
    }

    return 0;
}