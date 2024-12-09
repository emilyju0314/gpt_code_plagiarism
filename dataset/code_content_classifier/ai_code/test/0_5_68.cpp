#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Bubble {
    int id, x, y;
};

int main() {
    int N;
    cin >> N;

    vector<Bubble> bubbles(N);
    for (int i = 0; i < N; i++) {
        bubbles[i].id = i + 1;
        cin >> bubbles[i].x >> bubbles[i].y;
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int dx, dy, K;
        cin >> dx >> dy >> K;

        int last_popped = 0;
        for (int j = 1; j < K; j++) {
            long long min_dist = LLONG_MAX;
            int min_index = -1;

            for (int k = 0; k < N; k++) {
                long long dist = (long long)dx * (bubbles[k].x - bubbles[last_popped].x) + (long long)dy * (bubbles[last_popped].y - bubbles[k].y);
                if (dist > 0 && dist < min_dist) {
                    min_dist = dist;
                    min_index = k;
                }
            }

            last_popped = min_index;
        }

        cout << bubbles[last_popped].id << endl;
    }

    return 0;
}