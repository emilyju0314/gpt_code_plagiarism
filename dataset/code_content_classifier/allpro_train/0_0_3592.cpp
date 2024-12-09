#include <iostream>
#include <deque>
#include <algorithm>

#define MOD 1000000009

using namespace std;

int main() {
    int m;
    cin >> m;

    deque<pair<long long, long long>> cubes;
    for (int i = 0; i < m; i++) {
        long long x, y;
        cin >> x >> y;
        cubes.push_back({x, y});
    }

    sort(cubes.begin(), cubes.end());

    long long ans = 0;
    for (int i = 0; i < m; i++) {
        if (i % 2 == 0) {
            ans = (ans * m + cubes.back().first) % MOD;
            cubes.pop_back();
        } else {
            ans = (ans * m + cubes.front().first) % MOD;
            cubes.pop_front();
        }
    }

    cout << ans << endl;

    return 0;
}