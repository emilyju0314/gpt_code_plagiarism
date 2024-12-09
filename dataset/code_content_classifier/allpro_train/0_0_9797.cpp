#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> points(n, vector<int>(k));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> points[i][j];
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int i;
            cin >> i;
            for (int j = 0; j < k; j++) {
                int val;
                cin >> val;
                points[i-1][j] = val;
            }
        } else {
            int l, r;
            cin >> l >> r;
            int max_dist = 0;
            for (int i = l - 1; i < r; i++) {
                for (int j = i + 1; j < r; j++) {
                    int dist = 0;
                    for (int dim = 0; dim < k; dim++) {
                        dist += abs(points[i][dim] - points[j][dim]);
                    }
                    max_dist = max(max_dist, dist);
                }
            }
            cout << max_dist << endl;
        }
    }

    return 0;
}