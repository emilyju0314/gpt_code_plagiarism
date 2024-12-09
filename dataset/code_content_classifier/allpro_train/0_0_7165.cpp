#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> start(N), end(N), block(N);
    for (int i = 0; i < N; i++) {
        cin >> start[i] >> end[i] >> block[i];
    }

    vector<int> times(Q);
    for (int i = 0; i < Q; i++) {
        cin >> times[i];
    }

    vector<int> result(Q, -1);

    int current_pos = 0;
    for (int i = 0; i < Q; i++) {
        int walk_distance = 0;
        bool blocked = false;
        for (int j = 0; j < N; j++) {
            if (times[i] >= start[j] - 0.5 && times[i] < end[j] - 0.5 && current_pos < block[j]) {
                walk_distance += block[j] - current_pos;
                result[i] = walk_distance;
                blocked = true;
                break;
            } else if (times[i] >= start[j] - 0.5 && times[i] < end[j] - 0.5) {
                blocked = true;
                break;
            } else if (times[i] >= end[j] - 0.5) {
                current_pos = max(current_pos, block[j]);
            }
        }
        if (!blocked) {
            walk_distance += 1000000000 - current_pos;
            result[i] = walk_distance;
        }
    }

    for (int i = 0; i < Q; i++) {
        cout << result[i] << endl;
    }

    return 0;
}