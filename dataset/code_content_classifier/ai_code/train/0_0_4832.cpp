#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Barrier {
    int x, y, r;
};

double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

bool isInsideBarrier(int x, int y, const Barrier& barrier) {
    return distance(x, y, barrier.x, barrier.y) <= barrier.r;
}

double minExposureTime(int x_s, int y_s, int x_t, int y_t, const vector<Barrier>& barriers) {
    double min_time = distance(x_s, y_s, x_t, y_t);
    for (const Barrier& barrier : barriers) {
        if (isInsideBarrier(x_s, y_s, barrier) != isInsideBarrier(x_t, y_t, barrier)) {
            // Snuke's initial position and target position are on different side of the barrier
            double time_to_barrier = distance(x_s, y_s, barrier.x, barrier.y) - barrier.r;
            double time_from_barrier = distance(barrier.x, barrier.y, x_t, y_t) - barrier.r;
            min_time = min(min_time, time_to_barrier + time_from_barrier);
        }
    }
    return min_time;
}

int main() {
    int x_s, y_s, x_t, y_t;
    cin >> x_s >> y_s >> x_t >> y_t;

    int N;
    cin >> N;

    vector<Barrier> barriers(N);
    for (int i = 0; i < N; i++) {
        cin >> barriers[i].x >> barriers[i].y >> barriers[i].r;
    }

    double result = minExposureTime(x_s, y_s, x_t, y_t, barriers);
    cout << fixed << result << endl;

    return 0;
}