#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Trolleybus {
    int t, v;
};

int main() {
    int n, a, d;
    cin >> n >> a >> d;

    vector<Trolleybus> trolleys(n);
    for (int i = 0; i < n; i++) {
        cin >> trolleys[i].t >> trolleys[i].v;
    }

    for (int i = 0; i < n; i++) {
        double t_i = (double)trolleys[i].t + 1.0 * d / trolleys[i].v;
        for (int j = i - 1; j >= 0; j--) {
            double time_diff = 1.0 * trolleys[j].v / a;
            double meeting_point = trolleys[j].t + 1.0 * trolleys[j].v * time_diff + 0.5 * a * time_diff * time_diff;
            if (trolleys[i].t >= meeting_point) {
                t_i = max(t_i, meeting_point + 1.0 * (d - meeting_point) / trolleys[i].v);
                break;
            }
        }

        cout << fixed << setprecision(10) << t_i << endl;
    }

    return 0;
}