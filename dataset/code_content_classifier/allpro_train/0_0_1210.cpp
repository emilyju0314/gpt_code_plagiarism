#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Balloon {
    int position;
    int time;

    Balloon(int p, int t) : position(p), time(t) {}
};

int main() {
    int n;
    
    while (true) {
        cin >> n;
        if (n == 0) break;

        vector<Balloon> balloons;
        for (int i = 0; i < n; i++) {
            int p, t;
            cin >> p >> t;
            balloons.push_back(Balloon(p, t));
        }

        int distance = 0;
        int carrying = 0;
        bool possible = true;
        int first_fail = 0;

        for (int i = 0; i < n; i++) {
            int time_needed = balloons[i].position + carrying - distance;

            if (time_needed <= balloons[i].time) {
                distance = balloons[i].position + carrying;
                carrying = min(carrying + 1, 3);
            } else {
                possible = false;
                first_fail = i + 1;
                break;
            }
        }

        if (possible) {
            cout << "OK " << distance << endl;
        } else {
            cout << "NG " << first_fail << endl;
        }
    }

    return 0;
}