#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        long double k = (long double) sum / n;
        
        int countPairs = 0;
        long long prefixSum = 0;

        for (int i = 0; i < n; i++) {
            prefixSum += a[i];
            if (prefixSum == k * (i + 1)) {
                countPairs += i;
            }
        }

        cout << countPairs << endl;
    }

    return 0;
}