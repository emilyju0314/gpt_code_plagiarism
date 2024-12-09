#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int vp, vd, t, f, c;
    cin >> vp >> vd >> t >> f >> c;

    if (vp >= vd) {
        cout << 0 << endl;
        return 0;
    }

    double princess_pos = vp * t;
    int bijous = 0;

    while (princess_pos < c) {
        double time_to_meet = princess_pos / (vd - vp);
        double distance_covered_by_dragon = time_to_meet * vd;

        if (distance_covered_by_dragon >= c) {
            break;
        }

        bijous++;
        double time_to_next_meeting = c / vd + f + (c - distance_covered_by_dragon) / vp;
        princess_pos = vd * time_to_next_meeting;
    }

    cout << bijous << endl;

    return 0;
}