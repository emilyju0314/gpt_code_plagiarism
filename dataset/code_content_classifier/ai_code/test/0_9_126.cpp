#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<pair<int, int>> reqs(m);
    for (int i = 0; i < m; i++) {
        cin >> reqs[i].first >> reqs[i].second;
    }

    vector<long long> b(n, 1e18);
    for (int i = 0; i < m; i++) {
        b[reqs[i].first - 1] = min(b[reqs[i].first - 1], a[reqs[i].second - 1]);
        b[reqs[i].second - 1] = min(b[reqs[i].second - 1], a[reqs[i].second - 1]);
    }

    for (int i = 0; i < m; i++) {
        if (a[reqs[i].first - 1] > b[reqs[i].first - 1]) {
            b[reqs[i].first - 1] = a[reqs[i].first - 1];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }

    return 0;
}