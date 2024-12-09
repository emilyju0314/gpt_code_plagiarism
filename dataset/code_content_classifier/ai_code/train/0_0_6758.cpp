#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < k; i++) {
        int minNonZero = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (a[j] != 0) {
                minNonZero = min(minNonZero, a[j]);
            }
        }

        if (minNonZero == 0) {
            cout << 0 << endl;
            continue;
        }

        cout << minNonZero << endl;
        
        for (int j = 0; j < n; j++) {
            if (a[j] != 0) {
                a[j] -= minNonZero;
            }
        }
    }

    return 0;
}