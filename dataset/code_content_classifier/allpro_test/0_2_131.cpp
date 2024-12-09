#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int x = 0, y = 1, m = a[y] - a[x];
    int min_diff = abs(a[y] - a[x]);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int k = int(log2(a[j] - a[i])) + 1;
            int exchanges = a[i] ^ ((1 << k) - 1);
            if (exchanges >= a[j]) {
                if (a[j] + exchanges < min_diff) {
                    min_diff = a[j] + exchanges;
                    x = i;
                    y = j;
                    m = exchanges;
                }
            }
        }
    }

    cout << x + 1 << " " << y + 1 << " " << m << endl;

    return 0;
}