#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Bubble {
    int x, y, index;
};

bool compareBubble(const Bubble& b1, const Bubble& b2) {
    if(b1.x == b2.x) {
        return b1.y < b2.y;
    }
    return b1.x < b2.x;
}

int main() {
    int N;
    cin >> N;

    vector<Bubble> bubbles(N);
    for(int i = 0; i < N; i++) {
        cin >> bubbles[i].x >> bubbles[i].y;
        bubbles[i].index = i + 1;
    }

    sort(bubbles.begin(), bubbles.end(), compareBubble);

    int Q;
    cin >> Q;

    for(int q = 0; q < Q; q++) {
        int dx, dy, K;
        cin >> dx >> dy >> K;

        int lastPopIndex = -1;
        double maxAngle = -1;

        for(int i = 0; i < N; i++) {
            double angle = atan2(bubbles[i].y - dy, bubbles[i].x - dx);
            if(angle < 0) {
                angle += 2 * M_PI;
            }

            if(angle > maxAngle) {
                maxAngle = angle;
                lastPopIndex = i;
            }
        }

        cout << bubbles[lastPopIndex].index << endl;
    }

    return 0;
}