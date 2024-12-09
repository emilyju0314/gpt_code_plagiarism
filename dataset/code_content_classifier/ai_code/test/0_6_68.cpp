#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> bubbles(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        bubbles[i] = make_pair(x, y);
    }

    int Q;
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int dx, dy, K;
        cin >> dx >> dy >> K;

        int last_bubble_index = 0;
        long long last_distance = LLONG_MAX;

        for (int i = 0; i < N; i++) {
            long long x = bubbles[i].first;
            long long y = bubbles[i].second;
            long long distance = abs((long long)dx*x + (long long)dy*y);

            if (distance < last_distance) {
                last_bubble_index = i + 1;
                last_distance = distance;
            }
        }

        cout << last_bubble_index << "\n";
    }

    return 0;
}