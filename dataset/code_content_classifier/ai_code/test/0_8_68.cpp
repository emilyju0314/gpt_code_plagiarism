#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Bubble {
    int x, y, index;
};

int main() {
    int N;
    cin >> N;

    vector<Bubble> bubbles(N);
    for (int i = 0; i < N; i++) {
        cin >> bubbles[i].x >> bubbles[i].y;
        bubbles[i].index = i + 1;
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int dx, dy, K;
        cin >> dx >> dy >> K;

        vector<pair<double, Bubble>> angles;
        for (int j = 0; j < N; j++) {
            double angle = atan2(bubbles[j].y - dy, bubbles[j].x - dx);
            angles.push_back({angle, bubbles[j]});
        }

        sort(angles.begin(), angles.end());

        cout << angles[K - 1].second.index << endl;
    }

    return 0;
}