#include <iostream>
#include <vector>
#include <unordered_set>

#define MOD 1000000007

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    for(int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    unordered_set<int> xSet, ySet;
    for(auto p : points) {
        xSet.insert(p.first);
        ySet.insert(p.second);
    }

    long long ans = 1;
    ans *= (1LL << xSet.size()) % MOD;
    ans *= (1LL << ySet.size()) % MOD;

    cout << ans % MOD << endl;

    return 0;
}