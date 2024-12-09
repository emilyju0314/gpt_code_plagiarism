#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int q;
    cin >> q;

    while (q--) {
        int n, r;
        cin >> n >> r;

        vector<int> x(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }

        sort(x.begin(), x.end());

        int shots = 0;
        int prev = -1;

        for (int i = n - 1; i >= 0; i--) {
            if (x[i] - r > prev) {
                shots++;
                prev = x[i];
            }

            while (i >= 0 && x[i] <= prev) {
                i--;
            }
        }

        cout << shots << endl;
    }

    return 0;
}