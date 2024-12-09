#include <iostream>
#include <vector>

using namespace std;

int main() {
    int q;
    cin >> q;

    vector<int> a(500001, 0); // Initialize array with 500001 elements all set to 0

    for (int i = 0; i < q; i++) {
        int t, x, y;
        cin >> t >> x >> y;

        if (t == 1) {
            a[x] += y;
        } else {
            int sum = 0;
            for (int j = y; j <= 500000; j += x) {
                sum += a[j];
            }
            cout << sum << endl;
        }
    }

    return 0;
}