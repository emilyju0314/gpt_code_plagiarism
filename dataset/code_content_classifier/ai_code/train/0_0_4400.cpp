#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> ninjas;
    for (int i = 0; i < N; i++) {
        int x, v;
        cin >> x >> v;
        ninjas.push_back({x, v});
    }

    sort(ninjas.begin(), ninjas.end());

    long long ans = 1;
    for (int i = 0; i < N; i++) {
        ans = (ans * (i + 1)) % MOD;
        while (i + 1 < N && 1LL * (ninjas[i + 1].first - ninjas[i].first) * ninjas[i].second <= 1LL * (ninjas[i].first - ninjas[i + 1].first) * ninjas[i + 1].second) {
            i++;
        }
    }

    cout << ans << endl;

    return 0;
}