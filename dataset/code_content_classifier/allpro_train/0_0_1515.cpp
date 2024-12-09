#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> positions(k);
    vector<long long> values(k);

    for(int i = 0; i < k; i++) {
        int x, y;
        long long w;
        cin >> x >> y >> w;
        positions[i] = {x, y};
        values[i] = w;
    }

    long long ans = 1;
    for(int i = 0; i < k; i++) {
        ans = (ans * values[i]) % MOD;
    }

    cout << ans << endl;

    return 0;
}