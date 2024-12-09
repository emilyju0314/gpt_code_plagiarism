#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> beavers(n);
    for (int i = 0; i < n; i++) {
        cin >> beavers[i];
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int p, x, y;
        cin >> p >> x >> y;

        if (p == 1) {
            int min_sessions = 1;
            for (int j = x; j < y; j++) {
                if (beavers[j] > beavers[j+1]) {
                    min_sessions++;
                }
            }
            cout << min_sessions << endl;
        } else if (p == 2) {
            swap(beavers[x-1], beavers[y-1]);
        }
    }

    return 0;
}