#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_N = 40;
const int MAX_M = 10;
const int INF = 1e9;

int n, m, b;
int p[MAX_M];
int dp[1 << MAX_N][MAX_M];
vector<pair<int, int>> child[MAX_N];

int solve(int mask, int lastMachine) {
    if (mask == (1 << n) - 1) return 0; // All children have played

    if (dp[mask][lastMachine] != -1) {
        return dp[mask][lastMachine];
    }

    int res = INF;
    for (int i = 0; i < n; i++) {
        if (!(mask & (1 << i))) {
            int newMask = mask | (1 << i);
            int lastTime = 0;
            int total = 0;

            for (const auto& play : child[i]) {
                int machine = play.first, time = play.second;

                if (machine == lastMachine) {
                    total += time;
                } else {
                    int cost = (machine == lastMachine) ? 0 : p[machine - 1];
                    if (cost <= b) {
                        total += time;
                        b -= cost;
                        lastMachine = machine;
                    } else {
                        break;
                    }
                }
                res = min(res, max(total, solve(newMask, lastMachine)));
            }
        }
    }

    return dp[mask][lastMachine] = res;
}

int main() {
    cin >> n >> m >> b;
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        for (int j = 0; j < k; j++) {
            int machine, time;
            cin >> machine >> time;
            child[i].push_back({machine, time});
        }
    }

    memset(dp, -1, sizeof(dp));
    int minTime = solve(0, 0);
    cout << minTime << '\n';

    string usedMachines = string(m, '0');
    int mask = 0;
    int lastMachine = 0;

    for (int i = 0; i < n; i++) {
        if (dp[mask][lastMachine] == minTime) {
            for (const auto& play : child[i]) {
                int machine = play.first;
                usedMachines[machine - 1] = '1';
                cout << i + 1 << ' ' << machine << " " << dp[mask][lastMachine] - play.second << " " << play.second << '\n';
            }
            
            mask |= (1 << i);
        }
    }

    cout << usedMachines << '\n';
    cout << minTime << '\n';

    return 0;
}