#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> report(n);
    for (int i = 0; i < n; i++) {
        cin >> report[i];
    }

    int t, r;
    for (int i = 0; i < m; i++) {
        cin >> t >> r;
        if (t == 1) {
            sort(report.begin(), report.begin() + r);
        } else {
            sort(report.begin(), report.begin() + r, greater<int>());
        }
    }

    for (int num : report) {
        cout << num << " ";
    }

    return 0;
}