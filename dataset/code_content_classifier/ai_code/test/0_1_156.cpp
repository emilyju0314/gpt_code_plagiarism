#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        long long k;
        cin >> n >> k;

        vector<int> arr(n);
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }

        long long steps = 0;
        for (int i = 0; i < n; i++) {
            if (sum <= k) {
                break;
            }

            if (arr[i] > k) {
                steps += (arr[i] - k);
                arr[i] = k;
            }

            sum -= arr[i];
        }

        sort(arr.begin(), arr.end());

        for (int i = n-1; i >= 0; i--) {
            if (sum <= k) {
                break;
            }

            if (k - sum >= arr[i]) {
                steps++;
                sum += (k - sum - arr[i]);
            } else {
                steps += 2;
                sum += (2 * (k - sum) - arr[i]);
            }
        }

        cout << steps << "\n";
    }

    return 0;
}