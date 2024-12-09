#include <iostream>
#include <vector>

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

        long long max_stones = 0;
        long long smallest_heap = min(heaps[n-1], min(heaps[n-2], heaps[n-3]));
        
        for(int i = n-4; i >= 0; i--) {
            max_stones += max(0, heaps[i] - smallest_heap);
        }

        long long result = smallest_heap + (max_stones / 3);
        cout << result << endl;
    }

    return 0;
}