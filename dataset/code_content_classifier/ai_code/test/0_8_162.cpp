#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<long long> heaps(n);
        for(int i = 0; i < n; i++) {
            cin >> heaps[i];
        }

        long long sum = 0;
        long long min_heap_size = 1e18;
        for(int i = n-1; i >= 1; i--) {
            sum += heaps[i];
            min_heap_size = min(min_heap_size, sum - max(heaps[i-1], heaps[i-2]));
        }

        cout << min_heap_size << endl;
    }

    return 0;
}