#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Pigeon {
public:
    int s, t, a, b, d;
    Pigeon(int st, int tt, int at, int bt, int dt) : s(st), t(tt), a(at), b(bt), d(dt) {}
};

int main() {
    int N, M, s, t, f;
    cin >> N >> M >> s >> t >> f;

    vector<Pigeon> pigeons;
    for(int i = 0; i < M; i++) {
        int si, ti, ai, bi, di;
        cin >> si >> ti >> ai >> bi >> di;
        pigeons.push_back(Pigeon(si, ti, ai, bi, di));
    }

    vector<vector<int>> dp(f+1, vector<int>(N, INT_MAX));
    dp[0][s] = 0;

    for(int u = 1; u <= f; u++) {
        for(int i = 0; i < M; i++) {
            int si = pigeons[i].s, ti = pigeons[i].t, ai = pigeons[i].a, bi = pigeons[i].b, di = pigeons[i].d;
            for(int v = 0; v < N; v++) {
                if(dp[u-di][v] != INT_MAX) {
                    int cost = dp[u-di][v] + ((u <= di) ? u * ai : di * ai + (u - di) * bi);
                    if(v == si) dp[u][ti] = min(dp[u][ti], cost);
                }
            }
        }
    }

    if(dp[f][t] == INT_MAX) {
        cout << "Impossible" << endl;
    } else {
        cout << dp[f][t] << endl;
    }

    return 0;
}