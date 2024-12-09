#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct Line {
    int a, b, c, h, r;
};

struct State {
    int station, time, cost, bitmask;
};

int main() {
    int N, M, H, K;

    while (cin >> N >> M >> H >> K) {
        if (N == 0 && M == 0 && H == 0 && K == 0) break;

        vector<vector<Line>> lines(N);

        for (int i = 0; i < M; i++) {
            Line line;
            cin >> line.a >> line.b >> line.c >> line.h >> line.r;
            line.a--;
            line.b--;
            lines[line.a].push_back(line);
            swap(line.a, line.b);
            lines[line.a].push_back(line);
        }

        int S, T;
        cin >> S >> T;
        S--;
        T--;

        int P;
        cin >> P;

        vector<vector<int>> passport_cost(P);
        vector<vector<int>> passport_companies(P);

        for (int i = 0; i < P; i++) {
            int l, d;
            cin >> l >> d;
            passport_cost[i] = vector<int>(l);
            passport_companies[i] = vector<int>(l);

            for (int j = 0; j < l; j++) {
                cin >> passport_companies[i][j];
                passport_companies[i][j]--;
            }
            for (int j = 0; j < l; j++) {
                passport_cost[i] = d;
            }
        }

        vector<vector<vector<int>>> dp(N, vector<vector<int>>(H + 1, vector<int>(1 << K, INF));

        priority_queue<State, vector<State>, greater<State>> pq;
        pq.push({S, 0, 0, 0});
        dp[S][0][0] = 0;

        while (!pq.empty()) {
            State state = pq.top();
            pq.pop();
            int station = state.station;
            int time = state.time;
            int cost = state.cost;
            int bitmask = state.bitmask;

            if (time > H) continue;
            if (station == T) {
                cout << cost << endl;
                break;
            }

            if (dp[station][time][bitmask] < cost) continue;

            for (Line line : lines[station]) {
                if (time + line.h > H) continue;
                int new_time = time + line.h;
                int new_cost = cost + line.c;
                int new_bitmask = bitmask | (1 << (line.r - 1));

                if (dp[line.b][new_time][new_bitmask] > new_cost) {
                    dp[line.b][new_time][new_bitmask] = new_cost;
                    pq.push({line.b, new_time, new_cost, new_bitmask});
                }
            }

            for (int i = 0; i < P; i++) {
                int new_cost = cost + passport_cost[i];
                int new_bitmask = bitmask;
                for (int company : passport_companies[i]) {
                    new_bitmask |= (1 << company);
                }
                if (dp[station][time][new_bitmask] > new_cost) {
                    dp[station][time][new_bitmask] = new_cost;
                    pq.push({station, time, new_cost, new_bitmask});
                }
            }
        }

        if (dp[T][H][0] == INF) {
            cout << -1 << endl;
        }
    }

    return 0;
}