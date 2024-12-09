#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, p, q;
    cin >> n >> p >> q;

    vector<pair<int, int>> projects(n);
    for (int i = 0; i < n; i++) {
        cin >> projects[i].first >> projects[i].second;
    }

    double minDays = 1e9;
    for (int i = 0; i < n; i++) {
        double days = (double)(p) / (double)(projects[i].first);
        days = min(days, (double)(q) / (double)(projects[i].second));
        minDays = min(minDays, days);
    }

    cout << fixed;
    cout.precision(15);
    cout << minDays << endl;

    return 0;
}