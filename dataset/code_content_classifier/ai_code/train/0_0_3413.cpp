#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    long long ans = 0;
    for (int i = 0; i < m - 1; i++) {
        ans += abs(a[i] - a[i+1]);
    }

    sort(a.begin(), a.end());
    long long minTurn = abs(a[0] - a[m-1]);

    for (int i = 0; i < m - 1; i++) {
        minTurn = min(minTurn, abs(a[i] - a[i+1]));
    }

    cout << ans - minTurn << endl;

    return 0;
}