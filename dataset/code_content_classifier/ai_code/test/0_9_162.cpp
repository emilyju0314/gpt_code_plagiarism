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

        long long min_heap = *min_element(heaps.begin(), heaps.end());
        long long max_possible = min_heap * 3;

        long long max_movable = 0;
        for (int i = 2; i < n; i++) {
            max_movable += heaps[i] / 3;
        }

        cout << min(min_heap, max_possible - max_movable) << endl;
    }

    return 0;
}