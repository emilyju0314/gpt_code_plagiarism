#include <iostream>
#include <cmath>

using namespace std;

struct Obstacle {
    int x, y, z, r, l;
};

int main() {
    int N, Q;
    cin >> N >> Q;

    Obstacle obstacles[N];
    for (int i = 0; i < N; i++) {
        cin >> obstacles[i].x >> obstacles[i].y >> obstacles[i].z >> obstacles[i].r >> obstacles[i].l;
    }

    for (int i = 0; i < Q; i++) {
        int sx, sy, sz, dx, dy, dz;
        cin >> sx >> sy >> sz >> dx >> dy >> dz;

        double minPower = INFINITY;
        for (int j = 0; j < N; j++) {
            double distance = sqrt(pow(dx - obstacles[j].x, 2) + pow(dy - obstacles[j].y, 2) + pow(dz - obstacles[j].z, 2));
            double power = max(0.0, distance - obstacles[j].r) * obstacles[j].l;
            minPower = min(minPower, power);
        }

        cout << static_cast<int>(minPower) << endl;
    }

    return 0;
}