#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int k;
vector<vector<long long>> grid;
vector<vector<int>> figure;
int t;

bool can_be_zero(int p) {
    for (int x = 0; x < (1 << k); x++) {
        for (int y = 0; y < (1 << k); y++) {
            long long total = 0;
            for (int i = 0; i < t; i++) {
                int xi = figure[i][0];
                int yi = figure[i][1];
                total ^= grid[(x + xi - 1) % (1 << k)][(y + yi - 1) % (1 << k)];
            }
            if (total != 0) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    cin >> k;
    grid = vector<vector<long long>>(1 << k, vector<long long>(1 << k));
    for (int i = 0; i < (1 << k); i++) {
        for (int j = 0; j < (1 << k); j++) {
            cin >> grid[i][j];
        }
    }

    cin >> t;
    figure = vector<vector<int>>(t, vector<int>(2));
    for (int i = 0; i < t; i++) {
        cin >> figure[i][0] >> figure[i][1];
    }

    int min_ops = INT_MAX;
    for (int p = 0; p < (1 << k); p++) {
        if (can_be_zero(p)) {
            int ops = 0;
            for (int i = 0; i < k; i++) {
                if ((p >> i) & 1) {
                    ops++;
                }
            }
            min_ops = min(min_ops, ops);
        }
    }

    if (min_ops == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << min_ops << endl;
    }

    return 0;
}