#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Ghost {
    int x, vx, vy;
};

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<Ghost> ghosts(n);
    for (int i = 0; i < n; i++) {
        cin >> ghosts[i].x >> ghosts[i].vx >> ghosts[i].vy;
    }

    long long experience = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double t = 0;
            if (ghosts[i].vx != ghosts[j].vx) {
                t = (double)(ghosts[j].x - ghosts[i].x) / (ghosts[i].vx - ghosts[j].vx);
                if (t >= 0 && fabs(ghosts[i].x + ghosts[i].vx * t - ghosts[j].x - ghosts[j].vx * t) <= 1e-9) {
                    int y1 = a * ghosts[i].x + b;
                    int y2 = a * ghosts[j].x + b;
                    if (y1 == a * (ghosts[i].x + ghosts[i].vx * t) + b && y2 == a * (ghosts[j].x + ghosts[j].vx * t) + b) {
                        experience += 2;
                    }
                }
            }
        }
    }

    cout << experience << endl;

    return 0;
}