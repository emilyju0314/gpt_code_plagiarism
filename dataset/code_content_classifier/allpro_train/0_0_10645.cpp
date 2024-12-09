#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, A, B, C;
    cin >> n >> A >> B >> C;

    vector<pair<int, int>> rocks(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        rocks[i] = {x, y};
    }

    double distance_to_destination = sqrt(pow(rocks[n-1].first - rocks[0].first, 2) + pow(rocks[n-1].second - rocks[0].second, 2));

    if (distance_to_destination > A + B + C) {
        cout << -1 << endl;
    } else {
        cout << 3 << endl;
    }

    return 0;
}