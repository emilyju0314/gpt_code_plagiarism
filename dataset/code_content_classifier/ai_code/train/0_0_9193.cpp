#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int k;
        cin >> k;

        vector<vector<int>> roads(2*k - 1, vector<int>(3));
        for (int i = 0; i < 2*k - 1; i++) {
            cin >> roads[i][0] >> roads[i][1] >> roads[i][2];
        }

        sort(roads.begin(), roads.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });

        long long G = 0, B = 0;
        for (int i = 0; i < k; i++) {
            G += roads[i][2];
        }

        for (int i = k; i < 2*k - 1; i++) {
            B += roads[i][2];
        }

        cout << G << " " << B << endl;
    }

    return 0;
}