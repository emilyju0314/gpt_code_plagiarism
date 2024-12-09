#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n, a, d;
    cin >> n >> a >> d;

    vector<pair<int, int>> trolleys(n);
    for(int i = 0; i < n; i++) {
        cin >> trolleys[i].first >> trolleys[i].second;
    }

    for(int i = 0; i < n; i++) {
        double ti = trolleys[i].first;
        double vi = trolleys[i].second;

        double t = 0;
        double time_to_reach_target = sqrt((2 * d) / a);
        if (vi >= a * time_to_reach_target) {
            t = time_to_reach_target;
        } else {
            t = vi / a + (d - (vi * vi) / (2 * a)) / vi;
        }

        cout << fixed << setprecision(10) << t + ti << endl;
    }

    return 0;
}