#include <iostream>
#include <vector>
#include <unordered_map>

#define MOD 998244353

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<pair<int, int>> initialFires(n);
    unordered_map<long long, int> fireTimes;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        initialFires[i] = make_pair(x, y);
        fireTimes[(long long)x * 2e9 + y] = 1;
    }

    for (int time = 1; time <= t; time++) {
        unordered_map<long long, int> newFireTimes;
        for (auto& fire : fireTimes) {
            int x = fire.first / 2e9;
            int y = fire.first % (long long)2e9;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) continue;
                    long long newKey = ((long long)x + dx) * 2e9 + y + dy;
                    newFireTimes[newKey] += fire.second;
                    newFireTimes[newKey] %= MOD;
                }
            }
        }
        fireTimes = newFireTimes;
    }

    int totalDestructivePower = 0;
    for (auto& fire : fireTimes) {
        totalDestructivePower += fire.second;
        totalDestructivePower %= MOD;
    }

    cout << totalDestructivePower << endl;

    return 0;
}