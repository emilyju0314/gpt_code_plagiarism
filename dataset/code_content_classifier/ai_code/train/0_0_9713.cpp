#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long maxCost = 0;
    for (int l = 0; l < n; l++) {
        long long sum = 0;
        for (int r = l; r < n; r++) {
            sum += a[r];
            int length = r - l + 1;
            long long cost = sum - k * ceil((double)length / m);
            maxCost = max(maxCost, cost);
            if (sum < k * ceil((double)length / m)) {
                break; // no need to consider subarrays with lower sum
            }
        }
    }

    cout << maxCost << endl;

    return 0;
}