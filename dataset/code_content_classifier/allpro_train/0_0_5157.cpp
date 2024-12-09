#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Sensor {
    int x, y;
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<Sensor> sensors(k);
    for(int i = 0; i < k; i++) {
        cin >> sensors[i].x >> sensors[i].y;
    }

    vector<int> times(k, -1);

    for(auto sensor : sensors) {
        int x = sensor.x, y = sensor.y;
        int dx = x, dy = y;
        int t = 0;

        if (x == 1) {
            t += y;
        }
        else if (y == 1) {
            t += x;
        }
        else {
            if (x % 2 == 0) {
                t += x;
                dx = n - x;
            }
            else {
                t += x - 1;
                dx = x - 1;
            }

            if (y % 2 == 0) {
                t += (y - 1) * (n + 1);
                dy = m - y;
            }
            else {
                t += (y - 1) * (n + 1) + n;
                dy = y - 1;
            }

            if (dx == 0) {
                t += dy;
            }
            else if (dy == 0) {
                t += dx;
            }
            else {
                int numDiags = min(dx, dy);
                t += numDiags * (n + m - 1);
                dx -= numDiags;
                dy -= numDiags;

                if (dx == 0) {
                    t += dy;
                }
                else {
                    t += dx;
                }
            }
        }

        times.push_back(t);
    }

    for(auto time : times) {
        cout << time << endl;
    }

    return 0;
}