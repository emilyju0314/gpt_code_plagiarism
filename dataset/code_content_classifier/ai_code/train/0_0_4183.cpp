#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> friends(n);
    unordered_map<int, unordered_map<int, int>> cnt;

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        friends[a]++;
        friends[b]++;
        cnt[a][b]++;
        cnt[b][a]++;
    }

    long long ans = 0;

    for(int i = 0; i < n; i++) {
        ans += (long long)(friends[i] * (friends[i] - 1)) / 2;

        for(auto &[a, v] : cnt[i]) {
            ans -= (long long)(friends[i] - 1) * (friends[a] - 1);

            for(int b = 1; b <= friends[a]; b++) {
                cnt[i][b] = 0;
            }
        }
    }

    cout << ans << endl;

    return 0;
}