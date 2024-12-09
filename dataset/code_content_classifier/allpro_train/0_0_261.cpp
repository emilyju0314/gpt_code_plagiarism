#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXN 105
#define MAXS 100010

int n, m, s, b, k;
vector<int> adj[MAXN];
int dp[MAXS];
vector<pair<int, int>> spaceships;
vector<pair<int, int>> bases;
vector<int> dependencies[MAXS];

int solve(int bitmask) {
    if (dp[bitmask] != -1) return dp[bitmask];

    int profit = 0;
    for (int i = 0; i < s; i++) {
        if (bitmask & (1 << i)) {
            bool canOperate = true;
            for (int dep : dependencies[i]) {
                if (!(bitmask & (1 << dep))) {
                    canOperate = false;
                    break;
                }
            }
            if (canOperate) {
                int maxProfit = 0;
                int baseIdx = -1;
                for (int j = 0; j < b; j++) {
                    int dist = abs(spaceships[i].first - bases[j].first);
                    if (dist == 0) continue;
                    if (dist <= spaceships[i].third) {
                        if (spaceships[i].second >= bases[j].second) {
                            int currProfit = bases[j].third - spaceships[i].fourth;
                            if (currProfit > maxProfit) {
                                maxProfit = currProfit;
                                baseIdx = j;
                            }
                        }
                    }
                }
                if (baseIdx != -1) {
                    profit = max(profit, maxProfit + solve(bitmask ^ (1 << i)));
                }
            }
        }
    }

    return dp[bitmask] = profit;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin >> s >> b >> k;

    memset(dp, -1, sizeof(dp));
    
    for (int i = 0; i < s; i++) {
        int x, a, f, p;
        cin >> x >> a >> f >> p;
        spaceships.push_back({x, a, f, p});
    }

    for (int i = 0; i < b; i++) {
        int x, d, g;
        cin >> x >> d >> g;
        bases.push_back({x, d, g});
    }

    for (int i = 0; i < k; i++) {
        int s1, s2;
        cin >> s1 >> s2;
        dependencies[s1-1].push_back(s2-1);
    }

    int ans = solve((1 << s) - 1);
    cout << ans << endl;

    return 0;
}