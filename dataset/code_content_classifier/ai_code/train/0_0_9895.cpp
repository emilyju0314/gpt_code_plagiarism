#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, d, m;
    cin >> n >> d >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<long long> prefixSum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefixSum[i + 1] = prefixSum[i] + a[i];
    }

    long long maxFunFactor = 0;

    for (int i = 0; i <= n; i++) {
        int remainingDays = n - i;

        if (remainingDays <= (i - 1) * (d + 1) + 1) {
            long long sum = prefixSum[i];

            int j = max(0, remainingDays - 1);
            sum += prefixSum[i + j];

            if (i + j < n) {
                sum += prefixSum[n] - prefixSum[i + j];
            }

            maxFunFactor = max(maxFunFactor, sum);
        }
    }

    cout << maxFunFactor << endl;

    return 0;
}