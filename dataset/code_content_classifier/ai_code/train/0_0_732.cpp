#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, bool>> relations[n+1];
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        relations[a].push_back({b, c});
        relations[b].push_back({a, c});
    }

    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        int num_love = 0, num_hate = 0;
        for (auto r : relations[i]) {
            if (r.second) {
                num_love++;
            } else {
                num_hate++;
            }
        }

        if (num_love > 0 && (num_love + num_hate) != n - 1) {
            ans = 0;
            break;
        }

        for (int j = 0; j < num_hate; j++) {
            ans = (ans * 2) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}