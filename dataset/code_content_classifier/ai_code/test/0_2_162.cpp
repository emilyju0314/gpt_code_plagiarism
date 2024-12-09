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

        long long prev1 = heaps[n-1];
        long long prev2 = heaps[n-2];

        long long smallest = min(prev1, prev2);

        for (int i = n-3; i >= 0; i--) {
            long long d = min(heaps[i], (prev1-prev2)/3);
            heaps[i] -= 3*d;
            prev2 += 2*d;
            prev1 += d;
            smallest = min(smallest, heaps[i]);
        }

        cout << smallest << endl;
    }

    return 0;
}