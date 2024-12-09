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

        vector<int> minJoy(n, INT_MAX);

        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                minJoy[k] = min(minJoy[k], joy[j][k]);
            }
        }

        sort(minJoy.begin(), minJoy.end());

        cout << minJoy[n-2] << endl;
    }

    return 0;
}