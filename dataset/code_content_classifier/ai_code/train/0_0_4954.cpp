#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> l(n), r(n), a(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i] >> a[i];
    }

    long long bullets = 0;
    long long magazine = k;

    for (int i = 0; i < n; i++) {
        if (magazine < a[i]) {
            long long reloads_needed = (a[i] - magazine + k - 1) / k;
            bullets += reloads_needed * (l[i] - 1);
            magazine += reloads_needed * k;
            if (magazine < a[i]) {
                cout << -1 << endl;
                return 0;
            }
        }
        magazine -= a[i];
        if (i < n - 1) {
            bullets += a[i];
        }
    }

    cout << bullets << endl;

    return 0;
}