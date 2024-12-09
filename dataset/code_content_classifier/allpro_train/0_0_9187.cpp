#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> b(n);
    vector<int> g(m);

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> g[i];
    }

    int minTotalSweets = 0;

    sort(b.begin(), b.end());
    sort(g.begin(), g.end());

    if (b[n-1] > g[0]) {
        cout << "-1" << endl;
        return 0;
    }

    for (int i = 0; i < n - 1; i++) {
        minTotalSweets += g[m-1];
        minTotalSweets += b[i] * m;
    }

    minTotalSweets += b[n-1];

    cout << minTotalSweets << endl;

    return 0;
}