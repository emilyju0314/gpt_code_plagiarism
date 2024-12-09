#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> instructions(N);
    for (int i = 0; i < N; i++) {
        cin >> instructions[i];
    }

    vector<int> dist(N, INT_MAX);
    queue<int> q;
    q.push(0);
    dist[0] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int i = 1; i <= 6; i++) {
            int next = current + i;
            if (next >= N) {
                next = N - 1;
            }
            next += instructions[next];
            if (dist[next] > dist[current] + 1) {
                dist[next] = dist[current] + 1;
                q.push(next);
            }
        }
    }

    cout << dist[N-1] << endl;

    return 0;
}