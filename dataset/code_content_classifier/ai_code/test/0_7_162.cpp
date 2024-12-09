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

        vector<int> heaps(n);
        for (int i = 0; i < n; i++) {
            cin >> heaps[i];
        }

        long long minHeap = heaps[n-1]; // smallest heap starts with the last heap
        long long carry = 0; // carry stones to move to previous heaps

        for (int i = n-2; i >= 0; i--) {
            carry = min(heaps[i], carry); // update carry to minimum of current heap size and carry
            minHeap = min(minHeap, (heaps[i] - carry) / 3); // update minHeap to minimum of current minHeap and current heap size after moving carry stones
            carry += min(heaps[i], minHeap); // increase carry with stones moved from the current heap
        }

        cout << minHeap << endl;
    }

    return 0;
}