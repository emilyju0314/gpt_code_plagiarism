#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> heaps(n);
        for(int i = 0; i < n; i++) {
            cin >> heaps[i];
        }

        long long d1 = 0, d2 = 0;
        long long min_heap = heaps[n-1];
        for(int i = n-1; i >= 2; i--) {
            if(heaps[i] >= 2 * (d1 + d2)) {
                d1 = min(1LL * (heaps[i] - (d1 + d2)) / 3, 1LL * heaps[i] / 3);
                min_heap = min(min_heap, 1LL * heaps[i] - 3 * d1);
            }
            d2 = 2 * d1;
        }

        cout << min_heap << endl;
    }

    return 0;
}