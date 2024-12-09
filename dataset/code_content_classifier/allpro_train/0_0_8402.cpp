#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<int> d(N);
    for (int i = 0; i < N; i++) {
        cin >> d[i];
    }

    vector<int> b(M), t(M);
    vector<char> c(M);
    for (int i = 0; i < M; i++) {
        cin >> c[i] >> b[i] >> t[i];
    }

    vector<int> total_distance(N);
    for (int i = 0; i < N; i++) {
        int dist = 0, curr = i;
        while (true) {
            dist += d[curr];
            if (c[b[curr] - 1] == 'R') {
                curr = (curr + 1) % N;
            } else {
                curr = (curr - 1 + N) % N;
            }
            total_distance[i] = dist;
            if (curr == i) break;
        }
    }

    for (int i = 0; i < Q; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;

        int min_time = abs(total_distance[y] - total_distance[x]);
        min_time = min(min_time, total_distance[N - 1] - min_time);
        
        cout << min_time << endl;
    }

    return 0;
}