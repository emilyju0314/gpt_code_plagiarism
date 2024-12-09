#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Bubble {
    int x, y, idx;
};

double polarAngle(int dx, int dy, int x, int y) {
    return atan2(y, x) - atan2(dy, dx);
}

int main() {
    int N, Q;
    cin >> N;

    vector<Bubble> bubbles(N);
    for (int i = 0; i < N; i++) {
        cin >> bubbles[i].x >> bubbles[i].y;
        bubbles[i].idx = i + 1;
    }

    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int dx, dy, K;
        cin >> dx >> dy >> K;

        sort(bubbles.begin(), bubbles.end(), [&](const Bubble &a, const Bubble &b) {
            return polarAngle(dx, dy, a.x, a.y) < polarAngle(dx, dy, b.x, b.y);
        });

        int lastPoppedIdx;
        for (int j = 0; j < K; j++) {
            lastPoppedIdx = bubbles[j].idx;
        }

        cout << lastPoppedIdx << endl;
    }

    return 0;
}