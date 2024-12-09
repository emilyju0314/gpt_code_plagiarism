#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long long t;
    cin >> n >> t;

    vector<long long> a(n);
    vector<long long> x(n);
    vector<long long> b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> x[i];
        x[i]--;
    }

    for (int i = 0; i < n; i++) {
        long long diff = max(a[i] + t, b[x[i]]);
        if (i > 0) {
            diff = max(diff, b[x[i - 1]] + t);
        }
        b[x[i]] = diff;
    }

    for (int i = 0; i < n; i++) {
        if (b[x[i]] < a[i] + t) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    for (int i = 0; i < n; i++) {
        cout << b[x[i]] << " ";
    }
    cout << endl;

    return 0;
}