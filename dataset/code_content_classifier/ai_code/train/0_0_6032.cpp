#include <iostream>
#include <vector>

using namespace std;

struct Time {
    int h;
    int m;
};

int timeDiff(const Time& t1, const Time& t2) {
    return (t2.h - t1.h) * 60 + (t2.m - t1.m);
}

int main() {
    int n, s;
    cin >> n >> s;

    vector<Time> landings(n);
    for (int i = 0; i < n; i++) {
        cin >> landings[i].h >> landings[i].m;
    }

    Time takeoffTime;
    int earliestTime = 0;

    if (landings[0].h * 60 + landings[0].m >= s + 1) {
        takeoffTime.h = 0;
        takeoffTime.m = 0;
    } else {
        for (int i = 1; i < n; i++) {
            if (timeDiff(landings[i - 1], landings[i]) >= 2 * s + 2) {
                takeoffTime = landings[i - 1];
                takeoffTime.m += s + 1;
                if (takeoffTime.m >= 60) {
                    takeoffTime.m -= 60;
                    takeoffTime.h++;
                }
                earliestTime = 1;
                break;
            }
        }

        if (earliestTime == 0) {
            takeoffTime = landings[n - 1];
            takeoffTime.m++;
            if (takeoffTime.m >= 60) {
                takeoffTime.m -= 60;
                takeoffTime.h++;
            }
        }
    }

    cout << takeoffTime.h << " " << takeoffTime.m << endl;

    return 0;
}