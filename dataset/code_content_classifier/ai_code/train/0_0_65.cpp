#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> students(N);
    vector<pair<int, int>> checkpoints(M);

    for (int i = 0; i < N; i++) {
        cin >> students[i].first >> students[i].second;
    }

    for (int i = 0; i < M; i++) {
        cin >> checkpoints[i].first >> checkpoints[i].second;
    }

    for (int i = 0; i < N; i++) {
        int min_distance = INT_MAX;
        int closest_checkpoint = 0;

        for (int j = 0; j < M; j++) {
            int distance = abs(students[i].first - checkpoints[j].first) + abs(students[i].second - checkpoints[j].second);
            if (distance < min_distance) {
                min_distance = distance;
                closest_checkpoint = j + 1;
            }
        }

        cout << closest_checkpoint << endl;
    }

    return 0;
}