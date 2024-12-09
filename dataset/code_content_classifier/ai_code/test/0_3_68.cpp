#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Bubble {
    int x, y, idx;
};

bool cmp(Bubble a, Bubble b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

int main() {
    int N;
    cin >> N;

    vector<Bubble> bubbles(N);
    for (int i = 0; i < N; i++) {
        cin >> bubbles[i].x >> bubbles[i].y;
        bubbles[i].idx = i + 1;
    }

    sort(bubbles.begin(), bubbles.end(), cmp);

    int Q;
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int dx, dy, K;
        cin >> dx >> dy >> K;

        long long start_x = 0, start_y = 0;

        for (int i = 1; i < N; i++) {
            long long x_diff = bubbles[i].x - start_x;
            long long y_diff = bubbles[i].y - start_y;
            long long det = x_diff * dy - y_diff * dx;

            if (det > 0) {
                start_x = bubbles[i].x;
                start_y = bubbles[i].y;
                K--;
                if (K == 0) {
                    cout << bubbles[i].idx << endl;
                    break;
                }
            }
        }
    }

    return 0;
}