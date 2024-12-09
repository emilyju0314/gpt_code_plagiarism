#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> bubbles(N);
    for (int i = 0; i < N; i++) {
        cin >> bubbles[i].first >> bubbles[i].second;
    }

    int Q;
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int dx, dy, K;
        cin >> dx >> dy >> K;

        vector<pair<long long, int>> distances; // store {squared_distance, index} pairs

        for (int i = 0; i < N; i++) {
            long long sq_dist = (long long)(bubbles[i].first - dx) * (bubbles[i].first - dx) + (long long)(bubbles[i].second - dy) * (bubbles[i].second - dy);
            distances.push_back({sq_dist, i + 1});
        }

        sort(distances.begin(), distances.end());

        cout << distances[K - 1].second << endl;
    }

    return 0;
}