#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> dist(N, vector<int>(N, INF));
    for (int i = 0; i < N; i++) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        dist[a][b] = dist[b][a] = c;
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (dist[i][j] == INF) {
                continue;
            }
            bool isValid = true;
            for (int k = 0; k < N; k++) {
                if (k != i && k != j && dist[i][j] == dist[i][k] + dist[k][j]) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}