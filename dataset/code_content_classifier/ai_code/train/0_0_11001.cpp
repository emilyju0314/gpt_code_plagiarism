#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, l;
    cin >> n >> m >> l;

    vector<int> hairlines(n);
    for (int i = 0; i < n; i++) {
        cin >> hairlines[i];
    }

    int numSegments = 0;
    for (int i = 0; i < n; i++) {
        if (hairlines[i] > l && (i == 0 || hairlines[i-1] <= l)) {
            numSegments++;
        }
    }

    while (m--) {
        int query;
        cin >> query;

        if (query == 0) {
            cout << numSegments << "\n";
        } else {
            int p, d;
            cin >> p >> d;
            p--;

            hairlines[p] += d;

            if (hairlines[p] > l) {
                if ((p == 0 || hairlines[p-1] <= l) && (p == n - 1 || hairlines[p+1] <= l)) {
                    numSegments++;
                } else if ((p > 0 && hairlines[p-1] > l) && (p < n - 1 && hairlines[p+1] > l)) {
                    numSegments--;
                }
            }

            hairlines[p] = min(hairlines[p], l);
        }
    }

    return 0;
}