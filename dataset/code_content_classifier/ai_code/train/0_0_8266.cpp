#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<long long> a(m), b(n);
    for(int i = 0; i < m; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long total = 0;
    for(int i = 0; i < m; i++) {
        total += b[0] * a[i];
    }

    cout << total << endl;

    return 0;
}