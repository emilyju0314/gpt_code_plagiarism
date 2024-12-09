#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> moves(n);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        moves[i] = {x, y};
    }

    vector<int> result;
    long long x_pos = 0, y_pos = 0;

    for (int i = 0; i < n; i++) {
        long long x1 = x_pos + moves[i].first, y1 = y_pos + moves[i].second;
        long long x2 = x_pos - moves[i].first, y2 = y_pos - moves[i].second;

        if (sqrt(x1*x1 + y1*y1) <= 1.5e6) {
            x_pos = x1;
            y_pos = y1;
            result.push_back(1);
        } else {
            x_pos = x2;
            y_pos = y2;
            result.push_back(-1);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}