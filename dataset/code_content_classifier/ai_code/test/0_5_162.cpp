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
        vector<long long> heaps(n);

        for (int i = 0; i < n; i++) {
            cin >> heaps[i];
        }

        long long small_heap = *min_element(heaps.begin(), heaps.end());
        long long sum = 0;

        for (int i = 0; i < n - 2; i++) {
            sum += heaps[i];
        }

        long long extra_needed = max(0LL, (sum - small_heap) / 2 + 1);

        cout << max(small_heap, sum - extra_needed) << endl;
    }

    return 0;
}