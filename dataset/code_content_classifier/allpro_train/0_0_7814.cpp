#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int cur = 0; // current index
    vector<int> p(n-1, 0);

    for (int i = 1; i < n; i++) {
        cout << "? 0 1" << endl;
        cout.flush();
        int a;
        cin >> a;
        if (a == m) {
            p[i-1] = 1;
            continue;
        }

        int lo = 0, hi = m-1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            cout << "? " << cur << " 1" << endl;
            cout.flush();
            int b;
            cin >> b;
            if (b >= a) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        p[i-1] = lo;

        cout << "? " << cur << " -1" << endl;
        cout.flush();
        int c;
        cin >> c;

        a = c;
        cur = i;
    }

    cout << "! ";
    for (int i = 0; i < n-1; i++) {
        cout << p[i] << " ";
    }
    cout << endl;

    return 0;
}