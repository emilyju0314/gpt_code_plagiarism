#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int x_max, y_max, z_max, n, m, k;
    cin >> x_max >> y_max >> z_max >> n >> m >> k;

    map<pair<int, int>, int> open_times;
    map<pair<int, int>, int> close_times;

    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        open_times[{x, y}] = z;
    }

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        close_times[{x, y}] = z;
    }

    for (auto it = open_times.begin(); it != open_times.end(); it++) {
        pair<int, int> p = it->first;
        if (close_times.find(p) != close_times.end() && close_times[p] == it->second) {
            cout << "INCORRECT" << endl;
            return 0;
        }
    }

    cout << "CORRECT" << endl;

    for (int i = 0; i < k; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        if (open_times.find({x, y}) != open_times.end() && open_times[{x, y}] <= z) {
            cout << "OPEN" << endl;
        } else if (close_times.find({x, y}) != close_times.end() && close_times[{x, y}] >= z) {
            cout << "CLOSED" << endl;
        } else {
            cout << "UNKNOWN" << endl;
        }
    }

    return 0;
}