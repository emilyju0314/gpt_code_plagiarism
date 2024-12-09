#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Clerk {
    int x, y;
    bool repeated = false;
};

double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    int datasets;
    cin >> datasets;

    for (int d = 0; d < datasets; d++) {
        int N, X, Y;
        cin >> N >> X >> Y;

        int natsumeX, natsumeY;
        cin >> natsumeX >> natsumeY;

        vector<Clerk> clerks(N);
        for (int i = 0; i < N; i++) {
            cin >> clerks[i].x >> clerks[i].y;
        }

        int time = 0;
        bool quiet = false;

        while (!quiet) {
            quiet = true;
            for (int i = 0; i < N; i++) {
                double dist = distance(natsumeX, natsumeY, clerks[i].x, clerks[i].y);
                if (dist <= 10) {
                    cout << "Welcome Hello\n";
                    time += X;
                    clerks[i].repeated = false;
                    quiet = false;
                } else {
                    for (int j = 0; j < N; j++) {
                        if (i == j) continue;
                        double dist2 = distance(clerks[i].x, clerks[i].y, clerks[j].x, clerks[j].y);
                        if (dist2 <= 50 && clerks[j].repeated) {
                            cout << "Welcome Hello\n";
                            time += X;
                            clerks[i].repeated = true;
                            quiet = false;
                        }
                    }
                }
            }
            if (time > Y) {
                cout << "You're always welcome!\n";
                break;
            }
        }

        if (quiet) {
            cout << time << "\n";
        }
    }

    return 0;
}