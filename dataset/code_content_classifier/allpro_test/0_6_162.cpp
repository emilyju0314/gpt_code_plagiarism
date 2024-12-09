#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> h(n);
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }

        long long sum = h[n-1];
        long long min_heap = h[n-1];

        for (int i = n-2; i >= 2; i--) {
            sum += h[i];
            min_heap = min(min_heap, (sum + 2) / 3);
        }

        cout << min(min(h[0], h[1]), min_heap) << endl;
    }

    return 0;
}