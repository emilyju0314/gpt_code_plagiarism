#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, s_x, s_y;
    cin >> n >> s_x >> s_y;

    vector<pair<int, int>> houses(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        houses[i] = make_pair(x, y);
    }

    int max_students = 0;
    pair<int, int> optimal_location;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int count = 0;
            for (int k = 0; k < n; k++) {
                if (min(abs(houses[k].first - s_x), abs(houses[k].second - s_y)) >= max(abs(i), abs(j))) {
                    count++;
                }
            }
            if (count > max_students) {
                max_students = count;
                optimal_location = make_pair(s_x + i, s_y + j);
            }
        }
    }

    cout << max_students << endl;
    cout << optimal_location.first << " " << optimal_location.second << endl;

    return 0;
}