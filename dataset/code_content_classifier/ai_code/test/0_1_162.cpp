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

        int smallest_heap = min(heaps[0], min(heaps[1], heaps[2]));
        long long extra = max(0LL, heaps[0] - smallest_heap) + max(0LL, heaps[1] - smallest_heap) + max(0LL, heaps[2] - smallest_heap);
        cout << smallest_heap + extra / 3 << endl;
    }

    return 0;
}