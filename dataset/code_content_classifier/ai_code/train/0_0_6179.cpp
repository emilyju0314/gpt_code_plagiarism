#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;

    sort(a.begin(), a.end());

    int profit = 0;
    for (int i = 0; i < min(m, n); i++) {
        profit += a[i];
    }

    if (m > n) {
        profit -= d * (m - n);
    }

    cout << profit << endl;

    return 0;
}