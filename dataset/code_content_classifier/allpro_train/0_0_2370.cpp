#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Gripper {
    int x, y, m, p, r;
};

bool canGrip(const Gripper& g1, const Gripper& g2) {
    int dx = g1.x - g2.x;
    int dy = g1.y - g2.y;
    int distance = sqrt(dx*dx + dy*dy);
    if (distance <= g1.r) {
        if (g1.m >= g2.p) {
            return true;
        }
    }
    return false;
}

int main() {
    int x, y, p, r, n;
    cin >> x >> y >> p >> r >> n;

    vector<Gripper> grippers(n);
    for (int i = 0; i < n; i++) {
        cin >> grippers[i].x >> grippers[i].y >> grippers[i].m >> grippers[i].p >> grippers[i].r;
    }

    vector<bool> visited(n, false);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (canGrip({x, y, 0, p, r}, grippers[i])) {
            visited[i] = true;
            count++;
        }
    }

    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (visited[j] && canGrip(grippers[j], grippers[i])) {
                        visited[i] = true;
                        changed = true;
                        count++;
                        break;
                    }
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}