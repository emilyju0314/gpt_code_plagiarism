#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int n, T;
vector<pair<int, int>> songs;
long long dp[16][1 << 15][4];

long long solve(int idx, int mask, int last_genre) {
    if(idx == n) {
        if(T == 0 && last_genre == 0) return 1;
        return 0;
    }
    if(dp[idx][mask][last_genre] != -1) return dp[idx][mask][last_genre];

    long long ans = 0;
    for(int i = 0; i < n; i++) {
        if(!(mask & (1 << i))) {
            if(last_genre == 0 || songs[i].second != last_genre) {
                if(T - songs[i].first >= 0) {
                    ans += solve(idx + 1, mask | (1 << i), songs[i].second);
                    ans %= MOD;
                }
            }
        }
    }

    return dp[idx][mask][last_genre] = ans;
}

int main() {
    cin >> n >> T;

    songs.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> songs[i].first >> songs[i].second;
    }

    memset(dp, -1, sizeof(dp));
    long long answer = solve(0, 0, 0);

    cout << answer << endl;

    return 0;
}