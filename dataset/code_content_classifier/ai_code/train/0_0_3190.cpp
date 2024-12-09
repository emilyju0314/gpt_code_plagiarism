#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, K, A, B, C, T;
    vector<int> express_stops;

    cin >> N >> M >> K;
    cin >> A >> B >> C;
    cin >> T;

    for (int i = 0; i < M; i++) {
        int stop;
        cin >> stop;
        express_stops.push_back(stop);
    }

    int max_stations = 0;

    for (int i = 1; i <= K - M + 1; i++) {
        for (int j = 1; j <= K - M + 1; j++) {
            vector<int> semiexpress_stops;
            int cnt = 0;

            for (int k = 0; k < i; k++) {
                semiexpress_stops.push_back(express_stops[k]);
            }

            for (int k = i; k < i + j; k++) {
                semiexpress_stops.push_back(express_stops[M - 1] - k + i + 1);
            }

            for (int k = i + j; k < i + j + M; k++) {
                semiexpress_stops.push_back(express_stops[M - 1] - j + 1);
                cnt++;
            }

            if (cnt >= K) {
                continue;
            }

            sort(semiexpress_stops.begin(), semiexpress_stops.end());

            auto it = lower_bound(semiexpress_stops.begin(), semiexpress_stops.end(), express_stops[M - 1] + 1);

            int time = 0;

            if (it == semiexpress_stops.end()) {
                time += C * (N - 1 - express_stops[M - 1]);
            } else {
                time += C * (*it - express_stops[M - 1] - 1);
            }

            if (time > T) {
                continue;
            }

            for (int k = 1; k < semiexpress_stops[0]; k++) {
                time += A;
                if (time > T) {
                    continue;
                }
            }

            for (int k = 0; k < semiexpress_stops.size() - 1; k++) {
                int diff = semiexpress_stops[k + 1] - semiexpress_stops[k] - 1;
                time += min(B * diff, C * diff);
                if (time > T) {
                    continue;
                }
            }

            max_stations = max(max_stations, semiexpress_stops[semiexpress_stops.size() - 1]);
        }
    }

    cout << max_stations - 1 << endl;

    return 0;
}