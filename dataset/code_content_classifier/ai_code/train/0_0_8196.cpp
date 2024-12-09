#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cmath>
#include <bitset>

#define MOD 1000000007

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    unordered_set<int> x_set, y_set;
    for(auto p : points) {
        x_set.insert(p.first);
        y_set.insert(p.second);
    }

    long long ans = 1;
    ans *= (1 << x_set.size());
    ans %= MOD;
    ans *= (1 << y_set.size());
    ans %= MOD;
    
    cout << ans << endl;

    return 0;
}