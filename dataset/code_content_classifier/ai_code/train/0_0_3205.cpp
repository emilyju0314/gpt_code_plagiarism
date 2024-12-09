#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> start(m), end(m);
    for(int i = 0; i < m; i++) {
        cin >> start[i] >> end[i];
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    long long ans = 1;
    for(int i = 0; i < m; i++) {
        ans = (ans * (end[i] - start[i])) % MOD;
    }

    cout << ans << endl;

    return 0;
}