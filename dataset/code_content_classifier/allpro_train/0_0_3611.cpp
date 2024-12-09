#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, c_l, c_e, v;
    cin >> n >> m >> c_l >> c_e >> v;

    vector<int> stairs(c_l);
    for (int i = 0; i < c_l; i++) {
        cin >> stairs[i];
    }

    vector<int> elevators(c_e);
    for (int i = 0; i < c_e; i++) {
        cin >> elevators[i];
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int min_time = abs(x1 - x2); // time to move floors with stairs or elevator

        if (stairs.empty() || elevators.empty()) {
            min_time += abs(y1 - y2); // time to move between sections on the same floor
        } else {
            int stair_time = abs(y1 - stairs[0]) + abs(stairs[0] - y2);
            int elevator_time = abs(y1 - elevators[0]) + abs(elevators[0] - y2);

            min_time += min(stair_time, elevator_time);
        }

        cout << min_time << endl;
    }

    return 0;
}