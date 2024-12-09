#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<int> a(n);
        vector<long long> cumulativeSum(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cumulativeSum[i] = (i == 0) ? a[i] : cumulativeSum[i - 1] + a[i];
        }

        while (q--) {
            int sum;
            cin >> sum;

            int low = 0, high = n - 1;

            while (low <= high) {
                int mid = low + (high - low) / 2;
                int leftSum = (mid == 0) ? 0 : cumulativeSum[mid - 1];
                int rightSum = cumulativeSum[n - 1] - cumulativeSum[mid];

                if (a[mid] == sum || leftSum == sum || rightSum == sum) {
                    cout << "Yes" << endl;
                    break;
                } else if (leftSum < sum && rightSum < sum) {
                    cout << "No" << endl;
                    break;
                } else if (leftSum >= sum) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
    }

    return 0;
}