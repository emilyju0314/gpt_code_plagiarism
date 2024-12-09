#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x0, y0;
    cin >> n >> x0 >> y0;

    vector<pair<int, int>> stormtroopers(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        stormtroopers[i] = {x, y};
    }

    int shots = 0;
    sort(stormtroopers.begin(), stormtroopers.end());

    for (int i = 0; i < n; i++) {
        int xi = stormtroopers[i].first;
        int yi = stormtroopers[i].second;

        if (xi == x0 || yi == y0) {
            shots++;
        } else if ((xi > x0 && yi > y0) || (xi < x0 && yi < y0)) {
            shots++;
        }
    }

    cout << shots << endl;

    return 0;
}